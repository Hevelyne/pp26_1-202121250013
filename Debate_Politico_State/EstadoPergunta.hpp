#ifndef ESTADOPERGUNTA_HPP
#define ESTADOPERGUNTA_HPP

#include "EstadoDebate.hpp"

class EstadoPergunta :
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