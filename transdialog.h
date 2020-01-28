#ifndef TRANSDIALOG_H
#define TRANSDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>
#include <QBoxLayout>

namespace Ui {
class TransDialog;
}

class TransDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransDialog(QWidget *parent = nullptr);
    ~TransDialog();

    bool createConnection();

    friend class Frame;
signals:
    void itemViewClicked(const QModelIndex &index);
private slots:
    void itemViewDoubleClicked(const QModelIndex &index);
private:
    Ui::TransDialog *ui;

    QSqlDatabase transDir;
    QSqlQueryModel* model;
    QVBoxLayout *verticalLayout;
};

#endif // TRANSDIALOG_H
