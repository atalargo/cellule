#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGLWidget>
#include <QTime>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    row = ROW;

    ui->setupUi(this);
    ui->graphicsView->setViewport(new QGLWidget());
    ((QGLWidget)ui->graphicsView->viewport()).format().setDoubleBuffer(true);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(new QGraphicsScene(0,0,(row*CELL_SIZE + 40),(row*CELL_SIZE + 40)));
    QMatrix scaleMatrix;
    scaleMatrix.scale(1,1);
    ui->graphicsView->setMatrix(scaleMatrix);
    QRectF sceneRect = ui->graphicsView->scene()->sceneRect();
//    ui->graphicsView->fitInView(sceneRect, Qt::KeepAspectRatio);
    ui->graphicsView->ensureVisible(sceneRect,20,20);
    ybasepose = ((row*row)*CELL_SIZE + 20);

    connect(ui->stopButton, SIGNAL(clicked()), SLOT(stop()));
    connect(ui->startButton, SIGNAL(clicked()), SLOT(start()));

    connect(ui->action_Quitter, SIGNAL(triggered()),SLOT(close()));
    connect(ui->actionFullscreen, SIGNAL(triggered()), SLOT(fullscreen()));
    ui->actionFullscreen->setShortcut(QKeySequence(QKeySequence::FullScreen));
    escShortcut = new QShortcut(QKeySequence(QString("Esc")), this);

    ui->spinNbRow->setValue(row);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fullscreen()
{
    /*
    if (ui->graphicsView->isFullScreen())
        ui->graphicsView->setWindowState(ui->graphicsView->windowState() & ~Qt::WindowFullScreen);
    else*/
    if (isFullScreen())
    {
        ui->menuBar->setVisible(true);
        ui->frame->setVisible(true);
        ui->centralWidget->layout()->setContentsMargins(13,13,13,13);
        disconnect(escShortcut, SIGNAL(activated()), this, SLOT(fullscreen()));
    }
    else
    {
        ui->menuBar->setVisible(false);
        ui->frame->setVisible(false);
        ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
        connect(escShortcut, SIGNAL(activated()), SLOT(fullscreen()));
    }
    setWindowState(windowState() ^ Qt::WindowFullScreen);
}

void MainWindow::createBits()
{
    int c= row * row;
    bits.resize(c);
    qDebug() << QString("TRAND %1 %2 %3").arg(qrand()).arg(qrand()%2).arg(qrand()%2 == 1);
    qDebug() << QString("TRAND %1 %2 %3").arg(qrand()).arg(qrand()%2).arg(qrand()%2 == 1);
    qDebug() << QString("TRAND %1 %2 %3").arg(qrand()).arg(qrand()%2).arg(qrand()%2 == 1);
    qDebug() << QString("TRAND %1 %2 %3").arg(qrand()).arg(qrand()%2).arg(qrand()%2 == 1);
    qDebug() << QString("TRAND %1 %2 %3").arg(qrand()).arg(qrand()%2).arg(qrand()%2 == 1);
    qDebug() << QString("TRAND %1 %2 %3").arg(qrand()).arg(qrand()%2).arg(qrand()%2 == 1);
    qDebug() << QString("TRAND %1 %2 %3").arg(qrand()).arg(qrand()%2).arg(qrand()%2 == 1);

    for(int i =0 ; i < c ; i++)
        bits[i] = (qrand()%2 == 1);
}

