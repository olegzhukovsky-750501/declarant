#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include <QDialog>

namespace Ui {
class CalendarDialog;
}

class CalendarDialog : public QDialog
{
    Q_OBJECT


public:
    explicit CalendarDialog(QWidget *parent = nullptr);
    ~CalendarDialog();

signals:
    void dateChanged(const QDate &date);
private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CalendarDialog *ui;
};

#endif // CALENDARDIALOG_H
