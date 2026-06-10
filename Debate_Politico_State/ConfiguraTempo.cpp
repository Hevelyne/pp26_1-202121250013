#include "ConfiguraTempo.hpp"

void ConfiguraTempo::set_temp_pergunta(
    int t
)
{
    pergunta = t;
}

int ConfiguraTempo::get_temp_pergunta()
{
    return pergunta;
}

void ConfiguraTempo::set_temp_resposta(
    int t
)
{
    resposta = t;
}

int ConfiguraTempo::get_temp_resposta()
{
    return resposta;
}

void ConfiguraTempo::set_temp_replica(
    int t
)
{
    replica = t;
}

int ConfiguraTempo::get_temp_replica()
{
    return replica;
}

void ConfiguraTempo::set_temp_treplica(
    int t
)
{
    treplica = t;
}

int ConfiguraTempo::get_temp_treplica()
{
    return treplica;
}

void ConfiguraTempo::set_temp_DR(
    int t
)
{
    direitoResposta = t;
}

int ConfiguraTempo::get_temp_DR()
{
    return direitoResposta;
}