void MainWindow::refreshBits()
{
    QBitArray calcBit(row*row,0);

    int rowmax = row-1;
    QTime t1;t1.start();
    int base;
    int nbLive;
    int jp1;int jm1;int ip1; int im1;

    for(int i = 1;i < row-1;i++)
    {
        for(int j = 1;j<row-1;j++)
        {
            base = calcPos(i,j);
            nbLive = 0;

            jp1 = j+1;
            jm1 = j-1;
            ip1 = i+1;
            im1 = i-1;

//            nbLive = bits.testBit(calcPos(im1,jm1)) +
//                    bits.testBit(calcPos(im1,j)) +
//                    bits.testBit(calcPos(im1,jp1)) +
//                    bits.testBit(calcPos(i,jm1)) +
//                    bits.testBit(calcPos(i,jp1)) +
//                    bits.testBit(calcPos(ip1,jm1)) +
//                    bits.testBit(calcPos(ip1,j)) +
//                    bits.testBit(calcPos(ip1,jp1));

//            calcBit.clearBit(base);
//            if (nbLive == 3 || (nbLive == 2 && bits.testBit(base)))
//                calcBit.setBit(base);

            if (j < rowmax)
            {
                if (bits.testBit(calcPos(i,jp1)))
                    nbLive++;
                if (i > 0 && bits.testBit(calcPos(im1, jp1)))
                    nbLive++;
                if (i < rowmax && bits.testBit(calcPos(ip1, jp1)))
                    nbLive++;
            }
            if (j > 0 )
            {
                if(bits.testBit(calcPos(i,jm1)))
                    nbLive++;
                if (i > 0 && bits.testBit(calcPos(im1, jm1)))
                    nbLive++;
                if (i < rowmax && bits.testBit(calcPos(ip1, jm1)))
                    nbLive++;
            }
            if (i < rowmax && bits.testBit(calcPos(ip1,j)))
                nbLive++;
            if (i > 0 && bits.testBit(calcPos(im1, j)))
                nbLive++;

            if(bits.testBit(base) == 1 && (nbLive == 2 || nbLive == 3))
                    calcBit.setBit(base);
            else if (bits.testBit(base) == 0 && nbLive == 3)
                calcBit.setBit(base);

        }
    }
    qDebug() << "Cycle for " << t1.elapsed() << " ms";
    bits = calcBit;
}

void MainWindow::start()
{
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(false);
    ui->spinNbRow->setEnabled(false);

    row = ui->spinNbRow->value();

    ui->graphicsView->scene()->clear();/*
    ui->graphicsView->scene()->setSceneRect(0, 0, (row*CELL_SIZE + 40), (row*CELL_SIZE + 40));
    ui->graphicsView->centerOn((row*CELL_SIZE + 40)/2, (row*CELL_SIZE + 40)/2);*/

    ui->graphicsView->scene()->setSceneRect(0, 0, (row + 40), (row + 40));
    ui->graphicsView->centerOn((row + 40)/2, (row + 40)/2);
    ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect());
    QMatrix m; m.scale(ui->graphicsView->width()/ui->graphicsView->sceneRect().width(), ui->graphicsView->height()/ui->graphicsView->scene()->height());


    ui->graphicsView->setMatrix(m);

    createBits();

    cycleCount = 0;
//    if (timer)
//        timer->stop();
//    else
//    {
        timer = new QTimer(this);
        timer->setSingleShot(true);
        connect(timer, SIGNAL(timeout()), this, SLOT(cycle()));
//    }
    timer->start(10);
}

void MainWindow::stop()
{
    timer->stop();
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    ui->spinNbRow->setEnabled(true);
}

void MainWindow::cycle()
{
QTime t;
t.start();
    refreshBits();

    qDebug() << "Cycle " << t.elapsed() << " ms";
    QGraphicsScene *scene = ui->graphicsView->scene();
    if (!scene)
    {
        qDebug() << "PAS SCENE";
    }

    t.start();
    scene->clear();

    QBrush brush;
    QPen pen(Qt::black, 1, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

    int x;
    int y;
    QPixmap img(scene->sceneRect().toRect().size());

    QPainter p;
    p.begin(&img);
    p.setRenderHint(QPainter::Antialiasing, false);
//    p.setPen(pen);
    p.setBackground(Qt::white);
    scene->setBackgroundBrush(Qt::white);
    p.fillRect(scene->sceneRect(), Qt::white);
brush = Qt::red;
p.setPen(Qt::red);
    for(int i = 0 ; i < (row*row) ; i++)
    {
//        x = (i%row);
//        y = (int)(i/row);

//        if (!bits.testBit(i))
//            brush = Qt::white;
//        else
        if (bits.testBit(i))
        {
//            brush = Qt::red;
//            p.setBrush(brush);
//            p.drawRect(QRect(20+(x*CELL_SIZE), (y*CELL_SIZE)+20, CELL_SIZE, CELL_SIZE));
//            p.setPen(Qt::red);
            p.drawPoint(20+(i%row), ((int)(i/row))+20);
        }

//        qDebug() << QString("i %3 x: %1 y: %2 xv: %4 yv: %5").arg(x).arg(y).arg(i).arg(x*CELL_SIZE).arg(y*CELL_SIZE);
//        scene->addRect(
//                    20+(x*CELL_SIZE), (y*CELL_SIZE)+20,
//                    CELL_SIZE, CELL_SIZE,
//                    pen, brush
//        );
    }
    p.end();
    scene->addPixmap(img);

    qDebug() << "Display " << t.elapsed() << " ms";
    cycleCount++;
    ui->cycleLabel->setText(QString("Cycle: %1").arg(cycleCount));
    timer->start(2);
}
