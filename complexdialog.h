#ifndef COMPLEXDIALOG_H
#define COMPLEXDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class complexDialog;
}

class complexDialog : public QDialog
{
    Q_OBJECT

public:
    explicit complexDialog(QWidget *parent = 0);
    complexDialog(QStringList species_names, QWidget *parent = 0);
    ~complexDialog();

private:
    Ui::complexDialog *ui;

private slots:
    void on_button_add_reaction_clicked();
    void on_button_remove_clicked();
    void on_button_add_clicked();
    void on_button_cancel_clicked();

signals:
    void addCplxRequestFromDia(QString name, QStringList species_to_complex, QString result);
};

#endif // COMPLEXDIALOG_H
