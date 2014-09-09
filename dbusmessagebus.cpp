#include "dbusmessagebus.h"

DBusMessageBus::DBusMessageBus(const QString &uniqueName, QObject *parent) :
    QObject(parent), uniqueName_(uniqueName)
{



}
