#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maindbus.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainDBusInstance(new MainDBus(this))
{
    ui->setupUi(this);      // moc stuff..

    // my initialisation
    buildMenuTree();
    buildAppInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::buildAppInfo()
{
    // do stuff
}


void MainWindow::buildMenuTree()
{
    // start with unique names
    QStringList slistUNames = mainDBusInstance->getUniqueNames();
    for (int i = 0; i < slistUNames.size(); i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->messageBusNamesTree, QStringList(slistUNames.at(i)));
        item->setIcon(0, QIcon::fromTheme("modem"));

    }

    // match corresponding named bus
    QStringList slistBusNames = mainDBusInstance->getBusNames();
    for (int i = 0; i < slistBusNames.size(); i++)
    {
        QString sUniqueName = mainDBusInstance->matchBusNameToUniqueName(slistBusNames.at(i));
        QList<QTreeWidgetItem *> treeItem = ui->messageBusNamesTree->findItems(sUniqueName, Qt::MatchExactly);
        if (slistBusNames.at(i) == QString("org.freedesktop.DBus")) {

        }
        else {
            // add named bus as a child of unique name item
            QTreeWidgetItem *newItem = new QTreeWidgetItem(treeItem.at(0), QStringList(slistBusNames.at(i)));
            newItem->setIcon(0, QIcon::fromTheme("user-available"));
        }
    }

    // expand all items & sort treeview
    ui->messageBusNamesTree->expandAll();
    ui->messageBusNamesTree->sortItems(0, Qt::AscendingOrder);
}

void MainWindow::on_cbFilterUniqueBusNames_stateChanged(int arg1)
{
    if (arg1 == 0)
        showAllTreeItems();
    else
        hideSoulUniqueTreeItems();
}

void MainWindow::showAllTreeItems()
{
    QTreeWidgetItemIterator it(ui->messageBusNamesTree);
    while (*it) {
        (*it)->setHidden(false);
        ++it;
    }
}

void MainWindow::hideSoulUniqueTreeItems()
{
    QTreeWidgetItemIterator it(ui->messageBusNamesTree, QTreeWidgetItemIterator::NoChildren);
    while (*it) {
        if ((*it)->text(0).startsWith(":"))
            (*it)->setHidden(true);
        ++it;
    }
}
