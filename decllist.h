#ifndef DECLLIST_H
#define DECLLIST_H

#include <QWidget>
#include <QScrollArea>
#include <QtSql>
#include <QTableWidgetItem>

namespace Ui {
class DeclList;
}

class DeclList : public QWidget
{
    Q_OBJECT

public:
    explicit DeclList(QWidget *parent = nullptr);
    ~DeclList();

    QScrollArea* getScrollArea();

signals:
    void tableItemDoubleClicked(QTableWidgetItem *item);
    void toChangeNumRecords();
    void toDeleteEntryFromDb(int id);
    void toDeleteEntryFromStack(int id);
private slots:
    void slotToUpdateTable(QSqlRecord rec);
    void slotToRemoveRow();
    void slotToRemoveTable();
    void slotTableItemDoubleClicked(QTableWidgetItem *item);
private:
    Ui::DeclList *ui;
};

#endif // DECLLIST_H
