#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QListWidgetItem>
#include "secondwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
   // void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_4_released();

    void on_pushButton_released();

    void on_lineEdit_editingFinished();

    void removeChecked(QListWidgetItem *item);

    void saveToFile();

    void readFromFile( QListWidget*, QString);

    void saveToArchive(QListWidgetItem *item);

    void removeSelectedItem();

private:
    Ui::MainWindow *ui;
    secondwindow* secwindow;
void createConnections();


};
#endif // MAINWINDOW_H
