#include "Implementador.h"
#include <iostream>

using namespace std;

void PublicacaoImplBD::getDados(string tipo) {
    cout << "[BD] Buscando dados do tipo: " << tipo << endl;
}

void PublicacaoImplXML::getDados(string tipo) {
    cout << "[XML] Buscando dados do tipo: " << tipo << endl;
}