
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

#endif
