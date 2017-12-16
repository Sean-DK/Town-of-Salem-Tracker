#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_lineEdit_1_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_lineEdit_12_textChanged(const QString &arg1);

    void on_lineEdit_13_textChanged(const QString &arg1);

    void on_lineEdit_14_textChanged(const QString &arg1);

    void on_lineEdit_15_textChanged(const QString &arg1);

    void on_lineEdit_1_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_6_editingFinished();

    void on_lineEdit_7_editingFinished();

    void on_lineEdit_8_editingFinished();

    void on_lineEdit_9_editingFinished();

    void on_lineEdit_10_editingFinished();

    void on_lineEdit_11_editingFinished();

    void on_lineEdit_12_editingFinished();

    void on_lineEdit_13_editingFinished();

    void on_lineEdit_14_editingFinished();

    void on_lineEdit_15_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void loadList();

    void matchString(const QString, int, int);

    void changeRole(int, QString);
};

#endif // MAINWINDOW_H
