#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileSystemWatcher>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QDateTime>
#include <QElapsedTimer>
#include <QTimer>
#include <QDesktopServices>
#include <set>
#include <QListWidget>
#include <QListWidgetItem>
#include <regedithelper.h>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    watcher = new QFileSystemWatcher(this);
    timer = NULL;
    connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(onFileChanged(QString)));
    connect(watcher,SIGNAL(directoryChanged(QString)),this,SLOT(onDirectoryChanged(QString)));
    connect(ui->watchEdit,SIGNAL(textChanged()),this,SLOT(onWatchEditChanged()));
    connect(ui->compareEdit,SIGNAL(textChanged()),this,SLOT(onCompareEditChanged()));
    connect(ui->exceptEdit,SIGNAL(textChanged()),this,SLOT(onExceptEditChanged()));
    // 注册表
    pReg = new regeditHelper;
    connect(pReg,SIGNAL(getetInfoFinished(vector<pair<QString,bool>>)),this,SLOT(onGetRegInfo(vector<pair<QString,bool>>)));
    connect(ui->listWidget,SIGNAL(removeRegItem(QString)),pReg,SLOT(removeRegItem(QString)));
    connect(ui->listWidget,SIGNAL(enableRegItem(QString)),pReg,SLOT(enableRegItem(QString)));
    connect(ui->listWidget,SIGNAL(addRegItem(QString)),pReg,SLOT(addRegItem(QString)));
    pReg->refreshListView();
}

void MainWindow::onWatchEditChanged()
{
    watchList.clear();
    QTextEdit* watchEdit = ui->watchEdit;
    QStringList lines = watchEdit->toPlainText().split("\n");
    bool valid = true;
    QStringList validList;
    QString str;
    for(auto line:lines)
    {
         line = line.trimmed();
         QFileInfo check(line);
         if(check.isFile() || check.isDir())
             validList.push_back(line);
         else
         {
             valid = false;
             this->statusBar()->showMessage("监视路径错误：" + line);
         }
    }
    if(valid)
    {
        this->statusBar()->clearMessage();
        watchList.swap(validList);
    }
    updateBtn();
}
void MainWindow::onCompareEditChanged()
{
    compareList.clear();
    QStringList lines = ui->compareEdit->toPlainText().split("\n");
    bool valid = true;
    for(auto line:lines)
    {
         line = line.trimmed();
         if(line.isEmpty())
             continue;
         QFileInfo check(line);
         if(!check.isDir())
         {
             valid = false;
             this->statusBar()->showMessage("对比目录错误：" + line);
         }
         else
         {
             compareList.push_back(line);
         }
    }
    if(valid)
        this->statusBar()->clearMessage();
    else
    {
        compareList.clear();
    }
    updateBtn();
}

void MainWindow::onExceptEditChanged()
{
    exceptList.clear();
    QTextEdit* exceptEdit = ui->exceptEdit;
    QStringList lines = exceptEdit->toPlainText().split("\n");
    bool valid = true;
    QStringList validList;
    QString str;
    for(auto line:lines)
    {
         line = line.trimmed();
         QFileInfo check(line);
         if(check.isFile() || check.isDir())
             validList.push_back(line);
         else
         {
             valid = false;
             this->statusBar()->showMessage("排除路径出错" + line);
         }
    }
    if(valid)
    {
        this->statusBar()->clearMessage();
        exceptList.swap(validList);
    }
}

void MainWindow::enableInput(bool b)
{
    ui->watchEdit->setEnabled(b);
    ui->exceptEdit->setEnabled(b);
    ui->compareEdit->setEnabled(b);
    ui->groupBox->setEnabled(b);
}

void MainWindow::updateBtn()
{
    bool enable = true;
    if(watchList.size() == 0 || compareList.size() == 0)
        enable = false;
    ui->autoSyn->setEnabled(enable);
    ui->manualSyn->setEnabled(enable);
}




void MainWindow::on_manualSyn_clicked()
{
    // 点击手动同步
    qDebug() << "onMannualSynClicked";
    click = true;
    if(!watchList.empty())
        enableInput(false);
    for(auto path : watchList)
    {
        QFileInfo check(path);
        if(check.isFile())
            onFileChanged(path);
        else if(check.isDir())
            onDirectoryChanged(path);
    }
}


void MainWindow::onDirectoryChanged(const QString &path)
{
    qDebug() << "DirectoryChanged :" + path;
    directoryQueue.push_back(path);
    setTimer();

}

void MainWindow::onFileChanged(const QString &path)
{
    qDebug() << "fileChanged :" + path;
    fileQueue.push_back(path);
    setTimer();

}

void MainWindow::timeOut()
{
    ui->statusBar->showMessage("开始同步...");
    timer->stop();
    disconnect(timer,SIGNAL(timeout()),this,SLOT(timeOut()));
    timer = NULL;
    for(auto file : fileQueue)
        startCopyFile(file);
    for(auto directory : directoryQueue)
        startCopyDirectory(directory);
    if(click == true)
    {
        if(!autoSyn)
            enableInput(true);
        click = false;
    }
}

void MainWindow::openPaths(QStringList &list)
{
    std::set<QString> pathList;

    for(auto path : list)
    {
        QFileInfo file(path);
        if(file.isDir())
            pathList.insert(path);
        else
        {
            pathList.insert(file.absolutePath());
        }
    }
    for(auto path:pathList)
        QDesktopServices::openUrl(QUrl("file:///" + path));
}

