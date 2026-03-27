#include "Publicacao.h"
#include <iostream>

using namespace std;

// ===== Publicacao =====
Publicacao::Publicacao(Implementador* i) : imp(i) {}

void Publicacao::obterDados(string tipo) {
    imp->getDados(tipo);
}

Publicacao::~Publicacao() {}

// ===== Livro =====
Livro::Livro(Implementador* i) : Publicacao(i) {}

void Livro::getISBN() {
    cout << "ISBN do livro" << endl;
}

void Livro::getTitulo() {
    cout << "Titulo do Livro" << endl;
}

void Livro::getAutor(int id) {
    cout << "Autor do Livro ID: " << id << endl;
}

// ===== Revista =====
Revista::Revista(Implementador* i) : Publicacao(i) {}

void Revista::getArtigo() {
    cout << "Artigo da Revista" << endl;
}

void Revista::getTitulo() {
    cout << "Titulo da Revista" << endl;
}

void Revista::getAutor(int id) {
    cout << "Autor da Revista ID: " << id << endl;
}