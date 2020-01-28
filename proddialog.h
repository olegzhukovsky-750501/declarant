#ifndef PRODDIALOG_H
#define PRODDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>
#include <QBoxLayout>

namespace Ui {
class ProdDialog;
}

class ProdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProdDialog(QWidget *parent = nullptr);
    ~ProdDialog();

    bool createConnection();

    friend class Frame;
signals:
    void itemViewClicked(const QModelIndex &index);
private slots:
    void itemViewDoubleClicked(const QModelIndex &index);
private:
    Ui::ProdDialog *ui;

    QSqlDatabase prodDir;
    QSqlQueryModel* model;
    QVBoxLayout *verticalLayout;
};

#endif // PRODDIALOG_H
