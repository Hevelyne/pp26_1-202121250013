#ifndef MICROFONE_HPP
#define MICROFONE_HPP

class ColaboradorPolitico;

class Microfone
{
private:

    bool ligado;

public:

    Microfone();

    void liga();

    void desliga();

    void passa_tempo(
        int tempo
    );

    void pressionar_DR(
        ColaboradorPolitico* politico
    );
};

#endif