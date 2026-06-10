#include <iostream>

#include "Eleitor.hpp"

using namespace std;

Eleitor::Eleitor(
    string nome
)
:
Entidade(nome)
{
}

void Eleitor::atualizar(
    string mensagem
)
{
    cout
        << "[ELEITOR] "
        << nome
        << " recebeu: "
        << mensagem
        << endl;
}

Prototype* Eleitor::clone()
{
    return new Eleitor(*this);
}

Eleitor::~Eleitor()
{
}