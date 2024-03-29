#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
	
	
	

public slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_lineEdit_7_textChanged(QString );
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    bool test1(QString str);
};

#endif // MAINWINDOW_H
