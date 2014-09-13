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

private slots:
    void on_cbFilterUniqueBusNames_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    MainDBus *mainDBusInstance;

    void buildMenuTree();
    void buildAppInfo();

    void showAllTreeItems();
    void hideSoulUniqueTreeItems();
};

#endif // MAINWINDOW_H
