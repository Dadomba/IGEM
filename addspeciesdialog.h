#ifndef ADDSPECIESDIALOG_H
#define ADDSPECIESDIALOG_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
    class addSpeciesDialog;
}

class addSpeciesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addSpeciesDialog(QWidget *parent = 0);
    ~addSpeciesDialog();

private:
    Ui::addSpeciesDialog *ui;

private slots:
    void on_cancelButton_clicked();
    void on_addButton_clicked();

signals:
    void addSpeciesRequestFromDia(string name,bool initial_value);
};

#endif // ADDSPECIESDIALOG_H
