#include "Entidade.hpp"

Entidade::Entidade(
    string nome
)
{
    this->nome = nome;
}

string Entidade::get_nome()
{
    return nome;
}