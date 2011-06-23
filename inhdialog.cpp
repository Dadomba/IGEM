#include "inhdialog.h"
#include "ui_inhdialog.h"

inhDialog::inhDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inhDialog)
{
    ui->setupUi(this);
}

inhDialog::inhDialog(QStringList species_names,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inhDialog)
{
    ui->setupUi(this);

        this->ui->comboBox_inhibitor->addItems(species_names);
        this->ui->comboBox_spe_to_inh->addItems(species_names);
        this->ui->Inh_name->setFocus();
}


inhDialog::~inhDialog()
{
    delete ui;
}

void inhDialog::on_pushButton_close_clicked()
{
    this->close();
}

void inhDialog::on_pushButton_add_clicked()
{
    if(this->ui->comboBox_inhibitor->currentText() == this->ui->comboBox_spe_to_inh->currentText()){
        QMessageBox::warning(this, "Inhibition Error", "The inhibited specie cannot be its own inhibitor.");
    }
    else if(this->ui->Inh_name->text() == ""){
        QMessageBox::warning(this, "Complexation Error", "Please specify a name for the inhibition.");
    }
    else{
        emit addInhRequestFromDia(this->ui->Inh_name->text(),this->ui->comboBox_spe_to_inh->currentText(),this->ui->comboBox_inhibitor->currentText());
        this->close();
    }
}
