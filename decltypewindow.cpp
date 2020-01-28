#include "decltypewindow.h"
#include "ui_decltypewindow.h"

void DeclTypeWindow::treeItemDoubleClicked(QTreeWidgetItem *treeItem, int column)
{
    emit itemDoubleClicked(treeItem, column);
}

DeclTypeWindow::DeclTypeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeclTypeWindow)
{
    ui->setupUi(this);
    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(treeItemDoubleClicked(QTreeWidgetItem*, int)));
}

DeclTypeWindow::~DeclTypeWindow()
{
    delete ui;
}

QTreeWidget *DeclTypeWindow::getTree()
{
    return ui->treeWidget;
}
