#include "countrydialog.h"
#include "ui_countrydialog.h"

CountryDialog::CountryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CountryDialog)
{
    ui->setupUi(this);

    createConnection();
    model = new QSqlQueryModel;
    model->setQuery("SELECT ABC2, KOD, KRNAIM, IMPORT, S_IMPORT, ABC3"
                    " FROM countries", countryDir);

    model->setHeaderData(0, Qt::Horizontal, "Абр. 1");
    model->setHeaderData(1, Qt::Horizontal, "Код");
    model->setHeaderData(2, Qt::Horizontal, "Наименование");
    model->setHeaderData(3, Qt::Horizontal, "Коэф имп. пош.");
    model->setHeaderData(4, Qt::Horizontal, "Коэф имп. пош. с сертиф.");
    model->setHeaderData(5, Qt::Horizontal, "Абр. 2");
    ui->view = new QTableView;
    ui->view->setModel(model);

    connect(ui->view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemViewDoubleClicked(const QModelIndex&)));

    verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(ui->view);
    setLayout(verticalLayout);
}

CountryDialog::~CountryDialog()
{
    delete ui;
}

bool CountryDialog::createConnection()
{
    countryDir = QSqlDatabase::addDatabase("QSQLITE", "CountryBase");
    countryDir.setDatabaseName("C:\\Users\\User\\Documents\\untitled3\\npi.db3");
    countryDir.setPort(5432);
    countryDir.setHostName("localhost");
    countryDir.setUserName("postgres");
    countryDir.setPassword("root");

    if(!(countryDir.open()))
    {
        qDebug() << "Cannot open database:" << countryDir.lastError();
        return false;
    }
    else
    {
        return true;
    }
}

QTableView *CountryDialog::getTableView()
{
    return ui->view;
}

void CountryDialog::itemViewDoubleClicked(const QModelIndex &index)
{
    emit itemViewClicked(index);
}
