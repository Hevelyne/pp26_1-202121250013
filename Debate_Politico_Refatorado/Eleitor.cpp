
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
}
