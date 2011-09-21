#ifndef MANAGER_H
#define MANAGER_H

#include <cstdlib>
#include <QObject>
#include <QInputDialog>
#include "mainwindow.h"
#include "species.h"
#include "reaction.h"
#include "inh.h"
#include "complex.h"
#include "synth.h"
#include "system.h"
#include "bio_cst.h"


class Manager : public QObject
{
    Q_OBJECT
private:
    MainWindow *ui;
    Species *species_list;
    int species_list_size;
    p_Reaction *reaction_list;
    int reaction_list_size;

    Species* newTabAllocation(int size);
    p_Reaction* newTabAllocation_react(int size);

public:
    Manager(MainWindow *target_ui);
    bool addSpeciesToList(string name, bool initial_value);
    bool removeSpeciesFromList(string name);
    bool modifySpeciesToList(string name, bool initial_value);
    bool isSpeciesInList(string name);
    bool addReactionToList(Reaction *react_to_add);
    bool removeReactionFromList(string name);
    bool isReactionInList(string name);
    bool patCreation(QString name, QStringList reactions, p_Reaction *reaction_in_system_tab, int reaction_in_system_tab_size);

public slots:
    void speciesAddRequest(string name, bool initial_value);
    void speciesRemoveRequest(string name);
    void speciesModifyRequest(string name, bool initial_value);
    void reactionAddRequest(QString name, int type, QStringList speciesin, QString speciesout, QStringList speciesoptional);
    void reactionRemoveRequest(string name);
    void systemCreationRequest(QString name, QStringList reactions);

signals:
    void speciesAddingSuccess(bool result,string name, bool initial_value);
    void speciesRemovingSuccess(bool result, string name);
    void speciesModifiingSuccess(bool res, string name, bool initial_value);
    void reactionAddingSuccess(bool res, QString name, int type, QStringList speciesin, QString speciesout = QString(), QStringList speciesoptional = QStringList());
    void reactionRemovingSuccess(bool res, string name);
    void systemCreationSuccess(bool res, QString name);
};

#endif // MANAGER_H
