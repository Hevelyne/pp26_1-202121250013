#ifndef INQUIRIDO_HPP
#define INQUIRIDO_HPP

#include "ColaboradorPolitico.hpp"

class Inquirido :
    public ColaboradorPolitico {

public:

    Inquirido(
        string nome,
        string partido
    );

    void responder(
        int tempo,
        LogSistem* log
    ) override;

    void treplica(
        int tempo,
        LogSistem* log
    ) override;
};

#endif
