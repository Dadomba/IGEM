#ifndef REACTION_H
#define REACTION_H

#include "Species.h"
#include <string>


class Reaction
{
public:
    // Constructeur
    Reaction();

    // Destructeur
    virtual ~Reaction();

    // Méthodes
    bool file_creation();
    string get_reaction_name();
    Species get_output_species();
    int get_nb_input_species();
    const Species* get_input_species() const;

    int get_reaction_type();
    void set_reaction_type(int new_type);

    string get_file_name_user();
    void set_file_name_user(string str);

    string get_entity_name_user();
    void set_entity_name_user(string str);

protected:

    // Attributs
    string reaction_name;
    string pattern_file_name;
    string file_name_user;
    string entity_name_user;
    Species out;
    Species* in;
    int nb_in;
    int reaction_type;

    // Méthodes virtuelles
    virtual const string log_eq() const = 0 ;
    virtual const string portmap() const = 0 ;

private:
};

#endif // REACTION_H
