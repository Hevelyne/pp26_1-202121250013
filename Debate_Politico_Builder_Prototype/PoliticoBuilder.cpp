#include "PoliticoBuilder.hpp"

PoliticoBuilder&
PoliticoBuilder::set_nome(
    string nome
)
{
    this->nome = nome;

    return *this;
}

PoliticoBuilder&
PoliticoBuilder::set_partido(
    string partido
)
{
    this->partido = partido;

    return *this;
}

PoliticoBuilder&
PoliticoBuilder::set_cargo(
    string cargo
)
{
    this->cargo = cargo;

    return *this;
}

PoliticoBuilder&
PoliticoBuilder::set_estado(
    string estado
)
{
    this->estado = estado;

    return *this;
}

PoliticoBuilder&
PoliticoBuilder::set_numero(
    int numero
)
{
    this->numeroEleitoral =
        numero;

    return *this;
}

Inquiridor*
PoliticoBuilder::build_inquiridor()
{
    return new Inquiridor(
        nome,
        partido,
        cargo,
        estado,
        numeroEleitoral
    );
}

Inquirido*
PoliticoBuilder::build_inquirido()
{
    return new Inquirido(
        nome,
        partido,
        cargo,
        estado,
        numeroEleitoral
    );
}