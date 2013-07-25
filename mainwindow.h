#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QMouseEvent;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public:
    void CreateMenu();
    QMenu* m_FileMenu;
    QMenu* m_EditMenu;
    QMenu* m_ToolsMenu;
    QMenu* m_OptionsMenu;
    QAction* m_pNewAction;
    QAction* m_pOpenAction;
    QAction* m_pSaveAction;
    QAction* m_pSaveAsAction;

    QAction* m_pCutAction;
    QAction* m_pCopyAction;
    QAction* m_pPasteAction;
    QAction* m_pDeleteAction;
    QList<QAction*> m_EditListAct;
public:
    void Init();

private slots:
    void NewFile();

private:
    Ui::MainWindow *ui;

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    QPoint oPresPoint;
};

#endif // MAINWINDOW_H
