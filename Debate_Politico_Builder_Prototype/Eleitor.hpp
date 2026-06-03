/*
#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include <string>
#include "Observer.hpp"

using namespace std;

class Eleitor : public Observer {
private:
    string nome;

public:
    Eleitor(string nome);

    void atualizar(string msg) override;

    virtual ~Eleitor();
};

#endif */


#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include <string>

#include "Observer.hpp"
#include "Entidade.hpp"

using namespace std;

class Eleitor :
    public Observer,
    public Entidade  // refatoramento verão 2 com BUILDER e PROTOTYPE
{

public:

    Eleitor(string nome);

    void atualizar(string msg) override;

    /*
     * Prototype
     */
    Prototype* clone() override;

    virtual ~Eleitor();
};

#endif
