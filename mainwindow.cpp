#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//QListView* NotesList = ui->listView;
//NotesList->setModel(new QStringListModel()); //string
/*NotesList->setStyleSheet("QListView {font: 75 11pt\"Bodoni MT\";border-style:solid;border-width:2px;border-color: rgb(109, 127, 209);}"
                         "QListView::item{color:rgb(155, 38, 175);}");
*/
    QListWidget* NotesList = ui->listWidget;
    NotesList->setStyleSheet("QListView {font: 75 11pt\"Bodoni MT\";border-style:solid;border-width:2px;border-color: rgb(109, 127, 209);}"
                             "QListView::item{color:rgb(155, 38, 175);}");
    readFromFile(NotesList, "notes.txt");

    createConnections(); //delete?



}
MainWindow::~MainWindow()
{
    delete ui;
}
//styles for buttons
QString qspressed = "font: 11pt\"Bodoni MT\" ;background-color: rgb(109, 127, 209); border-radius: 10px; border-bottom-style:solid;border-bottom-width: 5px; border-bottom-color: rgb(109, 127, 209);";
QString qsreleased = "font: 11pt\"Bodoni MT\" ;background-color: rgb(172, 169, 255); border-radius: 10px; border-bottom-style:solid;border-bottom-width: 5px; border-bottom-color: rgb(109, 127, 209);";
//list of notes

void MainWindow::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet(qspressed);
}
void MainWindow::on_pushButton_2_pressed()
{
    ui->pushButton_2->setStyleSheet(qspressed);

}
void MainWindow::on_pushButton_3_pressed()
{
    ui->pushButton_3->setStyleSheet(qspressed);
}
void MainWindow::on_pushButton_4_pressed()
{
    ui->pushButton_4->setStyleSheet(qspressed);
}
void MainWindow::on_pushButton_2_released()
{
    ui->pushButton_2->setStyleSheet(qsreleased); 
}
void MainWindow::on_pushButton_3_released()
{
    ui->pushButton_3->setStyleSheet(qsreleased);
    saveToFile();
    secwindow = new secondwindow(this);
    secwindow->setModal(true);
    secwindow->exec();
    QListWidget* NotesList = ui->listWidget;
    NotesList->clear();
    readFromFile(NotesList, "notes.txt");
}
void MainWindow::on_pushButton_4_released()
{
    ui->pushButton_4->setStyleSheet(qsreleased);
}
void MainWindow::on_pushButton_released()
{
    ui->pushButton->setStyleSheet(qsreleased);

    saveToFile();
    QApplication::quit();
}


void MainWindow::readFromFile(QListWidget* NotesList, QString nameoffile)
{
    QFile file (nameoffile);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
       while(!file.atEnd())
       {
        QString line = file.readLine();
        if(line[line.size()-1]=='\n')
            line.resize(line.size()-1);

        QListWidgetItem* b = new QListWidgetItem;
        b->setText(line);
        b->setData(Qt::CheckStateRole,line);
        NotesList->addItem(b);
       }
     }
}
void MainWindow::saveToFile()
{
    QFile file ("notes.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream stream(&file);
        for(int i=0; i<ui->listWidget->count(); i++)
        {
        QListWidgetItem *item = ui->listWidget->item(i);
                    stream << item->text()<<'\n';
        }
        }
}
void MainWindow::saveToArchive(QListWidgetItem *item)
{
    QFile file ("archieve.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream stream(&file);
         stream << item->text()<<'\n';
    }
}


void MainWindow::on_lineEdit_editingFinished()
{
    QString a = ui->lineEdit->text();
    ui->lineEdit->clear();

    if(a!="" && a.size()<=30)
    {
//QListView* NotesList = ui->listView;
//NotesList->model()->insertRow(NotesList->model()->rowCount());
//int rowindex = NotesList->model()->rowCount()-1;
//NotesList->model()->setData(NotesList->model()->index(rowindex,0),a);    //string
        QListWidget* NotesList = ui->listWidget;
        QListWidgetItem* b = new QListWidgetItem;
        b->setText(a);
        b->setData(Qt::CheckStateRole,a);
        NotesList->addItem(b);

    }
    else
    if(a.size()>30)
    {
        QMessageBox::warning(this,"Error", "you entered more than 30 symbols");
    }
}
void MainWindow::createConnections(){
    QObject::connect(ui->listWidget, SIGNAL(itemChanged(QListWidgetItem*)),
                     this, SLOT(removeChecked(QListWidgetItem*)));
    QObject::connect(ui->pushButton_2, SIGNAL(released()),this,SLOT(removeSelectedItem()));

}


void MainWindow::removeChecked(QListWidgetItem *item){
    if(item->checkState() == Qt::Checked){
        saveToArchive(item);
        ui->listWidget->removeItemWidget(item);
     delete item;
    }
}
void MainWindow::removeSelectedItem()
{
    QListWidget* NotesList = ui->listWidget;
    QListWidgetItem* item = NotesList->currentItem();
    if(item)
    {
    ui->listWidget->removeItemWidget(item);
 delete item;
    }
}
