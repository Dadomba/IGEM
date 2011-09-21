#ifndef SYSTEMDIALOG_H
#define SYSTEMDIALOG_H

#include <QDialog>
#include <QList>
#include <QSet>
#include <QTreeWidget>
#include <QMessageBox>

namespace Ui {
    class systemDialog;
}

class systemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit systemDialog(QWidget *parent = 0);
    systemDialog(QList<QTreeWidgetItem *>, QWidget *parent = 0);
    ~systemDialog();

private:
    Ui::systemDialog *ui;
    void refresh_species_available();

private slots:
    void on_button_remove_specie_clicked();
    void on_button_add_specie_clicked();
    void on_button_cancel_clicked();
    void on_button_create_system_clicked();
    void on_button_remove_clicked();
    void on_button_add_clicked();

signals:
    void createSystemRequestFromDia(QString name, QStringList reaction_list);
};

#endif // SYSTEMDIALOG_H
