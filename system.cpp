#include "system.h"
#include "reaction.h"
#include "inh.h"
#include "bio_cst.h"

#include <string>
#include <iostream>

#define TB_ENTITY_NAME "%%TB_ENTITY_NAME%%"
#define TB_ARCHITECTURE_NAME "%%TB_ARCHITECTURE_NAME%%"
#define TB_REACTION_NAME "%%TB_REACTION_NAME%%"
#define TB_REACTION_TYPE "%%TB_REACTION_TYPE%%"
#define TB_SIGNAL_DECLARATION "%%TB_SIGNAL_DECLARATION%%"
#define TB_PORT_MAP "%%TB_PORT_MAP%%"
#define TB_MAPPING "%%TB_MAPPING%%"



using namespace std;

System::System(p_Reaction* _reaction_array, int _size_array,string testbench_entity_name, string testbench_architecture_name, string file_name)
{
    tb_entity_name = testbench_entity_name;
    tb_architecture_name = testbench_architecture_name;
    reaction_array = _reaction_array;
    size_array = _size_array;
    tb_file_name = file_name;

    species_list_generation();
    signal_declaration();
    generate_port_map();

}


System::~System()
{

}


bool System::test_bench_generation()
{

    //recherche des états initiaux de chaque espèce


    // Ecriture dans le fichier
    tb_pattern_file_name = "test_bench_pattern.txt";
    tb_file_name = tb_file_name;

    string tb_entity_code = TB_ENTITY_NAME;
    string tb_architecture_code = TB_ARCHITECTURE_NAME ;
    string tb_signal_declaration_code = TB_SIGNAL_DECLARATION;
    string tb_portmap = TB_PORT_MAP;

    string pattern_path = "pattern_files\\" + tb_pattern_file_name;
    ifstream r_file(pattern_path.c_str(), ios::in);
    tb_file_name += ".vhd";
    string path = "generated_files\\" + tb_file_name;

    ofstream w_file(path.c_str(), ios::out | ios::trunc);

    bool res = w_file;

    if (r_file && w_file)
    {
        string line;
        size_t found = string::npos;

        while (r_file)
        {
            getline(r_file, line);

//remplacement de entity name
            found = line.find(tb_entity_code);
            if (found!=string::npos)
            {
                line.erase(found,tb_entity_code.size());
                line.insert(found,tb_entity_name);
            }

// remplacement de architecture_name
            found = line.find(tb_architecture_code);
            if (found!=string::npos)
            {
                line.erase(found,tb_architecture_code.size());
                line.insert(found,tb_architecture_name);
            }

// remplacement de signals

            found = line.find(tb_signal_declaration_code);
            if (found!=string::npos)
            {
                line.erase(found,tb_signal_declaration_code.size());
                line.insert(found,signal_declaration());
            }

//remplacement mapping
            found = line.find(tb_portmap);
            if (found!=string::npos)
            {
                line.erase(found,tb_portmap.size());
                line.insert(found,generate_port_map());
            }

            w_file << line << endl;
        }

        w_file.close();
        r_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }

    return res;
}

