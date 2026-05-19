#include "FachadaDebate.hpp"

FachadaDebate*
FachadaDebate::instance = nullptr;

FachadaDebate::FachadaDebate() {

    log =
        LogSistem::get_instance(
            "logs.txt"
        );
}

FachadaDebate*
FachadaDebate::get_instance() {

    if(instance == nullptr) {

        instance =
            new FachadaDebate();
    }

    return instance;
}

void FachadaDebate::configuracao(
    int pergunta,
    int resposta,
    int replica,
    int treplica
) {

    config.set_temp_pergunta(pergunta);

    config.set_temp_resposta(resposta);

    config.set_temp_replica(replica);

    config.set_temp_treplica(treplica);
}

void FachadaDebate::executar_debate(
    Inquiridor* iq,
    Inquirido* id
) {

    mediador.set_inquiridor(iq);

    mediador.set_inquirido(id);

    mediador.debate(
        &config,
        log
    );
}
