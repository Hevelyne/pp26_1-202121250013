#ifndef MEDIADORBASE_HPP
#define MEDIADORBASE_HPP

#include "ConfiguraTempo.hpp"

class ColaboradorPolitico;
class LogSistem;

class MediadorBase
{
public:

    virtual void solicitar_DR(
        ColaboradorPolitico* politico
    ) = 0;

    virtual void debate(
        ConfiguraTempo* config,
        LogSistem* log
    ) = 0;

    virtual ~MediadorBase() = default;
};

#endif