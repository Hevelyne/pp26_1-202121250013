#ifndef ESTADOANALISEDR_HPP
#define ESTADOANALISEDR_HPP

#include "EstadoDebate.hpp"

class EstadoAnaliseDR :
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