#include "addspeciesdialog.h"
#include "ui_addspeciesdialog.h"
#include <QMessageBox>

using namespace std;

addSpeciesDialog::addSpeciesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSpeciesDialog)
{
    ui->setupUi(this);
    this->ui->nameToAdd->setFocus();
}

addSpeciesDialog::~addSpeciesDialog()
{
    delete ui;
}

void addSpeciesDialog::on_addButton_clicked()
{
    string name = this->ui->nameToAdd->text().toStdString();
    bool initial_value;
    QString ini_val_qt =this->ui->initialValueToAdd->currentText();
    if(ini_val_qt == QString("HIGH")){
        initial_value = true;
    }
    else{
        initial_value = false;
    }

    if(name!=""){
        emit addSpeciesRequestFromDia(name,initial_value);
        this->close();
    }
    else{
        QMessageBox::warning(this, "Adding Error", "Please specify the name of the specie.");
    }

}

void addSpeciesDialog::on_cancelButton_clicked()
{
    this->close();
}

