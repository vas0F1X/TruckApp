#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "inputdialog.h"
#include "databasedialog.h"
#include "registrationdialog.h" // Добавили заголовочный файл для регистрации

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openInputDialog();
    void openDatabaseDialog();
    void openRegisterDialog(); // Добавили слот для открытия диалога регистрации

private:
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *inputMenu; // Объявили меню для ручного ввода
    QMenu *databaseMenu; // Объявили меню для работы с базой данных
    QMenu *registerMenu; // Объявили меню для регистрации
    QAction *inputAction;
    QAction *databaseAction;
    QAction *registerAction; // Добавили действие для регистрации
};

#endif // MAINWINDOW_H
