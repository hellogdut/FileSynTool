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
    connect(ui->autoSyn,SIGNAL(stateChanged(int)),this,SLOT(onAutoSynChanged(int)));
    connect(ui->manualSyn,SIGNAL(clicked()),this,SLOT(onMannualSynClicked()));
}

void MainWindow::onWatchEditChanged()
{

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
        watcher->removePaths(watchList);
        watchList.swap(validList);
        watcher->addPaths(watchList);
    }
}
void MainWindow::onCompareEditChanged()
{
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
             compareFolder = line;
         }
    }
    if(valid)
        this->statusBar()->clearMessage();
    else
    {
        compareFolder.clear();
    }
}

void MainWindow::onAutoSynChanged(int state)
{
    ui->watchEdit->setEnabled(!ui->watchEdit->isEnabled());
    ui->compareEdit->setEnabled(!ui->compareEdit->isEnabled());
}

void MainWindow::onMannualSynClicked()
{
    qDebug() << "onMannualSynClicked";
    for(auto path : watchList)
    {
        click = true;
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

}

void MainWindow::setTimer()
{
    if(timer == NULL)
    {
        ui->statusBar->showMessage("有文件改变，十秒后开始同步...");
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(timeOut()));
        timer->setInterval(10000);
        timer->start();
    }
    else
    {
        ui->statusBar->showMessage("又有文件改变啦,等文件改变完一起同步...");
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

    if(!ui->autoSyn->checkState())
    {
        if(!click)
            return;
        click = false;
    }

    if(compareFolder.isEmpty())
        return;
    QDir dir(path);
    //QString newName = compareFolder + dir.dirName();    // 获得文件名，构造路径
    QString newName = compareFolder;    // 不带文件夹名
    qDebug() << "newName:" + newName;
    copyDirectoryFiles(path,newName,true);
    lastSynTimeNotify();
}

void MainWindow::startCopyFile(QString &path)
{
    // 流逝时间计算
    static QElapsedTimer et;
    et.start();

    lastSynFileNotify("正在同步: " + path);
    if(!ui->autoSyn->checkState())
    {
        if(!click)
            return;
        click = false;
    }

    if(compareFolder.isEmpty())
        return;
    QDir dir(path);
    QString newName = compareFolder + dir.dirName();    // 获得文件名，构造路径
    qDebug() << "newPath: " + newName;
    QFileInfo file(newName);
    if(file.exists())
    {
        if(!QFile::remove(newName))
            qDebug() << "can't delete : " + newName;
        else
            qDebug() << "delete : " + newName;
    }
    if(!QFile::copy(path, newName))
        qDebug() << "can't copy : " + path;


    if(et.elapsed() > 300)
    {
        QCoreApplication::processEvents();
        et.restart();
    }
    lastSynTimeNotify();
}

bool MainWindow::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    // 流逝时间计算
    static QElapsedTimer et;
    et.start();

    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /** 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
        {
            qDebug() << "mkdir " + targetDir.absolutePath() + " failed";
        }
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();

    foreach(QFileInfo fileInfo, fileInfoList)
    {
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir())
        {   /**< 当为目录时，递归的进行 copy */
            copyDirectoryFiles(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName()),coverFileIfExist);
        }
        else
        {   /**< 当允许覆盖操作时，将旧文件进行删除操作 */
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName()))
            {
                targetDir.remove(fileInfo.fileName());
            }
            /// 进行文件 copy
            lastSynFileNotify("正在同步:" + fileInfo.filePath());
            QFile::copy(fileInfo.filePath(),targetDir.filePath(fileInfo.fileName()));

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

void MainWindow::on_pushButton_2_clicked()
{
    std::set<QString> pathList;

    for(auto path : watchList)
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

void MainWindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("file:///" + compareFolder));
}
