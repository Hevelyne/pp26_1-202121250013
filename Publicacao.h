#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include "Implementador.h"
#include <string>

// Abstração
class Publicacao {
protected:
    Implementador* imp;

public:
    Publicacao(Implementador* i);

    virtual void obterDados(std::string tipo);
    virtual void getTitulo() = 0;
    virtual void getAutor(int id) = 0;

    virtual ~Publicacao();
};

// Livro
class Livro : public Publicacao {
public:
    Livro(Implementador* i);

    void getISBN();
    void getTitulo() override;
    void getAutor(int id) override;
};

// Revista
class Revista : public Publicacao {
public:
    Revista(Implementador* i);

    void getArtigo();
    void getTitulo() override;
    void getAutor(int id) override;
};

#endif