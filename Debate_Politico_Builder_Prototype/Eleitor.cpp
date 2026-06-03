/*
#include <iostream>
#include "Eleitor.hpp"

using namespace std;

Eleitor::Eleitor(string nome) {
    this->nome = nome;
}

void Eleitor::atualizar(string msg) {
    cout << nome << " recebeu: " << msg << endl;
}


Eleitor::~Eleitor() {
}  */


#include <iostream>

#include "Eleitor.hpp"

using namespace std;

Eleitor::Eleitor(string nome):Entidade(nome) {    // inserção da classe Entidade
    
}

void Eleitor::atualizar(string msg) {
    cout
        << nome
        << " recebeu: "
        << msg
        << endl;
}

/*
 * Prototype
 */
Prototype* Eleitor::clone()
{
    return new Eleitor(*this);
}

Eleitor::~Eleitor()
{
}