#include "EleitorBuilder.hpp"

EleitorBuilder&
EleitorBuilder::set_nome(
    string nome
)
{
    this->nome = nome;

    return *this;
}

Eleitor*
EleitorBuilder::build()
{
    return new Eleitor(nome);
}