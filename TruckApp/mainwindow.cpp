#include "mainwindow.h"
#include "registrationdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Создание меню
    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    fileMenu = new QMenu(tr("&Меню"), this);
    menuBar->addMenu(fileMenu);

    inputMenu = new QMenu(tr("&Ручной ввод"), this);
    databaseMenu = new QMenu(tr("&База данных"), this);
    registerMenu = new QMenu(tr("&Регистрация"), this);

    fileMenu->addMenu(inputMenu);
    fileMenu->addMenu(databaseMenu);
    fileMenu->addMenu(registerMenu);

    inputAction = new QAction(tr("&Ввод"), this);
    databaseAction = new QAction(tr("&База"), this);
    registerAction = new QAction(tr("&Регистрация"), this);

    inputMenu->addAction(inputAction);
    databaseMenu->addAction(databaseAction);
    registerMenu->addAction(registerAction);

    connect(inputAction, &QAction::triggered, this, &MainWindow::openInputDialog);
    connect(databaseAction, &QAction::triggered, this, &MainWindow::openDatabaseDialog);
    connect(registerAction, &QAction::triggered, this, &MainWindow::openRegisterDialog); // Подключили слот для регистрации
}

MainWindow::~MainWindow()
{
    // Освобождение памяти и другие необходимые действия при уничтожении объекта MainWindow
}

void MainWindow::openInputDialog()
{
    InputDialog inputDialog(this);
    inputDialog.exec();
}

void MainWindow::openDatabaseDialog()
{
    DatabaseDialog databaseDialog(this);
    databaseDialog.exec();
}

void MainWindow::openRegisterDialog()
{
    RegistrationDialog dialog(this);
    dialog.exec();
}
