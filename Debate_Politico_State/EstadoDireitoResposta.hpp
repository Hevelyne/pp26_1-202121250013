#ifndef ESTADODIREITORESPOSTA_HPP
#define ESTADODIREITORESPOSTA_HPP

#include "EstadoDebate.hpp"

class EstadoDireitoResposta :
    public EstadoDebate
{
public:

    void executar(
        MediarDebate* mediador,
        ConfiguraTempo* config,
        LogSistem* log
    ) override;
};

#endif