#include "systemdialog.h"
#include "ui_systemdialog.h"

systemDialog::systemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::systemDialog)
{
    ui->setupUi(this);
}

systemDialog::systemDialog(QList<QTreeWidgetItem *> react, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::systemDialog)
{
    ui->setupUi(this);
    for(int i=0;i<react.size();i++){
        QTreeWidgetItem *item = new QTreeWidgetItem;
        for(int j=0;j<react.at(0)->columnCount();j++){
            item->setText(j,react.at(i)->text(j));
        }
        this->ui->list_reactions_available->addTopLevelItem(item);
    }


}


systemDialog::~systemDialog()
{
    delete ui;
}

void systemDialog::on_button_add_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->list_reactions_available->currentItem() != NULL){
        for(int j=0;j<this->ui->list_reactions_available->currentItem()->columnCount();j++){
            item->setText(j,this->ui->list_reactions_available->currentItem()->text(j));
        }
        this->ui->list_reactions_in_system->addTopLevelItem(item);

        int index = this->ui->list_reactions_available->indexOfTopLevelItem(this->ui->list_reactions_available->currentItem());
        this->ui->list_reactions_available->takeTopLevelItem(index);

        this->ui->list_reactions_available->sortItems(0,Qt::AscendingOrder);
        this->ui->list_reactions_in_system->sortItems(0,Qt::AscendingOrder);
        refresh_species_available();
    }
}

void systemDialog::on_button_remove_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->list_reactions_in_system->currentItem() != NULL){
        for(int j=0;j<this->ui->list_reactions_in_system->currentItem()->columnCount();j++){
            item->setText(j,this->ui->list_reactions_in_system->currentItem()->text(j));
        }
        this->ui->list_reactions_available->addTopLevelItem(item);

        int index = this->ui->list_reactions_in_system->indexOfTopLevelItem(this->ui->list_reactions_in_system->currentItem());
        this->ui->list_reactions_in_system->takeTopLevelItem(index);

        this->ui->list_reactions_available->sortItems(0,Qt::AscendingOrder);
        this->ui->list_reactions_in_system->sortItems(0,Qt::AscendingOrder);
        refresh_species_available();
    }
}

void systemDialog::on_button_create_system_clicked()
{

    QString name = this->ui->system_name->text();
    QStringList reaction_list;
    for(int i=0;i<this->ui->list_reactions_in_system->topLevelItemCount();i++){
        reaction_list << this->ui->list_reactions_in_system->topLevelItem(i)->text(0);
    }

    if(reaction_list.count()<1){
        QMessageBox::warning(this, "System Error", "You must specify at least one reaction.");
    }
    else if(name==""){
        QMessageBox::warning(this, "System Error", "Please specify a name for the system.");
    }
    else{
        emit createSystemRequestFromDia(name,reaction_list);
        this->close();
    }

}

void systemDialog::on_button_cancel_clicked()
{
    this->close();
}


