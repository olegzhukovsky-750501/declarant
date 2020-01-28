#include "excratedialog.h"
#include "ui_excratedialog.h"

ExcRateDialog::ExcRateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExcRateDialog)
{
    ui->setupUi(this);

    createConnection();
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM val", excDir);

    model->setHeaderData(0, Qt::Horizontal, "Код");
    model->setHeaderData(1, Qt::Horizontal, "Бук. код");
    model->setHeaderData(2, Qt::Horizontal, "Наименование");

    ui->view = new QTableView;
    ui->view->setModel(model);

    connect(ui->view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemViewDoubleClicked(const QModelIndex&)));

    verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(ui->view);
    setLayout(verticalLayout);
}

ExcRateDialog::~ExcRateDialog()
{
    delete ui;
}

bool ExcRateDialog::createConnection()
{
    excDir = QSqlDatabase::addDatabase("QSQLITE", "ExcRateBase");
    excDir.setDatabaseName("C:\\Users\\User\\Documents\\untitled3\\npi.db3");
    excDir.setPort(5432);
    excDir.setHostName("localhost");
    excDir.setUserName("postgres");
    excDir.setPassword("root");

    if(!(excDir.open()))
    {
        qDebug() << "Cannot open database:" << excDir.lastError();
        return false;
    }
    else
    {
        return true;
    }
}

void ExcRateDialog::itemViewDoubleClicked(const QModelIndex &index)
{
    emit itemViewClicked(index);
}
