#ifndef INHDIALOG_H
#define INHDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class inhDialog;
}

class inhDialog : public QDialog
{
    Q_OBJECT

public:
    explicit inhDialog(QWidget *parent = 0);
    inhDialog(QStringList species_names,QWidget *parent = 0);
    ~inhDialog();

private:
    Ui::inhDialog *ui;

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_close_clicked();

signals:
    void addInhRequestFromDia(QString name, QString inhibited, QString inhibitor);
};

#endif // INHDIALOG_H
