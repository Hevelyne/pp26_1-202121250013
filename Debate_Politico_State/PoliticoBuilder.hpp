#ifndef POLITICOBUILDER_HPP
#define POLITICOBUILDER_HPP

#include "ColaboradorPolitico.hpp"

class PoliticoBuilder
{
private:

    string nome;

    string partido;

    string cargo;

    string estado;

    int numeroEleitoral;

public:

    PoliticoBuilder&
    set_nome(
        string nome
    );

    PoliticoBuilder&
    set_partido(
        string partido
    );

    PoliticoBuilder&
    set_cargo(
        string cargo
    );

    PoliticoBuilder&
    set_estado(
        string estado
    );

    PoliticoBuilder&
    set_numero(
        int numero
    );

    ColaboradorPolitico*
    build();
};

#endif