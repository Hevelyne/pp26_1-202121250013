/*#include "ColaboradorPolitico.hpp"

ColaboradorPolitico::ColaboradorPolitico(
    string nome,
    string partido
) {

    this->nome = nome;
    this->partido = partido;

    inquiridor = false;
}

string ColaboradorPolitico::get_nome() {

    return nome;
}

string ColaboradorPolitico::get_partido() {

    return partido;
}

void ColaboradorPolitico::set_mediador(
    MediadorBase* m
) {

    mediador = m;
}

void ColaboradorPolitico::set_inquiridor(
    bool b
) {

    inquiridor = b;
}

bool ColaboradorPolitico::get_inquiridor() {

    return inquiridor;
}

void ColaboradorPolitico::anexar_eleitor(
    Observer* obs
) {

    eleitores.push_back(obs);
}

void ColaboradorPolitico::remover_eleitor(
    Observer* obs
) {

    for(int i = 0; i < eleitores.size(); i++) {

        if(eleitores[i] == obs) {

            eleitores.erase(
                eleitores.begin() + i
            );

            break;
        }
    }
}

void ColaboradorPolitico::notificar_eleitores(
    string msg
) {

    for(auto eleitor : eleitores) {

        eleitor->atualizar(msg);
    }
}

void ColaboradorPolitico::perguntar(
    int tempo,
    LogSistem* log
) {}

void ColaboradorPolitico::responder(
    int tempo,
    LogSistem* log
) {}

void ColaboradorPolitico::replica(
    int tempo,
    LogSistem* log
) {}

void ColaboradorPolitico::treplica(
    int tempo,
    LogSistem* log
) {}   */



#include "ColaboradorPolitico.hpp"

ColaboradorPolitico::ColaboradorPolitico(
    string nome,
    string partido,
    string cargo,
    string estado,
    int numeroEleitoral):Entidade(nome) {
        
    this->partido = partido;
    this->cargo = cargo;
    this->estado = estado;
    this->numeroEleitoral = numeroEleitoral;

    inquiridor = false;

    mediador = nullptr;
}

string ColaboradorPolitico::get_partido()
{
    return partido;
}

string ColaboradorPolitico::get_cargo()
{
    return cargo;
}

string ColaboradorPolitico::get_estado()
{
    return estado;
}

int ColaboradorPolitico::get_numero_eleitoral()
{
    return numeroEleitoral;
}

void ColaboradorPolitico::set_mediador(MediadorBase* m) {
    
    mediador = m;
}

void ColaboradorPolitico::set_inquiridor(bool b) {
    
    inquiridor = b;
}

bool ColaboradorPolitico::get_inquiridor()
{
    return inquiridor;
}

void ColaboradorPolitico::anexar_eleitor(Observer* obs) {
    
    eleitores.push_back(obs);
}

void ColaboradorPolitico::remover_eleitor(Observer* obs) {
    
    for(int i = 0; i < eleitores.size(); i++)
    {
        if(eleitores[i] == obs)
        {
            eleitores.erase(eleitores.begin() + i);

            break;
        }
    }
}

void ColaboradorPolitico::notificar_eleitores(string msg) {
    
    for(auto eleitor : eleitores)
    {
        eleitor->atualizar(msg);
    }
}

void ColaboradorPolitico::perguntar(int tempo, LogSistem* log) {
    
}

void ColaboradorPolitico::responder(int tempo, LogSistem* log) {
    
}

void ColaboradorPolitico::replica(int tempo, LogSistem* log) {
    
}

void ColaboradorPolitico::treplica(int tempo, LogSistem* log) {
    
}