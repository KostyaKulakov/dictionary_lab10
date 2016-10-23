#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();

    QString eng, rus;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_Add_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
