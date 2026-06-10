#include "FachadaDebate.hpp"


#include "LogSistem.hpp"


FachadaDebate*
FachadaDebate::instance =
nullptr;

FachadaDebate::
FachadaDebate()
{
    log =
        LogSistem::get_instance(
            "logs.txt"
        );
}


FachadaDebate*
FachadaDebate::
get_instance()
{
    if(instance == nullptr)
    {
        instance =
            new FachadaDebate();
    }

    return instance;
}


void FachadaDebate::
configuracao(
    int pergunta,
    int resposta,
    int replica,
    int treplica,
    int direitoResposta,
    int rodadas
)
{
    config.set_temp_pergunta(
        pergunta
    );

    config.set_temp_resposta(
        resposta
    );

    config.set_temp_replica(
        replica
    );

    config.set_temp_treplica(
        treplica
    );

    config.set_temp_DR(
        direitoResposta
    );

    mediador.set_max_rodadas(
        rodadas
    );
}

void FachadaDebate::
adicionar_participante(
    ColaboradorPolitico* p
)
{
    mediador
        .adicionar_participante(p);
}

void FachadaDebate::
executar_debate()
{
    mediador.debate(
        &config,
        log
    );
}