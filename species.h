#ifndef SPECIES_H
#define SPECIES_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Header file for Species class allowing to create and modify name and/or state of a species.

//! \brief Species class allowing to create and modify name and/or state of a species.

class Species
{
private:
    string name;			/*!< Name of a species */
    bool initial_state;		/*!< State of a species */

public:

    /*!
    \brief Species creation by default creator

    \param state : species state, activated or deactivated
    */
    Species(bool state = 0);

	/*!
    \brief Species creation by giving a name

    \param name_s : species name
	\param state : species state
    */
    Species(string name_s, bool state = 0);

	/*!
    \brief Species creation by giving a name (second)

    \param name_s : species name (with different parameter type than the last method)
	\param state : species state
    */
    Species(const char* name_s, bool state = 0);

	/*!
    \brief Return the species name
    */
    const string Get_name() const;

	/*!
    \brief Modify the species name

    \param name_s : to change species name
    */
    void Set_name(string name_s);

	/*!
    \brief Return the initial state of the species
    */
    const bool Get_initial_state() const;

	/*!
    \brief Modify the initial state of the species

    \param state : to change species state
    */
    void Set_initial_state(bool state);



protected:

};

#endif // SPECIES_H
