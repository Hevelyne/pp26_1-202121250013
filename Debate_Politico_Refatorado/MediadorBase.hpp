#ifndef MEDIADORBASE_HPP
#define MEDIADORBASE_HPP

#include "ConfiguraTempo.hpp"
#include "LogSistem.hpp"

class MediadorBase {

public:

    virtual void debate(
        ConfiguraTempo* config,
        LogSistem* log
    ) = 0;
};

#endif
