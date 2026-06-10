#ifndef ELEITORBUILDER_HPP
#define ELEITORBUILDER_HPP

#include "Eleitor.hpp"

class EleitorBuilder
{
private:

    string nome;

public:

    EleitorBuilder&
    set_nome(
        string nome
    );

    Eleitor*
    build();
};

#endif