#include "manager.h"

Manager::Manager(MainWindow *target_ui){
    this->ui = target_ui;
    this->species_list=NULL;
    this->species_list_size=0;
    this->reaction_list=NULL;
    this->reaction_list_size=0;


//   //TEST species

//        Species A("A",0);
//        Species B("B",0);
//        Species C("C",1);
//        Species D("D",0);
//        Species E("E",0);
//        Species F("F",1);
//        Species X("X",0);
//        Species Y("Y",1);

//        Species tab_1[2];
//        Species tab_2[2];

//        tab_1[0] = A;
//        tab_1[1] = B;

//        tab_2[0] = C;
//        tab_2[1] = D;


//        // Instanciation des 3 blocs

//        Inh inh_1("inh_1", "inh_1","inh_1",D,F);
//        Complex cplx_1("cplx_1", "cplx_1","cplx_1",tab_1,2,X);
//        Synth synth_1("synth_1", "synth_1","synth_1",tab_1, tab_2, 2, 2,Y);

//        inh_1.file_creation();
//        cplx_1.file_creation();
//        synth_1.file_creation();

//        p_Reaction* test = new p_Reaction[3];
//        test[0] = &inh_1;
//        test[1] = &synth_1;
//        test[2] = &cplx_1;
//        System syst_1(test,3,"test","test","test");

//        syst_1.test_bench_generation();


    connect(this->ui,SIGNAL(addSpeciesRequestFromUi(string,bool)),this,SLOT(speciesAddRequest(string,bool)));
    connect(this,SIGNAL(speciesAddingSuccess(bool,string,bool)),this->ui,SLOT(speciesAddingResult(bool,string,bool)));
    connect(this->ui,SIGNAL(removeSpeciesRequestFromUi(string)),this,SLOT(speciesRemoveRequest(string)));
    connect(this,SIGNAL(speciesRemovingSuccess(bool,string)),this->ui,SLOT(speciesRemovingResult(bool,string)));
    connect(this->ui,SIGNAL(modifySpeciesRequestFromUi(string,bool)),this,SLOT(speciesModifyRequest(string,bool)));
    connect(this,SIGNAL(speciesModifiingSuccess(bool,string,bool)),this->ui,SLOT(speciesModifiingResult(bool,string,bool)));
    connect(this->ui,SIGNAL(addReactionRequestFromUi(QString,int,QStringList,QString,QStringList)),this,SLOT(reactionAddRequest(QString,int,QStringList,QString,QStringList)));
    connect(this,SIGNAL(reactionAddingSuccess(bool,QString,int,QStringList,QString,QStringList)),this->ui,SLOT(reactionAddingResult(bool,QString,int,QStringList,QString,QStringList)));
    connect(this->ui,SIGNAL(removeReactionRequestFromUi(string)),this,SLOT(reactionRemoveRequest(string)));
    connect(this,SIGNAL(reactionRemovingSuccess(bool,string)),this->ui,SLOT(reactionRemovingResult(bool,string)));
    connect(this->ui,SIGNAL(createSystemRequestFromUi(QString,QStringList)),this,SLOT(systemCreationRequest(QString,QStringList)));
    connect(this,SIGNAL(systemCreationSuccess(bool,QString)),this->ui,SLOT(systemCreationResult(bool,QString)));
}

Species* Manager::newTabAllocation(int size){
    Species *new_tab = new Species[size];
    if(new_tab == NULL){
        std::cerr<<"Dynamic allocation error"<<std::endl;
        exit(-1);
    }
    else{
        return new_tab;
    }
}

p_Reaction* Manager::newTabAllocation_react(int size){
    p_Reaction *new_tab = new p_Reaction[size];
    if(new_tab == NULL){
        std::cerr<<"Dynamic allocation error"<<std::endl;
        exit(-1);
    }
    else{
        return new_tab;
    }
}

//*********************************************//
//                Species Part                 //
//*********************************************//

bool Manager::addSpeciesToList(string name, bool initial_value){

    if(this->isSpeciesInList(name)){
        std::cerr<<"Species already exists in the list"<<std::endl;
        return false;
    }
    else{
        Species *new_tab= this->newTabAllocation(this->species_list_size+1);

        for(int i = 0; i<this->species_list_size; i++)
        {
            new_tab[i] = this->species_list[i];
        }
        new_tab[this->species_list_size] = Species(name,initial_value);
        this->species_list_size++;

        delete[] this->species_list;
        this->species_list = new_tab;
        return true;
    }

}

