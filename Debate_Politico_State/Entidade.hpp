#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include <string>

#include "Prototype.hpp"

using namespace std;

class Entidade :
    public Prototype
{
protected:

    string nome;

public:

    Entidade(
        string nome
    );

    string get_nome();

    virtual ~Entidade() = default;
};

#endif