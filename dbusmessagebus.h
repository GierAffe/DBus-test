#ifndef DBUSMESSAGEBUS_H
#define DBUSMESSAGEBUS_H

#include <QObject>
#include <QtDBus/QtDBus>

class DBusMessageBus : public QObject
{
    Q_OBJECT

private:
    const QString uniqueName_;

public:
    explicit DBusMessageBus(const QString &uniqueName, QObject *parent = 0);
    
    
};

#endif // DBUSMESSAGEBUS_H
