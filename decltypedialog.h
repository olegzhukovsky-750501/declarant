#ifndef DECLTYPEDIALOG_H
#define DECLTYPEDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>
#include <QBoxLayout>

namespace Ui {
class DeclTypeDialog;
}

class DeclTypeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeclTypeDialog(QWidget *parent = nullptr);
    ~DeclTypeDialog();

    bool createConnection();
    QTableView* getTableView();

    friend class Frame;

signals:
    void itemViewClicked(const QModelIndex &index);
private slots:
    void itemViewDoubleClicked(const QModelIndex &index);

private:
    Ui::DeclTypeDialog *ui;
    QSqlDatabase declDir;
    QSqlQueryModel* model;
    QVBoxLayout *verticalLayout;
};

#endif // DECLTYPEDIALOG_H
