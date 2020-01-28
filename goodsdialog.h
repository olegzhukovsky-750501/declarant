#ifndef GOODSDIALOG_H
#define GOODSDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QLabel>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class GoodsDialog;
}

class GoodsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoodsDialog(QWidget *parent = nullptr);
    ~GoodsDialog();

signals:
    void textEdit_textChanged(const QString &text, int row);

    void tableWidget_itemChanged(QTableWidgetItem *item);

    void buttonAddClicked();

    void deleteEntryFromDbGoods(int id);

private slots:
    void on_textEdit_textChanged();

    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_2_clicked();

    void slotToUpdateTable(QSqlRecord rec);

    void slotToUpdateUidGoods(QSqlRecord rec);

    void on_tableWidget_itemEntered(QTableWidgetItem *item);

private:
    Ui::GoodsDialog *ui;
    QTextEdit *nameText;
    QVector<QTextEdit*> vecText;
    int maxLength_TextEdit;
};

#endif // GOODSDIALOG_H