void MainWindow::synTwoFiles(QString fileA, QString fileB)
{
    if(isPathExcept(fileA))
        return;
    QFileInfo aFile(fileA);
    QFileInfo bFile(fileB);
//    qDebug() << "fileA:" + fileA;
//    qDebug() << "fileB:" + fileB;
    // 同步增加或修改
    if(aFile.exists())
    {
        // 同步修改
        if(bFile.exists() && synModify && aFile.lastModified() != bFile.lastModified())
        {
            if(!QFile::remove(fileB))
                qDebug() << "can't delete : " + fileB;
            if(!QFile::copy(fileA, fileB))
            {
                qDebug() << "can't copy : " + fileA;
            }
            else
            {
                lastSynFileNotify("正在修改: " + fileB);
                qDebug() << "copy : " + fileA;
            }
        }
        else if(!bFile.exists() && synAdd)
        {
            // 同步增加
            if(!QFile::copy(fileA, fileB))
            {
                qDebug() << "can't copy : " + fileA;
            }
            else
            {
                lastSynFileNotify("正在增加: " + fileB);
                qDebug() << "copy : " + fileA;
            }
        }

    }
    // 同步删除
    else
    {
        if(bFile.exists() && synDel)
        {
            if(!QFile::remove(fileB))
                qDebug() << "can't delete : " + fileB;
            else
            {
                lastSynFileNotify("正在删除: " + fileB);
                qDebug() << "del :" + fileB;
            }
        }
    }
}

void MainWindow::startWatch()
{
    watcher->addPaths(watchList);
}



void MainWindow::stopWatch()
{
    watcher->removePaths(watchList);
}


void MainWindow::setTimer()
{
    if(timer == NULL)
    {
        ui->statusBar->showMessage("有文件改变，准备同步...");
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(timeOut()));
        timer->setInterval(2000);
        timer->start();
    }
    else
    {
        lastSynFileNotify("又有文件改变啦,等文件改变完一起同步...");
        timer->start();
    }
}

void MainWindow::lastSynTimeNotify()
{
    QDateTime time = QDateTime::currentDateTime();// 获取系统现在的时间
    QString str = time.toString("同步完成，最近一次同步时间为 ：hh:mm:ss"); // 设置显示格式
    ui->statusBar->showMessage(str);
}

void MainWindow::lastSynFileNotify(const QString &fileName)
{
    ui->statusBar->showMessage(fileName);
}

void MainWindow::startCopyDirectory(QString &path)
{
    //qDebug() << "startCopyDirectory() :" + path;
    if(!autoSyn && !click)
        return;

    QDir dir(path);
    for(auto newPath : compareList)
    {
        // 不带文件夹名
        //qDebug() << "newPath" + newPath;
        copyDirectoryFiles(path,newPath,true);
        lastSynTimeNotify();
    }
}

void MainWindow::startCopyFile(QString &path)
{
    if(isPathExcept(path))
        return;
    // 流逝时间计算
    static QElapsedTimer et;
    et.start();
    lastSynFileNotify("正在同步: " + path);

    if(!autoSyn && !click)
        return;

    for(auto compareFolder : compareList)
    {
        QFileInfo file(path);
        QDir target(compareFolder);
        QString newName = target.filePath(file.fileName());    // 获得文件名，构造路径
        qDebug() << "newPath: " + newName;
        // 同步两个文件
        synTwoFiles(path,newName);

        if(et.elapsed() > 300)
        {
            QCoreApplication::processEvents();
            et.restart();
        }
        lastSynTimeNotify();
    }


}

bool MainWindow::isPathExcept(const QString &path)
{
    return exceptList.contains(path);
}

bool MainWindow::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    if(isPathExcept(fromDir))
        return true;
    // 流逝时间计算
    static QElapsedTimer et;
    et.start();

    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /** 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.path()))
        {
            qDebug() << "mkdir " + targetDir.filePath(sourceDir.dirName()) + " failed";
        }
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();

    foreach(QFileInfo fileInfo, fileInfoList)
    {
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir())
        {   /**< 当为目录时，递归的进行 copy */
            qDebug() << fileInfo.filePath() << "-> " << targetDir.filePath(fileInfo.fileName());
            copyDirectoryFiles(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName()),coverFileIfExist);
        }
        else
        {
            // 同步文件
            synTwoFiles(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName()));
        }
        if(et.elapsed() > 300)
        {
            QApplication::processEvents();
            et.restart();
            qDebug() << "回到UI";
        }
    }
    return true;
}



void MainWindow::onGetRegInfo(vector<pair<QString, bool>> vec)
{
    ui->listWidget->clear();
    for(auto p : vec)
    {
        QListWidgetItem* item = new QListWidgetItem(p.first);
        auto color = p.second ? QColor(0,255,0) : QColor(255,0,0);
        //item->setTextColor(color);
        item->setBackgroundColor(color);
        ui->listWidget->addItem(item);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    // 打开监视目录
    openPaths(watchList);
}

void MainWindow::on_pushButton_3_clicked()
{
    pReg->refreshListView();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    // 文件增加
    synAdd = (arg1 == 0) ? false : true;
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    // 文件修改
    synModify = (arg1 == 0) ? false : true;
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    // 文件删除
    synDel = (arg1 == 0) ? false : true;
}

void MainWindow::on_pushButton_clicked()
{
    // 打开对比目录
    openPaths(compareList);
}

void MainWindow::on_autoSyn_stateChanged(int arg1)
{
    // 选中自动同步
    autoSyn = (arg1 == 0) ? false : true;
    enableInput(!autoSyn);
    // 停止监听
    if(arg1 == 0)
    {
        stopWatch();
    }
    else
    {
        startWatch();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    openPaths(compareList);
}
