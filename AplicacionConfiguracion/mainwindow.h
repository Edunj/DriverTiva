#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_CheckQEI0_clicked();

    void on_CheckQEI1_clicked();

    void on_CheckPWM_clicked();

    void on_CheckADC_clicked();

    void on_GenerarConfig_clicked();

    void on_CheckLCD_clicked();



    void on_CheckTOF_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
