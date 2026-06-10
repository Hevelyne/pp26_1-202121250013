#ifndef COLABORADORPOLITICO_HPP
#define COLABORADORPOLITICO_HPP

#include <iostream>
#include <vector>

#include "Entidade.hpp"
#include "Observer.hpp"
#include "Microfone.hpp"
#include "MediadorBase.hpp"
#include "LogSistem.hpp"   
#include "Prototype.hpp"  

using namespace std;

class ColaboradorPolitico :
    public Entidade
{
protected:

    string partido;
    string cargo;
    string estado;
    int numeroEleitoral;

    bool solicitouDR;

    Microfone microfone;
    MediadorBase* mediador;

    vector<Observer*> eleitores;

public:

    ColaboradorPolitico(
        string nome,
        string partido,
        string cargo,
        string estado,
        int numeroEleitoral
    );

    string get_partido();
    string get_cargo();
    string get_estado();
    int get_numero_eleitoral();

    void set_mediador(MediadorBase* m);

    /*
     * Observer
     */
    void anexar_eleitor(Observer* obs);
    void remover_eleitor(Observer* obs);
    void notificar_eleitores(string msg);

    /*
     * Fluxo normal (STATE)
     */
    virtual void falar(
        string etapa,
        int tempo,
        LogSistem* log
    );

    /*
     * Direito de Resposta
     */
    void apertar_botao_DR();
    bool possui_DR();
    void limpar_DR();

    virtual void executar_direito_resposta(
        int tempo,
        LogSistem* log
    );

    /*
     * Prototype 
     */
    Prototype* clone() override;

    virtual ~ColaboradorPolitico();
};

#endif