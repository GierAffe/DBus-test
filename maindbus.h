#ifndef MAINDBUS_H
#define MAINDBUS_H

class DBusMessageBus;

#include <QObject>
#include <QtDBus/QtDBus>


class MainDBus : public QObject
{
    Q_OBJECT

private:
    QDBusConnection sessionbus_;
    QDBusInterface * dbus_iface_;

    QMap<QString, DBusMessageBus*> listMessageBus_;

public:
    explicit MainDBus(QObject *parent = 0);
    ~MainDBus();
    
};

#endif // MAINDBUS_H
