#ifndef BIO_CST_H
#define BIO_CST_H
#include "reaction.h"

typedef Reaction* p_Reaction;

typedef struct list_sig
    {
        string name_sp;
        bool state_sp;
        string signal;
    }list_sig;

#define CST_INHIBITION 0
#define CST_COMPLEXATION 1
#define CST_SYNTHESIS 2


#endif // BIO_CST_H
