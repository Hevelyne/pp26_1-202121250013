#include <iostream>
#include <thread>
#include <chrono>

#include "Microfone.hpp"
#include "ColaboradorPolitico.hpp"

using namespace std;

Microfone::Microfone()
{
    ligado = false;
}

void Microfone::liga()
{
    ligado = true;

    cout
        << "[MICROFONE LIGADO]"
        << endl;
}

void Microfone::desliga()
{
    ligado = false;

    cout
        << "[MICROFONE DESLIGADO]"
        << endl;
}

void Microfone::passa_tempo(
    int tempo
)
{
    cout
        << "Tempo disponível: "
        << tempo
        << " segundos"
        << endl;

    this_thread::sleep_for(
        chrono::seconds(3)
    );
}

void Microfone::pressionar_DR(
    ColaboradorPolitico* politico
)
{
    cout
        << "[BOTÃO DR ACIONADO]"
        << endl;

    politico->apertar_botao_DR();
}