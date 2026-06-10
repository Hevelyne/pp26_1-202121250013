#ifndef ESTADOTREPLICA_HPP
#define ESTADOTREPLICA_HPP

#include "EstadoDebate.hpp"

class EstadoTreplica :
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