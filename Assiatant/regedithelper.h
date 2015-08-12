#ifndef REGEDITHELPER_H
#define REGEDITHELPER_H

#include <QObject>
#include <vector>
using namespace std;
class regeditHelper : public QObject
{
    Q_OBJECT
public:
    explicit regeditHelper(QObject *parent = 0);
signals:
    void getetInfoFinished(vector<pair<QString,bool>> list);
    void refresh();
public slots:
    void refreshListView();
    void removeRegItem(QString name);
    void addRegItem(QString name);
    void enableRegItem(QString name);
private:
    QString path;
signals:

public slots:
};

#endif // REGEDITHELPER_H
