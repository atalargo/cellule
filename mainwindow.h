#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBitArray>
#include <QShortcut>

#define ROW         256
#define MAX_CELL    ROW*ROW
#define CELL_SIZE   4

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void start();
    void stop();

protected:
    QBitArray bits;
    void refreshBits();
    void createBits();
    uint cycleCount;

    QTimer *timer;
    int ybasepose;

    int calcPos(int x, int y)
    {
        return (x*row)+y;
    }

    QShortcut *escShortcut;

    int row;

protected slots:
    void cycle();

    void fullscreen();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