bool Manager::removeSpeciesFromList(string name){
    if(this->isSpeciesInList(name)){
        Species *new_tab= this->newTabAllocation(this->species_list_size-1);
        int j=0;
        for(int i=0;i<species_list_size;i++){
            if(this->species_list[i].Get_name() != name){
                new_tab[j]=this->species_list[i];
                j++;
            }
        }
        this->species_list_size--;
        this->species_list = new_tab;
        return true;
    }
    else{
        std::cerr<<"Species does not exists in the list"<<std::endl;
        return false;
    }
}

bool Manager::modifySpeciesToList(string name, bool initial_value){
    if(this->isSpeciesInList(name)){
        for(int i=0;i<species_list_size;i++){
            if(this->species_list[i].Get_name() == name){
                this->species_list[i].Set_initial_state(initial_value);
            }
        }
        return true;
    }
    else{
        std::cerr<<"Species does not exists in the list"<<std::endl;
        return false;
    }
}

bool Manager::isSpeciesInList(string name){

    for(int i =0;i<this->species_list_size;i++){
        if(this->species_list[i].Get_name() == name){
            return true;
        }
    }
    return false;
}

void Manager::speciesAddRequest(string name, bool initial_value){
    bool res = this->addSpeciesToList(name,initial_value);
    emit speciesAddingSuccess(res,name,initial_value);
}

void Manager::speciesRemoveRequest(string name){
    bool res = this->removeSpeciesFromList(name);
    emit speciesRemovingSuccess(res,name);
}

void Manager::speciesModifyRequest(string name, bool initial_value){
    bool res = this->modifySpeciesToList(name,initial_value);
    emit speciesModifiingSuccess(res,name,initial_value);
}

//*********************************************//
//                Reaction Part                //
//*********************************************//

bool Manager::addReactionToList(Reaction *react_to_add){

    if(this->isReactionInList(react_to_add->get_reaction_name())){
        std::cerr<<"Reaction already exists in the list"<<std::endl;
        return false;
    }
    else{
        p_Reaction *new_tab = this->newTabAllocation_react(this->reaction_list_size+1);

        for(int i = 0; i<this->reaction_list_size; i++)
        {
            new_tab[i] = this->reaction_list[i];
        }
        new_tab[this->reaction_list_size] = react_to_add;
        this->reaction_list_size++;

        delete[] this->reaction_list;
        this->reaction_list = new_tab;
        return true;
    }
}

bool Manager::removeReactionFromList(string name){
    if(this->isReactionInList(name)){
        p_Reaction *new_tab= this->newTabAllocation_react(this->reaction_list_size-1);
        int j=0;
        for(int i=0;i<reaction_list_size;i++){
            if(this->reaction_list[i]->get_reaction_name() != name){
                new_tab[j]=this->reaction_list[i];
                j++;
            }
        }
        this->reaction_list_size--;
        this->reaction_list = new_tab;
        return true;
    }
    else{
        std::cerr<<"Species does not exists in the list"<<std::endl;
        return false;
    }
}

bool Manager::isReactionInList(string name){

    for(int i =0;i<this->reaction_list_size;i++){
        if(this->reaction_list[i]->get_reaction_name() == name){
            return true;
        }
    }
    return false;
}

