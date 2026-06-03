#include <thread>
#include <chrono>

#include "MediarDebate.hpp"

using namespace std;

void digitando(
    string texto,
    int velocidade = 20
) {

    for(char c : texto) {

        cout << c << flush;

        this_thread::sleep_for(
            chrono::milliseconds(velocidade)
        );
    }

    cout << endl;
}

void MediarDebate::set_inquiridor(
    Inquiridor* i
) {

    inquiridor = i;
}

void MediarDebate::set_inquirido(
    Inquirido* i
) {

    inquirido = i;
}

void MediarDebate::debate(
    ConfiguraTempo* config,
    LogSistem* log
) {

    cout << endl;

    digitando(
        "======================================",
        10
    );

    digitando(
        "       DEBATE POLÍTICO AO VIVO        ",
        20
    );

    digitando(
        "======================================",
        10
    );

    cout << endl;

    this_thread::sleep_for(
        chrono::seconds(2)
    );

    log->register_log(
        "===== INÍCIO DO DEBATE ====="
    );

    cout << endl;

    digitando(
        "Primeira etapa iniciando...",
        40
    );

    this_thread::sleep_for(
        chrono::seconds(2)
    );

    inquiridor->perguntar(
        config->get_temp_pergunta(),
        log
    );

    cout << endl;

    digitando(
        "----------- PRÓXIMA ETAPA -----------",
        15
    );

    cout << endl;

    this_thread::sleep_for(
        chrono::seconds(3)
    );

    digitando(
        "Segunda etapa iniciando...",
        40
    );

    this_thread::sleep_for(
        chrono::seconds(2)
    );

    inquirido->responder(
        config->get_temp_resposta(),
        log
    );

    cout << endl;

    digitando(
        "----------- PRÓXIMA ETAPA -----------",
        15
    );

    cout << endl;

    this_thread::sleep_for(
        chrono::seconds(3)
    );

    digitando(
        "Terceira etapa iniciando...",
        40
    );

    this_thread::sleep_for(
        chrono::seconds(2)
    );

    inquiridor->replica(
        config->get_temp_replica(),
        log
    );

    cout << endl;

    digitando(
        "----------- PRÓXIMA ETAPA -----------",
        15
    );

    cout << endl;

    this_thread::sleep_for(
        chrono::seconds(3)
    );

    digitando(
        "Quarta etapa iniciando...",
        40
    );

    this_thread::sleep_for(
        chrono::seconds(2)
    );

    inquirido->treplica(
        config->get_temp_treplica(),
        log
    );

    cout << endl;

    digitando(
        "======================================",
        10
    );

    this_thread::sleep_for(
        chrono::seconds(2)
    );

    log->register_log(
        "===== FIM DO DEBATE ====="
    );
}