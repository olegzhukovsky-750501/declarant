#pragma once

#include <QDialog>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>
#include <QBoxLayout>

namespace Ui {
class CountryDialog;
}

class CountryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CountryDialog(QWidget *parent = nullptr);
    ~CountryDialog();

    bool createConnection();

    friend class SenderDialog;
    friend class ReceiverDialog;
    friend class DeclarantDialog;
    friend class Frame;

    QTableView* getTableView();
signals:
    void itemViewClicked(const QModelIndex &index);
private slots:
    void itemViewDoubleClicked(const QModelIndex &index);

private:
    Ui::CountryDialog *ui;

    QSqlDatabase countryDir;
    QSqlQueryModel* model;
    QVBoxLayout *verticalLayout;
};
