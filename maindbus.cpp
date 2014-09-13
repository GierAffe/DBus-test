#include "maindbus.h"
#include <QtDBus/QtDBus>
#include <QtCore/QDebug>


MainDBus::MainDBus(QObject *parent) : QObject(parent),
    sessionbus_(QDBusConnection::sessionBus())
{
    // initialize standard dbus-interface
    dbus_iface_ = new QDBusInterface("org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus", sessionbus_);

    // request message bus name

}

MainDBus::~MainDBus()
{
    delete dbus_iface_;
}


QStringList MainDBus::getUniqueNames()
{
    QStringList slistAllNames = getAllBusNames();
    QStringList slistUniqueNames;
    for (int i = 0; i < slistAllNames.size(); i++) {
        if (slistAllNames.at(i).startsWith(":")) {
            slistUniqueNames.append(slistAllNames.at(i));
        }
    }
    return slistUniqueNames;
}


QStringList MainDBus::getBusNames()
{
    QStringList slistAllNames = getAllBusNames();
    QStringList slistBusNames;
    for (int i = 0; i < slistAllNames.size(); i++) {
        if (! slistAllNames.at(i).startsWith(":")) {
            slistBusNames.append(slistAllNames.at(i));
        }
    }
    return slistBusNames;
}


QStringList MainDBus::getAllBusNames()
{
    return dbus_iface_->call("ListNames").arguments().at(0).toStringList();
}


QString MainDBus::matchBusNameToUniqueName(const QString & busName)
{
    return dbus_iface_->call("GetNameOwner", busName).arguments().at(0).toString();
}
