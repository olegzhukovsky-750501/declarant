#ifndef EXCRATEDIALOG_H
#define EXCRATEDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>
#include <QBoxLayout>

namespace Ui {
class ExcRateDialog;
}

class ExcRateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExcRateDialog(QWidget *parent = nullptr);
    ~ExcRateDialog();

    bool createConnection();

    friend class Frame;

signals:
    void itemViewClicked(const QModelIndex &index);
private slots:
    void itemViewDoubleClicked(const QModelIndex &index);

private:
    Ui::ExcRateDialog *ui;

    QSqlDatabase excDir;
    QSqlQueryModel* model;
    QVBoxLayout *verticalLayout;
};

#endif // EXCRATEDIALOG_H