void systemDialog::refresh_species_available(){
    QStringList species_available,species_listed_cst,species_listed_var;
    if(this->ui->list_reactions_in_system->topLevelItemCount()!=0){
        for(int i=0;i<this->ui->list_reactions_in_system->topLevelItemCount();i++){
            species_available << this->ui->list_reactions_in_system->topLevelItem(i)->text(2).split(" ");
        }
        QSet<QString> tmp = species_available.toSet();
        species_available = tmp.toList();
    }
    if(this->ui->list_constant_species->topLevelItemCount()!=0){
        for(int i=0;i<this->ui->list_constant_species->topLevelItemCount();i++){
            species_listed_cst << this->ui->list_constant_species->topLevelItem(i)->text(0);
        }
    }
    if(this->ui->list_variable_species->topLevelItemCount()!=0){
        for(int i=0;i<this->ui->list_variable_species->topLevelItemCount();i++){
            species_listed_var << this->ui->list_variable_species->topLevelItem(i)->text(0);
        }
    }


    for(int i=0;i<species_available.size();i++){
        if(!(species_listed_cst.contains(species_available.at(i))) && !(species_listed_var.contains(species_available.at(i)))){
            QTreeWidgetItem* item = new QTreeWidgetItem;
            item->setText(0,species_available.at(i));
            this->ui->list_constant_species->addTopLevelItem(item);
            this->ui->list_constant_species->sortItems(0,Qt::AscendingOrder);
        }
    }
    for(int i=0;i<species_listed_cst.size();i++){
        if(!(species_available.contains(species_listed_cst.at(i)))){
            qDebug(("a enlever:"+species_listed_cst.at(i)).toStdString().c_str());
            int index = this->ui->list_constant_species->indexOfTopLevelItem(this->ui->list_constant_species->findItems(species_listed_cst.at(i),Qt::MatchExactly).at(0));
            qDebug(("index:" + QString::number(index)).toStdString().c_str());
            this->ui->list_constant_species->takeTopLevelItem(index);
            this->ui->list_constant_species->sortItems(0,Qt::AscendingOrder);
        }
    }
    for(int i=0;i<species_listed_var.size();i++){
        if(!(species_available.contains(species_listed_var.at(i)))){
            qDebug(("a enlever:"+species_listed_var.at(i)).toStdString().c_str());
            int index = this->ui->list_variable_species->indexOfTopLevelItem(this->ui->list_variable_species->findItems(species_listed_var.at(i),Qt::MatchExactly).at(0));
            qDebug(("index:" + QString::number(index)).toStdString().c_str());
            this->ui->list_variable_species->takeTopLevelItem(index);
            this->ui->list_variable_species->sortItems(0,Qt::AscendingOrder);
        }
    }

/////////////////////////////////DEBUG////////////////////////////////////////////////////////////////////
//    if(this->ui->list_reactions_in_system->topLevelItemCount()!=0){
//        for(int i=0;i<this->ui->list_reactions_in_system->topLevelItemCount();i++){
//            species_available << this->ui->list_reactions_in_system->topLevelItem(i)->text(2).split(" ");
//        }
//        QSet<QString> tmp = species_available.toSet();
//        species_available = tmp.toList();
//    }
//    if(this->ui->list_constant_species->topLevelItemCount()!=0){
//        for(int i=0;i<this->ui->list_constant_species->topLevelItemCount();i++){
//            species_listed_cst << this->ui->list_constant_species->topLevelItem(i)->text(0);
//        }
//        QSet<QString> tmp = species_listed_cst.toSet();
//        species_listed_cst = tmp.toList();
//    }
//    if(this->ui->list_variable_species->topLevelItemCount()!=0){
//        for(int i=0;i<this->ui->list_variable_species->topLevelItemCount();i++){
//            species_listed_var << this->ui->list_variable_species->topLevelItem(i)->text(0);
//        }
//        QSet<QString> tmp = species_listed_var.toSet();
//        species_listed_var = tmp.toList();
//    }

//        qDebug("avalaible:");
//    for(int i=0;i<species_available.size();i++){
//        qDebug(species_available.at(i).toStdString().c_str());
//    }
//        qDebug("listed cst:");
//    for(int i=0;i<species_listed_cst.size();i++){
//        qDebug(species_listed_cst.at(i).toStdString().c_str());
//    }
//        qDebug("listed var:");
//    for(int i=0;i<species_listed_var.size();i++){
//        qDebug(species_listed_var.at(i).toStdString().c_str());
//    }

//    /////////////////////////////////////////////////////////////////////////////////////
}

void systemDialog::on_button_add_specie_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->list_constant_species->currentItem() != NULL){
        item->setText(0,this->ui->list_constant_species->currentItem()->text(0));
        this->ui->list_variable_species->addTopLevelItem(item);

        int index = this->ui->list_constant_species->indexOfTopLevelItem(this->ui->list_constant_species->currentItem());
        this->ui->list_constant_species->takeTopLevelItem(index);

        this->ui->list_constant_species->sortItems(0,Qt::AscendingOrder);
        this->ui->list_variable_species->sortItems(0,Qt::AscendingOrder);
    }
}

void systemDialog::on_button_remove_specie_clicked()
{
    QTreeWidgetItem* item = new QTreeWidgetItem;
    if(this->ui->list_variable_species->currentItem() != NULL){
        item->setText(0,this->ui->list_variable_species->currentItem()->text(0));
        this->ui->list_constant_species->addTopLevelItem(item);

        int index = this->ui->list_variable_species->indexOfTopLevelItem(this->ui->list_variable_species->currentItem());
        this->ui->list_variable_species->takeTopLevelItem(index);

        this->ui->list_constant_species->sortItems(0,Qt::AscendingOrder);
        this->ui->list_variable_species->sortItems(0,Qt::AscendingOrder);
    }
}
