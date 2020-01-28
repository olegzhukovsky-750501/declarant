#ifndef COUNTRIESDIALOG_H
#define COUNTRIESDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QTableView>
#include <QVBoxLayout>

namespace Ui {
class CountriesDialog;
}

class CountriesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CountriesDialog(QWidget *parent = nullptr);
    ~CountriesDialog();

    bool createConnection();

private:
    Ui::CountriesDialog *ui;

};

#endif // COUNTRIESDIALOG_H
