#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maindbus.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainDBusInstance(new MainDBus(this))
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
