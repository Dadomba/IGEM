#ifndef SYNTH_H
#define SYNTH_H

#include "Reaction.h"
#include "bio_cst.h"
#include<VECTOR>

/*! \brief Synth class used to create a syhthesis device.
                       inherits from the Reaction class*/

class Synth : public Reaction
{
public:

    /*!
    \brief Synth constructor

    \param name_device : name of the device (string)
    \param generated_entity_name : name of the generated entity on the VHDL file (string)
    \param generated_file_name : name of the VHDL file generated (string)
    \param activators : array of Species which contains activators inputs for this synthesis
    \param repressors : array of Species which contains repressors inputs for this synthesis
    \param size_act : number of activators of the activators array
    \param size_rep : number of activators of the repressors array
    */

    Synth(string name_device,string generated_entity_name, string generated_file_name, Species* activators, Species* repressors, int size_Act, int size_Rep, Species output_species);



    /*!
    \brief Synth default destructor
    */
    virtual ~Synth();


    /*!
    \brief Method which gives all the activators Species of this synthesis
    \return returns an array of Species which contains all the activators of this synthesis
    */
    const Species* get_act_species() const;

    /*!
    \brief Method which gives all the repressors Species of this synthesis
    \return returns an array of Species which contains all the repressors of this synthesis
    */
    const Species* get_rep_species() const;


protected:

    /*!
    \brief Method which calculates the logical equation for the VHDL-File linked with the synthesis
    \return returns a string which contains the logical equation linked with this synthesis
    */
    const string log_eq() const;


    /*!
    \brief Method which calculates the port mapping for the VHDL-file linked with the synthesis
    \return returns a string which the port mapping of this synthesis
    */
    const string portmap() const;



private:
    /*!
    \brief int attribute which contains the number of activators of this synthesis
    */
    int nb_Act;

    /*!
    \brief int attribute which contains the number of repressors of this synthesis
    */
    int nb_Rep;

        /*!
    \brief "array of Species" attribute which contains all the activators of this synthesis
    */
    Species* Act;

        /*!
    \brief "array of Species" attribute which contains all the repressors of this synthesis
    */
    Species* Rep;
};

#endif // SYNTH_H
