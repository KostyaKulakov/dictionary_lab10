#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "Dictionary.h"
#include "adddialog.h"

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
    void loadDictionary();
    void setFocusDict();
    void saveDictionary();
    void reloadDictLists();
    void on_removeWordButton_clicked();
    void on_translateButton_clicked();
    void addWord();

private:
    Ui::MainWindow *ui;
    Dictionary dict;
    AddDialog* addWordUi;
};

#endif // MAINWINDOW_H
