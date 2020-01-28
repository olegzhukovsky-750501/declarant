#include "decllist.h"
#include "ui_decllist.h"

DeclList::DeclList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeclList)
{
    ui->setupUi(this);
    connect(ui->tableWidget,
            SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
            this,
            SLOT(slotTableItemDoubleClicked(QTableWidgetItem*)));
}

DeclList::~DeclList()
{
    delete ui;
}

QScrollArea *DeclList::getScrollArea()
{
    return ui->scrollArea;
}

void DeclList::slotToUpdateTable(QSqlRecord rec)
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             0, new QTableWidgetItem((rec.value("DT1")).toString()
                                                    +(rec.value("DT2")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             1, new QTableWidgetItem((rec.value("id")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             2, new QTableWidgetItem((rec.value("SD1")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             3, new QTableWidgetItem((rec.value("RV1")).toString()));

    ui->tableWidget->setItem(ui->tableWidget->rowCount() -1,
                             4, new QTableWidgetItem((rec.value("FL18")).toString()));
}

void DeclList::slotToRemoveRow()
{
    QItemSelectionModel *select = ui->tableWidget->selectionModel();

    if(select->hasSelection())
    {
        QModelIndexList selection = select->selectedIndexes();

        QModelIndex index = selection.at(0);

        int id = (ui->tableWidget->item(index.row(), 1)->text()).toInt();

        ui->tableWidget->removeRow(index.row());

        emit toChangeNumRecords();

        emit toDeleteEntryFromStack(id);

        emit toDeleteEntryFromDb(id);
    }

}

void DeclList::slotToRemoveTable()
{
    ui->tableWidget->setRowCount(0);
}

void DeclList::slotTableItemDoubleClicked(QTableWidgetItem *item)
{
    emit tableItemDoubleClicked(item);
}
