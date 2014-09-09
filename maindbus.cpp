#include "maindbus.h"
#include <QtDBus/QtDBus>
#include <QtCore/QDebug>


MainDBus::MainDBus(QObject *parent) :
    QObject(parent), sessionbus_(QDBusConnection::sessionBus())
{
    // initialize standard dbus-interface
    dbus_iface_ = new QDBusInterface("org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus", sessionbus_);

    // get all available Message Bus Names
    QStringList vAllNames = dbus_iface_->call("ListNames").arguments().at(0).toStringList();

    QStringList slRequestedNames;
    for (int i = 0; i < vAllNames.size(); i++) {
        if (vAllNames.at(i).startsWith(":")){

            // load list of unique bus names


        }
        else
            slRequestedNames << vAllNames.at(i);

    }

}

MainDBus::~MainDBus()
{
    delete dbus_iface_;
}
