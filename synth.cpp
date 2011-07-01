#include "Synth.h"

using namespace std;

Synth::Synth(string name_device,string generated_entity_name, string generated_file_name, Species* activators, Species* repressors,int size_Act, int size_Rep, Species output_species)
{
    pattern_file_name = "synth_pattern.txt";
    reaction_name = name_device;
    reaction_type = CST_SYNTHESIS;
    entity_name_user = generated_entity_name;
    file_name_user = generated_file_name;

    nb_Act = size_Act;
    nb_Rep = size_Rep;

    nb_in = nb_Act + nb_Rep;

    Act = new Species[size_Act];

    for(int i=0; i<size_Act; i++)

    {
        Act[i] = activators[i];
    }


    Rep = new Species[size_Rep];

    for(int i=0; i<size_Rep; i++)
    {
        Rep[i] = repressors[i];
    }

    in = new Species[nb_in];

        for(int i=0; i<size_Act; i++)
    {
        in[i] = Act[i];
    }

         for(int i=0; i<size_Rep; i++)
    {
        in[i+(size_Act)] = Rep[i];
    }

    out = output_species;
}

Synth::~Synth()
{
    //dtor
}

const Species* Synth::get_act_species() const
{
    return this -> Act;
}

const Species* Synth::get_rep_species() const
{
    return this -> Rep;
}

const string Synth::log_eq() const
{

    string str="";

    str += (out.Get_name() + " <= (");

    for(int i =0; i<nb_Act-1; i++)
    {

        str += (Act[i].Get_name() + " OR ");
    }
    str += (Act[nb_Act-1].Get_name() + ") AND ( ");


    for(int i =0; i<nb_Rep-1; i++)
    {
        str+= ("NOT(" + Rep[i].Get_name() + ") AND ");
    }
    str += ("NOT(" + Rep[nb_Rep-1].Get_name() + ") );\n");

    return str;
}


const string Synth::portmap() const
{

    string str="";

    for(int i =0; i<nb_Act; i++)
    {
        str+= ("\t\t" + Act[i].Get_name() + " : IN  STD_LOGIC;\n");
    }

    for(int i =0; i<nb_Rep; i++)
    {
        str+= ("\t\t" + Rep[i].Get_name() + " : IN  STD_LOGIC;\n");
    }

    str += ("\t\t" + out.Get_name() + " : OUT STD_LOGIC");


    return str;
}
