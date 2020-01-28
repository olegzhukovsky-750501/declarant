#include "proddialog.h"
#include "ui_proddialog.h"

ProdDialog::ProdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProdDialog)
{
    ui->setupUi(this);

    createConnection();
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM tovar", prodDir);

    model->setHeaderData(0, Qt::Horizontal, "Код");
    model->setHeaderData(1, Qt::Horizontal, "Наименование");

    ui->view = new QTableView;
    ui->view->setModel(model);

    connect(ui->view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemViewDoubleClicked(const QModelIndex&)));

    verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(ui->view);
    setLayout(verticalLayout);
}

ProdDialog::~ProdDialog()
{
    delete ui;
}

bool ProdDialog::createConnection()
{
    prodDir = QSqlDatabase::addDatabase("QSQLITE", "ProdBase");
    prodDir.setDatabaseName("C:\\Users\\User\\Documents\\untitled3\\npi.db3");
    prodDir.setPort(5432);
    prodDir.setHostName("localhost");
    prodDir.setUserName("postgres");
    prodDir.setPassword("root");

    if(!(prodDir.open()))
    {
        qDebug() << "Cannot open database:" << prodDir.lastError();
        return false;
    }
    else
    {
        return true;
    }
}

void ProdDialog::itemViewDoubleClicked(const QModelIndex &index)
{
    emit itemViewClicked(index);
}
