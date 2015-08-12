#include "regedithelper.h"
#include <QSettings>
#include <QStringList>
#include <QDebug>
regeditHelper::regeditHelper(QObject *parent) : QObject(parent)
{
    path = "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\";
}

void regeditHelper::refreshListView()
{
    QSettings reg(path,QSettings::NativeFormat);
    QStringList groups = reg.childGroups();
    vector<pair<QString,bool>> vec;
    for(auto group : groups)
    {
        reg.beginGroup(group);
        auto Keys = reg.allKeys();
        bool found = false;
        // 先找 debuger ，如果没有，找是否有假的debuger
        for(auto k : Keys)
        {
            if(k == "debugger")
            {
                vec.push_back(make_pair(group,true));
                found = true;
                break;
            }
        }
        if(!found)
        {
            for(auto k : Keys)
                if(k == "dummy_debugger")
                {
                    vec.push_back(make_pair(group,false));
                    found = true;
                    break;
                }
        }
        reg.endGroup();
    }

    emit getetInfoFinished(vec);
}

void regeditHelper::removeRegItem(QString name)
{
    QSettings reg(path,QSettings::NativeFormat);
    reg.beginGroup(name);
    reg.remove("");
    reg.endGroup();

    refreshListView();

}

void regeditHelper::addRegItem(QString name)
{
    QSettings reg(path,QSettings::NativeFormat);
    reg.beginGroup(name);
    reg.setValue("debugger","vsjitdebugger");
    reg.endGroup();
    refreshListView();
}

void regeditHelper::enableRegItem(QString name)
{
    QSettings reg(path,QSettings::NativeFormat);
    reg.beginGroup(name);
    auto Keys = reg.childKeys();
    bool found = false;
    for(auto k : Keys)
    {
        if(k == "debugger")
        {
            qDebug() << "disable";
            reg.remove(k);
            reg.setValue("dummy_debugger","dummy_debugger");
            found = true;
        }
    }
    if(!found)
    {
        qDebug() << "enable";
        reg.setValue("debugger","vsjitdebugger.exe");
        reg.remove("dummy_debugger");
    }
    reg.endGroup();

    refreshListView();
}

