#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainDBus;

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    MainDBus *mainDBusInstance;
};

#endif // MAINWINDOW_H
