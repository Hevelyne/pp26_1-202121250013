#ifndef COLABORADORPOLITICO_HPP
#define COLABORADORPOLITICO_HPP

#include <iostream>
#include <vector>

#include "Observer.hpp"
#include "Microfone.hpp"
#include "MediadorBase.hpp"

using namespace std;

class ColaboradorPolitico {

protected:

    string nome;
    string partido;

    bool inquiridor;

    Microfone microfone;

    MediadorBase* mediador;

    vector<Observer*> eleitores;

public:

    ColaboradorPolitico(
        string nome,
        string partido
    );

    string get_nome();

    string get_partido();

    void set_mediador(MediadorBase* m);

    void set_inquiridor(bool b);

    bool get_inquiridor();

    void anexar_eleitor(Observer* obs);

    void remover_eleitor(Observer* obs);

    void notificar_eleitores(string msg);

    virtual void perguntar(
        int tempo,
        LogSistem* log
    );

    virtual void responder(
        int tempo,
        LogSistem* log
    );

    virtual void replica(
        int tempo,
        LogSistem* log
    );

    virtual void treplica(
        int tempo,
        LogSistem* log
    );
};

#endif
