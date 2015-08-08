#include "customlistwidget.h"
#include <QDebug>
#include <QString>
#include <QLineEdit>
#include <QInputDialog>

CustomListWidget::CustomListWidget(QWidget *parent)
    :QListWidget(parent)
{
    init();
}

void CustomListWidget::init()
{
    popMenu = new QMenu(this);
    enable = new QAction("启用",this);
    remove = new QAction("删除",this);
    add = new QAction("添加",this);
    popMenu->addAction(add);
    popMenu->addAction(remove);
    popMenu->addAction(enable);

    connect(add,SIGNAL(triggered(bool)),this,SLOT(onAddBtnPress(bool)));
    connect(remove,SIGNAL(triggered(bool)),this,SLOT(onRemovePress(bool)));
    connect(enable,SIGNAL(triggered(bool)),this,SLOT(onEnablePress(bool)));
}



void CustomListWidget::contextMenuEvent(QContextMenuEvent *e)
{
    popMenu->clear();
    auto item = itemAt(mapFromGlobal(QCursor::pos()));
    if(item != NULL)
    {
        if(item->textColor() == QColor(255,0,0))
        {
            enable->setText("启用");
        }
        else
        {
            enable->setText("禁用");
        }
        popMenu->addAction(enable);
        popMenu->addAction(remove);
    }
    else
    {
        popMenu->addAction(add);
    }
    popMenu->exec(QCursor::pos());
}


void CustomListWidget::onRemovePress(bool)
{
    auto item = selectedItems()[0];
    if(item)
    {
        qDebug() << "remove : " + item->text();
        emit removeRegItem(item->text());
    }
}

void CustomListWidget::onAddBtnPress(bool)
{
    bool isOK = false;
    QString text = QInputDialog::getText(NULL,"input","",QLineEdit::Normal,"",&isOK);
    if(isOK)
    {
        emit addRegItem(text);
    }
}

void CustomListWidget::onEnablePress(bool)
{

    auto item = selectedItems()[0];
    if(item)
    {
        qDebug() <<"onEnablePress";
       emit enableRegItem(item->text());
    }
}

