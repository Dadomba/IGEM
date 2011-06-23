#include "synthdialog.h"
#include "ui_synthdialog.h"

synthDialog::synthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::synthDialog)
{
    ui->setupUi(this);
}

synthDialog::synthDialog(QStringList species_names,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::synthDialog)
{
    ui->setupUi(this);

    this->ui->comboBox_species->addItems(species_names);
    for(int i=0;i<species_names.size();i++){
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0,species_names.at(i));
        this->ui->species_available_list->addTopLevelItem(item);
    }
    this->ui->species_available_list->sortItems(0,Qt::AscendingOrder);
}

synthDialog::~synthDialog()
{
    delete ui;
}

void synthDialog::on_button_addActivators_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->species_available_list->currentItem() != NULL){
        item->setText(0,this->ui->species_available_list->currentItem()->text(0));
        this->ui->species_activators->addTopLevelItem(item);
        int index = this->ui->species_available_list->indexOfTopLevelItem(this->ui->species_available_list->currentItem());
        this->ui->species_available_list->takeTopLevelItem(index);

        this->ui->species_available_list->sortItems(0,Qt::AscendingOrder);
        this->ui->species_activators->sortItems(0,Qt::AscendingOrder);
    }
}

void synthDialog::on_button_removeActivators_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->species_activators->currentItem() != NULL){
        item->setText(0,this->ui->species_activators->currentItem()->text(0));
        this->ui->species_available_list->addTopLevelItem(item);
        int index = this->ui->species_activators->indexOfTopLevelItem(this->ui->species_activators->currentItem());
        this->ui->species_activators->takeTopLevelItem(index);

        this->ui->species_available_list->sortItems(0,Qt::AscendingOrder);
        this->ui->species_activators->sortItems(0,Qt::AscendingOrder);
    }
}

void synthDialog::on_button_addRepressors_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->species_available_list->currentItem() != NULL){
        item->setText(0,this->ui->species_available_list->currentItem()->text(0));
        this->ui->species_repressors->addTopLevelItem(item);
        int index = this->ui->species_available_list->indexOfTopLevelItem(this->ui->species_available_list->currentItem());
        this->ui->species_available_list->takeTopLevelItem(index);

        this->ui->species_available_list->sortItems(0,Qt::AscendingOrder);
        this->ui->species_repressors->sortItems(0,Qt::AscendingOrder);
    }
}

void synthDialog::on_button_removeRepressors_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->species_repressors->currentItem() != NULL){
        item->setText(0,this->ui->species_repressors->currentItem()->text(0));
        this->ui->species_available_list->addTopLevelItem(item);
        int index = this->ui->species_repressors->indexOfTopLevelItem(this->ui->species_repressors->currentItem());
        this->ui->species_repressors->takeTopLevelItem(index);

        this->ui->species_available_list->sortItems(0,Qt::AscendingOrder);
        this->ui->species_repressors->sortItems(0,Qt::AscendingOrder);
    }
}

void synthDialog::on_button_add_reaction_clicked()
{
    QString name = this->ui->synth_name->text();
    QStringList activators, repressors;
    for(int i=0;i<this->ui->species_activators->topLevelItemCount();i++){
        activators << this->ui->species_activators->topLevelItem(i)->text(0);
    }
    for(int i=0;i<this->ui->species_repressors->topLevelItemCount();i++){
        repressors << this->ui->species_repressors->topLevelItem(i)->text(0);
    }
    QString result = this->ui->comboBox_species->currentText();

    if(activators.contains(result) || repressors.contains(result)){
        QMessageBox::warning(this, "Synthesis Error", "The result specie can't be on the activators or repressors list.");
    }
    else if(activators.count()<1 || repressors.count()<1){
        QMessageBox::warning(this, "Synthesis Error", "You define at least one activator and one repressor.");
    }
    else if(name==""){
        QMessageBox::warning(this, "Synthesis Error", "Please specify a name for the synthesis.");

    }
    else{
        emit addSynthRequestFromDia(name,activators,result,repressors);
        this->close();
    }
}

void synthDialog::on_button_cancel_clicked()
{
    this->close();
}
