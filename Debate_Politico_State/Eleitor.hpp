#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include <string>

#include "Observer.hpp"
#include "Entidade.hpp"

using namespace std;

class Eleitor :
    public Observer,
    public Entidade
{
public:

    Eleitor(
        string nome
    );

    void atualizar(
        string mensagem
    ) override;

    Prototype* clone() override;

    virtual ~Eleitor();
};

#endif