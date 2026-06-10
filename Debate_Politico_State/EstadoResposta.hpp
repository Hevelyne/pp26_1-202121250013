#ifndef ESTADORESPOSTA_HPP
#define ESTADORESPOSTA_HPP

#include "EstadoDebate.hpp"

class EstadoResposta :
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