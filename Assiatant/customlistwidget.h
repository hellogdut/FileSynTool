#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H
#include <QListWidget>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QObject>
class CustomListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit CustomListWidget(QWidget *parent = 0);
    void contextMenuEvent(QContextMenuEvent *e);
    void init();
signals:
    void removeRegItem(QString);
    void addRegItem(QString);
    void enableRegItem(QString);
public slots:
    void onAddBtnPress(bool);
    void onRemovePress(bool);
    void onEnablePress(bool);
private:
    QMenu* popMenu;
    QAction* add;
    QAction* remove;
    QAction* enable;
    QAction* rename;

};

#endif // CUSTOMLISTWIDGET_H
