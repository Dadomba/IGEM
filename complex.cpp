#include "Complex.h"

Complex::Complex(string name_device,string generated_entity_name, string generated_file_name, Species* input_species, int number_in_species, Species output_species)
{
    pattern_file_name = "complex_pattern.txt";
    reaction_name = name_device;
    reaction_type = CST_COMPLEXATION;
    entity_name_user = generated_entity_name;
    file_name_user = generated_file_name;
    nb_in = number_in_species;
    in = new Species[nb_in];

    for(int i=0; i<nb_in; i++)
    {
        in[i] = input_species[i];
    }

    out = output_species;


}


Complex::~Complex()
{
    //dtor
}

const Species* Complex::get_input_species() const
{
    return this -> in;
}

const int Complex::get_number_in_species() const
{
    return this-> nb_in;
}

const string Complex::portmap() const
{
    string str="";



    for(int i =0; i<nb_in; i++)
    {

        str+= ("\t\t" + in[i].Get_name() + " : IN  STD_LOGIC;\n");
    }

    str += "\t\tS : OUT STD_LOGIC";


    return str;


}

const string Complex::log_eq() const
{
    string str="";

    str += "S <= (";
    for(int i =0; i<nb_in-1; i++)
    {
        str += (in[i].Get_name() + " AND ");
    }
    str += (in[nb_in-1].Get_name() + ");\n");

    return str;

}
