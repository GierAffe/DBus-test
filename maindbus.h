#ifndef MAINDBUS_H
#define MAINDBUS_H

#include <QObject>
#include <QtDBus/QtDBus>


class MainDBus : public QObject
{
    Q_OBJECT

private:
    QDBusConnection sessionbus_;
    QDBusInterface * dbus_iface_;

public:
    explicit MainDBus(QObject *parent = 0);
    ~MainDBus();

    QStringList getAllBusNames();
    QStringList getBusNames();
    QStringList getUniqueNames();
    QString matchBusNameToUniqueName(const QString &busName);
    
};

#endif // MAINDBUS_H