string System::generate_port_map()
{


    p_Reaction* inh_array;
    int inh_indice = 0;
    p_Reaction* cplx_array;
    int cplx_indice = 0;
    p_Reaction* synth_array;
    int synth_indice = 0;
    int r_type;
    string r_name;


    for (int i=0; i<size_array; i++)
    {
        r_type = reaction_array[i]->get_reaction_type();
        r_name = reaction_array[i]->get_reaction_name();

        if (r_type == 0) // Inhibition
        {
            p_Reaction* new_tab;
            new_tab = new p_Reaction[inh_indice+1];

            for(int m=0; m<inh_indice; m++)
            {
                new_tab[m]=inh_array[m];
            }
            new_tab[inh_indice] = reaction_array[i];
            inh_array = new_tab;
            inh_indice++;
        }

        if ( r_type == 1) // Complexation
        {
            p_Reaction* new_tab;
            new_tab = new p_Reaction[cplx_indice+1];
            for(int m=0; m<cplx_indice; m++)
            {
                new_tab[m]=inh_array[m];
            }
            new_tab[cplx_indice] = reaction_array[i];
            cplx_array = new_tab;
            cplx_indice++;

        }

        if ( r_type == 2) // Synthesis
        {
            p_Reaction* new_tab;
            new_tab = new p_Reaction[synth_indice+1];
            for(int m=0; m<synth_indice; m++)
            {
                new_tab[m]=synth_array[m];
            }
            new_tab[synth_indice] = reaction_array[i];
            synth_array = new_tab;
            synth_indice++;
        }
    }


//Lecture du fichier de base pour générer le port map

    string p_map_pattern = "port_map_pattern.txt";
    string pattern_path = "pattern_files\\" + p_map_pattern;
    ifstream r_file(pattern_path.c_str(), ios::in);

    string mapping_string="";

    if(r_file)
    {
        while(r_file)
        {
            string buffer;
            getline(r_file, buffer);
            mapping_string += buffer;
        }
        r_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


    string tb_reaction_name_code = TB_REACTION_NAME;
    string tb_reaction_mapping = TB_MAPPING;
    string tb_entity_name_code = TB_ENTITY_NAME;


    string entities_mapping[size_array];
    string output_signal;
    int n = 0;

    for(int i=0;i<inh_indice;i++){
        entities_mapping[n]=mapping_string;
        size_t found = string::npos;
        do{
            found = entities_mapping[n].find(tb_reaction_name_code);
            if(found!=string::npos)
            {
                entities_mapping[n].erase(found,tb_reaction_name_code.size());
                entities_mapping[n].insert(found,inh_array[i]->get_reaction_name());
            }
        }while(found!=string::npos);

        found = string::npos;
        found = entities_mapping[n].find(tb_entity_name_code);
        if(found!=string::npos)
        {
            entities_mapping[n].erase(found,tb_entity_name_code.size());
            entities_mapping[n].insert(found,inh_array[i]->get_entity_name_user());
        }

        found = string::npos;
        found = entities_mapping[n].find(tb_reaction_mapping);
        if(found!=string::npos)
        {
            entities_mapping[n].erase(found,tb_reaction_mapping.size());

            string tmp="\n";
            const Species* species_in_reaction = inh_array[i]->get_input_species();
            for(int j=0;j<inh_array[i]->get_nb_input_species();j++){
                tmp += "\t\t\t\t" + species_in_reaction[j].Get_name() + " => ";

                for(int x=0;x<species_list_size;x++){
                    if(species_in_reaction[j].Get_name() == species_list[x].name_sp){
                        tmp += species_list[x].signal;
                        tmp += ",";
                        break;
                    }
                }
                tmp += "\n";
            }
            tmp += "\t\t\t\tS => ";
            for(int x=0;x<species_list_size;x++){
                    if(inh_array[i]->get_output_species().Get_name() == species_list[x].name_sp){
                        tmp += species_list[x].signal;
                        output_signal = species_list[x].signal;
                        break;
                    }
            }
            entities_mapping[n].insert(found,tmp);
        }
        Inh* stat = static_cast<Inh*>(inh_array[i]);

        for(int x=0;x<species_list_size;x++){
                    if(stat->get_main_species().Get_name() == species_list[x].name_sp){
                        species_list[x].signal = output_signal;
                        break;
                    }
        }


        n++;
    }

    for(int i=0;i<cplx_indice;i++){
        entities_mapping[n]=mapping_string;
        size_t found = string::npos;
        do{
            found = entities_mapping[n].find(tb_reaction_name_code);
            if(found!=string::npos)
            {
                entities_mapping[n].erase(found,tb_reaction_name_code.size());
                entities_mapping[n].insert(found,cplx_array[i]->get_reaction_name());
            }
        }while(found!=string::npos);

        found = string::npos;
        found = entities_mapping[n].find(tb_entity_name_code);
        if(found!=string::npos)
        {
            entities_mapping[n].erase(found,tb_entity_name_code.size());
            entities_mapping[n].insert(found,cplx_array[i]->get_entity_name_user());
        }

        found = string::npos;
        found = entities_mapping[n].find(tb_reaction_mapping);
        if(found!=string::npos)
        {
            entities_mapping[n].erase(found,tb_reaction_mapping.size());
            string tmp="\n";
            const Species* species_in_reaction = cplx_array[i]->get_input_species();
            for(int j=0;j<cplx_array[i]->get_nb_input_species();j++){
                tmp += "\t\t\t\t" + species_in_reaction[j].Get_name() + " => ";

                for(int x=0;x<species_list_size;x++){
                    if(species_in_reaction[j].Get_name() == species_list[x].name_sp){
                        tmp += species_list[x].signal;
                        tmp += ",";
                        break;
                    }
                }
                tmp += "\n";
            }
            tmp += "\t\t\t\tS => ";
            //            tmp += "\t\t\t\t" + cplx_array[i]->get_output_species().Get_name() + " => ";
            for(int x=0;x<species_list_size;x++){
                    if(cplx_array[i]->get_output_species().Get_name() == species_list[x].name_sp){
                        tmp += species_list[x].signal;
                        break;
                    }
            }
            entities_mapping[n].insert(found,tmp);
        }

        n++;
    }

    for(int i=0;i<synth_indice;i++){
        entities_mapping[n]=mapping_string;
        size_t found = string::npos;
        do{
            found = entities_mapping[n].find(tb_reaction_name_code);
            if(found!=string::npos)
            {
                entities_mapping[n].erase(found,tb_reaction_name_code.size());
                entities_mapping[n].insert(found,synth_array[i]->get_reaction_name());
            }
        }while(found!=string::npos);

        found = string::npos;
        found = entities_mapping[n].find(tb_entity_name_code);
        if(found!=string::npos)
        {
            entities_mapping[n].erase(found,tb_entity_name_code.size());
            entities_mapping[n].insert(found,synth_array[i]->get_entity_name_user());
        }

        found = string::npos;
        found = entities_mapping[n].find(tb_reaction_mapping);
        if(found!=string::npos)
        {
            entities_mapping[n].erase(found,tb_reaction_mapping.size());
            string tmp="\n";
            const Species* species_in_reaction = synth_array[i]->get_input_species();
            for(int j=0;j<synth_array[i]->get_nb_input_species();j++){
                tmp += "\t\t\t\t" + species_in_reaction[j].Get_name() + " => ";

                for(int x=0;x<species_list_size;x++){
                    if(species_in_reaction[j].Get_name() == species_list[x].name_sp){
                        tmp += species_list[x].signal;
                        tmp += ",";
                        break;
                    }
                }
                tmp += "\n";
            }
            tmp += "\t\t\t\t" + synth_array[i]->get_output_species().Get_name() + " => ";
            for(int x=0;x<species_list_size;x++){
                    if(synth_array[i]->get_output_species().Get_name() == species_list[x].name_sp){
                        tmp += species_list[x].signal;
                        break;
                    }
            }
            entities_mapping[n].insert(found,tmp);
        }

        n++;
    }

    string res="";
    for(int i=0;i<size_array;i++){
        res += entities_mapping[i]+"\n";
    }

    return res;

}


string System::signal_declaration()
{

    // Association d'un signal pour chaque espèce et création de 2 tableaux, un contenant les signaux a l'état haut, l'autre les signaux a l'état bas
    string* high_states;
    string* low_states;
    int high_indice = 0;
    int low_indice = 0;

    for (int n=0; n<species_list_size; n++)
    {
        species_list[n].signal = "s_" + species_list[n].name_sp;

        if (species_list[n].state_sp == true)
        {
            string* new_tab;
            new_tab = new string[high_indice+1];

            for(int m=0; m<high_indice; m++)
            {
                new_tab[m]=high_states[m];
            }

            new_tab[high_indice] = species_list[n].signal;
            high_states = new_tab;
            high_indice++;
        }

        else
        {
            string* new_tab;
            new_tab = new string[low_indice+1];

            for(int m=0; m<low_indice; m++)
            {
                new_tab[m]=low_states[m];
            }
            new_tab[low_indice] = species_list[n].signal;
            low_states = new_tab;
            low_indice++;
        }
    }

    string l_s_i="";
    if (low_indice!=0)
    {
        l_s_i += "SIGNAL ";
        l_s_i +=  low_states[0];

        if (low_indice > 2 )
        {
            for (int n=1; n<low_indice; n++)
            {
                l_s_i += "," + low_states[n];
            }
        }
        l_s_i += ": STD_LOGIC := '0';";
    }


    string h_s_i = "";

    if(high_indice !=0)
    {
        h_s_i += "SIGNAL ";
        h_s_i +=  high_states[0];

        if (high_indice > 2 )
        {
            for (int n=1; n<high_indice; n++)
            {
                h_s_i += "," + high_states[n];
            }
        }
        h_s_i += ": STD_LOGIC := '1';";
    }


     string sig = l_s_i + "\n" + h_s_i;

     return sig;

}
void System::species_list_generation(){

// Extraction des espèces dans un tableau et élimination des doublons

    species_list_size = 0;
    bool isin;

    for (int i=0; i<size_array; i++) // pour toutes les réactions
    {
        const Species* Sp_tab_test;
        Sp_tab_test = reaction_array[i]->get_input_species();

        for (int j=0; j<(reaction_array[i]->get_nb_input_species()); j++) //Pour toutes les espèces
        {
            isin = false;
            for (int n=0; n<species_list_size; n++)
            {
                if (species_list[n].name_sp==Sp_tab_test[j].Get_name())
                {
                    isin=true;
                }
            }

            if (!isin)
            {
                list_sig* new_tab;
                new_tab = new list_sig[species_list_size+1];
                for(int n=0; n<species_list_size; n++)
                {
                    new_tab[n]=species_list[n];
                }

                new_tab[species_list_size].name_sp = Sp_tab_test[j].Get_name();
                new_tab[species_list_size].state_sp = Sp_tab_test[j].Get_initial_state();

                species_list=new_tab;
                species_list_size++;
            }
        }


        isin = false;
        Species Sp_tempo;

        Sp_tempo = reaction_array[i]->get_output_species();

        for (int n=0; n<species_list_size; n++)
        {
            if (species_list[n].name_sp==Sp_tempo.Get_name())
            {
                isin=true;
            }
        }
        if (!isin)
        {
            list_sig* new_tab;
            new_tab = new list_sig[species_list_size+1];
            for(int n=0; n<species_list_size; n++)
            {
                new_tab[n]=species_list[n];
            }
            new_tab[species_list_size].name_sp = Sp_tempo.Get_name();
            new_tab[species_list_size].state_sp = Sp_tempo.Get_initial_state();
            species_list=new_tab;
            species_list_size ++;
        }
    }

}
