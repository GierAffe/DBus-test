#include "dbusmessagebus.h"
#include "ui_mainwindow.h"

DBusMessageBus::DBusMessageBus(const QString &uniqueName, QObject *parent) :
    QObject(parent), uniqueName_(uniqueName)
{



}
