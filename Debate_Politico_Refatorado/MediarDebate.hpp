#ifndef MEDIARDEBATE_HPP
#define MEDIARDEBATE_HPP

#include "Inquiridor.hpp"
#include "Inquirido.hpp"

class MediarDebate :
    public MediadorBase {

private:

    Inquiridor* inquiridor;
    Inquirido* inquirido;

public:

    void set_inquiridor(
        Inquiridor* i
    );

    void set_inquirido(
        Inquirido* i
    );

    void debate(
        ConfiguraTempo* config,
        LogSistem* log
    ) override;
};

#endif
