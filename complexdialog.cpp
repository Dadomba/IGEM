#include "complexdialog.h"
#include "ui_complexdialog.h"

complexDialog::complexDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::complexDialog)
{
    ui->setupUi(this);
}

complexDialog::complexDialog(QStringList species_names,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::complexDialog)
{
    ui->setupUi(this);

        for(int i=0;i<species_names.size();i++){
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0,species_names.at(i));
            this->ui->species->addTopLevelItem(item);
        }
        this->ui->species->sortItems(0,Qt::AscendingOrder);
        this->ui->comboBox_species->addItems(species_names);
        this->ui->complex_name->setFocus();
}

complexDialog::~complexDialog()
{
    delete ui;
}

void complexDialog::on_button_cancel_clicked()
{
    this->close();
}

void complexDialog::on_button_add_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->species->currentItem() != NULL){
        item->setText(0,this->ui->species->currentItem()->text(0));
        this->ui->speciesToComplex->addTopLevelItem(item);
        int index = this->ui->species->indexOfTopLevelItem(this->ui->species->currentItem());
        this->ui->species->takeTopLevelItem(index);

        this->ui->species->sortItems(0,Qt::AscendingOrder);
        this->ui->speciesToComplex->sortItems(0,Qt::AscendingOrder);
    }
}

void complexDialog::on_button_remove_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->speciesToComplex->currentItem() != NULL){
        item->setText(0,this->ui->speciesToComplex->currentItem()->text(0));
        this->ui->species->addTopLevelItem(item);
        int index = this->ui->speciesToComplex->indexOfTopLevelItem(this->ui->speciesToComplex->currentItem());
        this->ui->speciesToComplex->takeTopLevelItem(index);

        this->ui->species->sortItems(0,Qt::AscendingOrder);
        this->ui->speciesToComplex->sortItems(0,Qt::AscendingOrder);
    }
}

void complexDialog::on_button_add_reaction_clicked()
{
    QString name = this->ui->complex_name->text();
    QStringList to_complex_list;
    for(int i=0;i<this->ui->speciesToComplex->topLevelItemCount();i++){
        to_complex_list << this->ui->speciesToComplex->topLevelItem(i)->text(0);
    }
    QString result = this->ui->comboBox_species->currentText();

    if(to_complex_list.contains(result)){
        QMessageBox::warning(this, "Complexation Error", "The result specie can't be on the species to complex list.");
    }
    else if(to_complex_list.count()<2){
        QMessageBox::warning(this, "Complexation Error", "You must complex at least 2 species.");
    }
    else if(name==""){
        QMessageBox::warning(this, "Complexation Error", "Please specify a name for the complexation.");

    }
    else{
        emit addCplxRequestFromDia(name,to_complex_list,result);
        this->close();
    }
}
