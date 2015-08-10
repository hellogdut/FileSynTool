#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <vector>
using namespace std;
class regeditHelper;
class QFileSystemWatcher;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void init();

public slots:
/* tab1 */

    // UI
    void on_manualSyn_clicked();// 点击手动同步 btn
    void on_autoSyn_stateChanged(int arg1);// 选中自动同步 checkBox
    void on_pushButton_2_clicked(); // 点击查看按钮
    void on_pushButton_3_clicked(); // 点击查看按钮
    void onWatchEditChanged();      // 监控目录 Edit 发生改变
    void onCompareEditChanged();    // 同步目录 Edit 发生改变
    void enableInput(bool b);

    // Logic
    void onDirectoryChanged(const QString & path);  // 文件夹发生改变
    void onFileChanged(const QString & path);       // 文件发生变化
    void timeOut();
    void openPaths(QStringList& list);              // 批量打开文件|文件夹，去重
    void synTwoFiles(QString fileA,QString fileB);
public slots:
/* tab2 */
    void onGetRegInfo(vector<pair<QString,bool>>);

private slots:
    // tab1



    // tab2


    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
private:

    QFileSystemWatcher* watcher;
    regeditHelper* pReg;
    QStringList watchList;
    QStringList compareList;
    void setTimer();
    void lastSynTimeNotify();
    void lastSynFileNotify(const QString& fileName);
    void startCopyDirectory(QString& path);
    void startCopyFile(QString& path);

private:
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
private:
    QVector<QString> fileQueue;
    QVector<QString> directoryQueue;
    QTimer* timer;          // 设置几秒后开始同步

    bool synAdd = true;     // 同步文件修改
    bool synModify = true;  // 同步文件修改
    bool synDel = false;    // 同步文件删除
    bool autoSyn = false;   // 自动同步
    bool click = false;     // 记录是否点击 “手动同步”

};

#endif // MAINWINDOW_H
