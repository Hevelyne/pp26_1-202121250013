#include "Publicacao.h"
#include "Implementador.h"
#include <iostream>

using namespace std;

int main() {
    Implementador* impl1 = new PublicacaoImplBD();
    Implementador* impl2 = new PublicacaoImplXML();

    Publicacao* livro = new Livro(impl1);
    livro->obterDados("Livro");
    livro->getTitulo();
    livro->getAutor(1);

    cout << "---------------------" << endl;

    Publicacao* revista = new Revista(impl2);
    revista->obterDados("Revista");
    revista->getTitulo();
    revista->getAutor(2);

    delete livro;
    delete revista;
    delete impl1;
    delete impl2;

    return 0;
}