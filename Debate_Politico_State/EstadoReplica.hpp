#ifndef ESTADOREPLICA_HPP
#define ESTADOREPLICA_HPP

#include "EstadoDebate.hpp"

class EstadoReplica :
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