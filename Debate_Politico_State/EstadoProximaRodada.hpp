#ifndef ESTADOPROXIMARODADA_HPP
#define ESTADOPROXIMARODADA_HPP

#include "EstadoDebate.hpp"

class EstadoProximaRodada :
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