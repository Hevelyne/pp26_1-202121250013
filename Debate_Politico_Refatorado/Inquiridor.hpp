#ifndef INQUIRIDOR_HPP
#define INQUIRIDOR_HPP

#include "ColaboradorPolitico.hpp"

class Inquiridor :
    public ColaboradorPolitico {

public:

    Inquiridor(
        string nome,
        string partido
    );

    void perguntar(
        int tempo,
        LogSistem* log
    ) override;

    void replica(
        int tempo,
        LogSistem* log
    ) override;
};

#endif
