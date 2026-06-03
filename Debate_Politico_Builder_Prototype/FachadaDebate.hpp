#ifndef FACHADADEBATE_HPP
#define FACHADADEBATE_HPP

#include "MediarDebate.hpp"

class FachadaDebate {

private:

    static FachadaDebate* instance;

    ConfiguraTempo config;

    MediarDebate mediador;

    LogSistem* log;

    FachadaDebate();

public:

    static FachadaDebate* get_instance();

    void configuracao(
        int pergunta,
        int resposta,
        int replica,
        int treplica
    );

    void executar_debate(
        Inquiridor* iq,
        Inquirido* id
    );
};

#endif