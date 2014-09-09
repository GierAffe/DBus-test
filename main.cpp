#include <QApplication>
#include <QtCore/QDebug>
#include <QtDBus/QtDBus>
#include "mainwindow.h"
#include "maindbus.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Check if DBus is available
    if (!QDBusConnection::sessionBus().isConnected()) {
        fprintf(stderr, "Cannot connect to the D-Bus session bus.\nTo start it, run:\n\teval `dbus-launch --auto-syntax`\n");
        return 1;
    }

    MainWindow w;
    w.show();


    return a.exec();
}
