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
