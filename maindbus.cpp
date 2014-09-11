#include "maindbus.h"
#include <QtDBus/QtDBus>
#include <QtCore/QDebug>
#include "dbusmessagebus.h"


MainDBus::MainDBus(QObject *parent) :
    QObject(parent), sessionbus_(QDBusConnection::sessionBus())
{
    // initialize standard dbus-interface
    dbus_iface_ = new QDBusInterface("org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus", sessionbus_);

    // get all available Message Bus Names
    QStringList vAllNames = dbus_iface_->call("ListNames").arguments().at(0).toStringList();

    QStringList slRequestedNames;   // temporary store
    for (int i = 0; i < vAllNames.size(); i++) {
        if (vAllNames.at(i).startsWith(":")){
            // load list of unique bus names
            listMessageBus_.insert(vAllNames.at(i), new DBusMessageBus(vAllNames.at(i), parent));

        }
        else slRequestedNames << vAllNames.at(i);

    }

    // match requested bus names to unique names
    for (int i = 0; i < slRequestedNames.size(); i++) {
        QString uniqueName = dbus_iface_->call("GetNameOwner", slRequestedNames.at(i)).arguments().at(0).toString();
        if (listMessageBus_.contains(uniqueName))
            qDebug() << uniqueName << " has name: " << slRequestedNames.at(i);
        else
            qDebug() << "Named Bus '" << slRequestedNames.at(i) << "' has no uid??";
    }

}


MainDBus::~MainDBus()
{
    delete dbus_iface_;
}
