#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QMessageBox>
#include <QMouseEvent>
#include <QStyleFactory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    this->setStyle(QStyleFactory::create("Macintosh"));
    this->setWindowFlags(Qt::Dialog);
    this->setWindowTitle("PhotoGlance");
   // this->setWindowFlags(Qt::SubWindow);

    m_pCutAction = new QAction(tr("Cut"),this);
    m_pCopyAction = new QAction(tr("Copy"),this);
    m_pPasteAction = new QAction(tr("Paste"),this);
    m_pDeleteAction = new QAction(tr("Delete"),this);
    m_pCutAction->setIcon(QIcon(":/new/prefix/Cut.ico"));
    m_pCutAction->setShortcut(QKeySequence::Cut);
    m_pCutAction->setStatusTip(tr("cut the cotents"));
    m_EditListAct.append(m_pCutAction);

}

void MainWindow::CreateMenu()
{
    //FileMenu 初始化
    m_FileMenu = menuBar()->addMenu(tr("&File"));
    m_pNewAction = new QAction(tr("&New"),this);
    m_pNewAction->setIcon(QIcon(":/new/prefix/New.ico"));
    m_pNewAction->setShortcut(QKeySequence::New);
    m_pNewAction->setStatusTip(tr("create new file"));

    m_pOpenAction = new QAction(tr("&Open"),this);
    m_pOpenAction->setIcon(QIcon(":/new/prefix/Open.ico"));
    m_pOpenAction->setShortcut(QKeySequence::Open);
    m_pOpenAction->setStatusTip(tr("open a file"));

    m_pSaveAction = new QAction(tr("&Save"),this);
    m_pSaveAction->setIcon(QIcon(":/new/prefix/Save.ico"));
    m_pSaveAction->setShortcut(QKeySequence::Save);
    m_pSaveAction->setStatusTip(tr("save a file"));

    m_FileMenu->addAction(m_pNewAction);
    m_FileMenu->addAction(m_pOpenAction);
    m_FileMenu->addAction(m_pSaveAction);

    //Edit Tools Menu 初始化
    m_EditMenu = menuBar()->addMenu(tr("&Edit"));
    m_EditMenu->addActions(m_EditListAct);
    m_ToolsMenu = menuBar()->addMenu(tr("&Tools"));

}

void MainWindow::NewFile()
{
    QMessageBox boxNew;
    boxNew.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    boxNew.exec();
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        oPresPoint = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button() == Qt::RightButton)
    {
        close();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        move(event->globalPos()-oPresPoint);
        event->accept();
    }
}