void Manager::reactionAddRequest(QString name, int type, QStringList speciesin, QString speciesout, QStringList speciesoptional){

    switch(type){
        case CST_INHIBITION:{
            Species inhibited;
            Species inhibitor;
            for(int i=0;i<species_list_size;i++){
                if(species_list[i].Get_name() == speciesin.at(0).toStdString()){
                    inhibited = species_list[i];
                }
                if(species_list[i].Get_name() == speciesin.at(1).toStdString()){
                    inhibitor = species_list[i];
                }
            }
            Inh *tmp = new Inh("E_" + name.toStdString(),name.toStdString(),name.toStdString(),inhibited,inhibitor);
            bool res = addReactionToList(tmp);
            emit reactionAddingSuccess(res, name, CST_INHIBITION, speciesin, speciesout);
            break;
        }
        case CST_COMPLEXATION:{
                Species *tab = NULL;
                Species out;
                int tab_size = 0;
                for(int i=0;i<speciesin.size();i++){
                    for(int j=0;j<species_list_size;j++){
                        if(species_list[j].Get_name() == speciesin.at(i).toStdString()){
                            Species *new_tab = new Species[tab_size+1];
                            for(int n=0;n<tab_size;n++){
                                new_tab[n].Set_name(tab[n].Get_name());
                                new_tab[n].Set_initial_state(tab[n].Get_initial_state());
                            }
                            new_tab[tab_size] = species_list[i];
                            tab = new_tab;
                            tab_size++;
                        }
                    }
                }
                for(int j=0;j<species_list_size;j++){
                    if(species_list[j].Get_name() == speciesout.toStdString()){
                        out = species_list[j];
                        break;
                    }
                }
                Complex *tmp = new Complex("E_" + name.toStdString(),name.toStdString(),name.toStdString(),tab, speciesin.size(),out);
                bool res = addReactionToList(tmp);
                emit reactionAddingSuccess(res, name, CST_COMPLEXATION, speciesin, speciesout);
            break;
        }
        case CST_SYNTHESIS:{
                Species *tab_act = NULL;
                int tab_act_size = 0;
                for(int i=0;i<speciesin.size();i++){
                    for(int j=0;j<species_list_size;j++){
                        if(species_list[j].Get_name() == speciesin.at(i).toStdString()){
                            Species *new_tab = new Species[tab_act_size+1];
                            for(int n=0;n<tab_act_size;n++){
                                new_tab[n].Set_name(tab_act[n].Get_name());
                                new_tab[n].Set_initial_state(tab_act[n].Get_initial_state());
                            }
                            new_tab[tab_act_size] = species_list[i];
                            tab_act = new_tab;
                            tab_act_size++;
                        }
                    }
                }
                Species *tab_rep = NULL;
                int tab_rep_size = 0;
                for(int i=0;i<speciesoptional.size();i++){
                    for(int j=0;j<species_list_size;j++){
                        if(species_list[j].Get_name() == speciesoptional.at(i).toStdString()){
                            Species *new_tab_2 = new Species[tab_rep_size+1];
                            for(int n=0;n<tab_rep_size;n++){
                                new_tab_2[n].Set_name(tab_rep[n].Get_name());
                                new_tab_2[n].Set_initial_state(tab_rep[n].Get_initial_state());
                            }
                            new_tab_2[tab_rep_size] = species_list[j];
                            tab_rep = new_tab_2;
                            tab_rep_size++;
                        }
                    }
                }
                Species out;
                for(int j=0;j<species_list_size;j++){
                    if(species_list[j].Get_name() == speciesout.toStdString()){
                        out = species_list[j];
                        break;
                    }
                }
                Synth *tmp = new Synth("E_" + name.toStdString(),name.toStdString(),name.toStdString(), tab_act, tab_rep, tab_act_size, tab_rep_size, out);
                bool res = addReactionToList(tmp);
                emit reactionAddingSuccess(res, name, CST_SYNTHESIS, speciesin, speciesout, speciesoptional);
            break;
        }
    }
}

void Manager::reactionRemoveRequest(string name){
    bool res = this->removeReactionFromList(name);
    emit reactionRemovingSuccess(res,name);
}

//*********************************************//
//                System Part                  //
//*********************************************//

void Manager::systemCreationRequest(QString name, QStringList reactions){

    p_Reaction reaction_in_system_tab[reactions.size()];
    int reaction_in_system_tab_size=reactions.size();
    for(int i=0; i<reactions.size();i++){
        for(int j=0;j<reaction_list_size;j++){
            if(reaction_list[j]->get_reaction_name() == ("E_"+reactions.at(i)).toStdString()){
                reaction_in_system_tab[i] = reaction_list[j];
            }
        }
    }

    for(int i=0;i<reaction_in_system_tab_size;i++){
        reaction_in_system_tab[i]->file_creation();
    }

    patCreation(name,reactions,reaction_in_system_tab,reaction_in_system_tab_size);

    System new_system(reaction_in_system_tab,reaction_in_system_tab_size,"E_"+name.toStdString(),name.toStdString(),name.toStdString());
    bool res = new_system.test_bench_generation();
    emit systemCreationSuccess(res,name);

}

bool Manager::patCreation(QString name, QStringList reactions, p_Reaction *reaction_in_system_tab, int reaction_in_system_tab_size){

    std::ofstream w_file(("generated_files\\"+name+".pat").toStdString().c_str(), ios::out | ios::trunc);
    bool res = w_file;

    w_file<<".VHDL SET KIND=AMS"<<std::endl<<std::endl;

    for(int i=0;i<reaction_in_system_tab_size;i++){
        w_file<<".VHDL COMPILE LIBRARY=WORK SOURCE=" + reaction_in_system_tab[i]->get_file_name_user() + ".vhd"<<std::endl;
    }

    w_file<<".VHDL COMPILE LIBRARY=WORK SOURCE=" + name.toStdString() + ".vhd"<<std::endl;

    w_file<<std::endl<<".VHDL elaborate WORK.E_"+name.toStdString()<<std::endl;

    double end_time = QInputDialog::getDouble(this->ui, "End time of the simulation", "Enter in second the length of the simulation.");
    double step_time = QInputDialog::getDouble(this->ui, "Step time of the simulation", "Enter in second the step time of the simulation.");
    w_file<<".Tran " + QString::number(step_time).toStdString() + "s " + QString::number(end_time).toStdString() + "s"<<std::endl;

    return res;

}
