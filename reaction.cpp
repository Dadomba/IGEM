#include "Reaction.h"

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <WinBase.h>

#define ENTITY_NAME "%%ENTITY_NAME%%"
#define PORT_DECLARATION "%%PORT_DECLARATION%%"
#define LOGICAL_EQUATION "%%LOGICAL_EQUATION%%"

Reaction::Reaction()
{
    //ctor
}

Reaction::~Reaction()
{
    //dtor
}

string Reaction::get_file_name_user()
{
    return file_name_user;
}

void Reaction::set_file_name_user(string str)
{
    file_name_user = str;
}

string Reaction::get_entity_name_user()
{
    return entity_name_user;
}

void Reaction::set_entity_name_user(string str)
{
    entity_name_user = str;
}

string Reaction::get_reaction_name()
{
    return reaction_name;
}

Species Reaction::get_output_species()
{
    return out;
}

int Reaction::get_nb_input_species()
{
    return nb_in;
}

const Species* Reaction::get_input_species() const
{
   return this->in;
}

int Reaction::get_reaction_type()
{
    return reaction_type;
}


void Reaction::set_reaction_type(int new_type)
{
  reaction_type = new_type;
}


bool Reaction::file_creation()
{

    string entity_code = ENTITY_NAME;
    string port_code = PORT_DECLARATION;
    string equ_code = LOGICAL_EQUATION;


    string pattern_path = "pattern_files\\" + pattern_file_name;
    ifstream r_file(pattern_path.c_str(), ios::in);
    //file_name_user += ".vhd";
    string path = "generated_files\\" + file_name_user + ".vhd";

    ofstream w_file(path.c_str(), ios::out | ios::trunc);
    bool res = w_file;

    if(r_file && w_file)
    {
        string line;
        size_t found = string::npos;

        while(r_file)
        {
            getline(r_file, line);

            found = line.find(entity_code);
            if(found!=string::npos)
            {
                line.erase(found,entity_code.size());
                line.insert(found,entity_name_user);
            }

            found = line.find(port_code);
            if(found!=string::npos)
            {
                line.erase(found,port_code.size());
                line.insert(found,portmap());
            }


            found = line.find(equ_code);
            if(found!=string::npos)
            {
                line.erase(found,equ_code.size());



                line.insert(found,log_eq());
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



