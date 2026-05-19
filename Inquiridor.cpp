#include "Inquiridor.hpp"

using namespace std;

Inquiridor::Inquiridor(
    string nome,
    string partido
) : ColaboradorPolitico(nome, partido) {}

void Inquiridor::perguntar(
    int tempo,
    LogSistem* log
) {

    cout << endl;

    cout << "\033[33m";

    cout << "================================" << endl;

    cout << "CANDIDATO: " << nome << " - " << partido << endl;

    cout << "ETAPA: PERGUNTA" << endl;

    cout << "================================" << endl;

    cout << "\033[0m";

    notificar_eleitores(
        "Candidato " + nome + " está falando (PERGUNTA)"
    );

    microfone.liga();

    log->register_log(
        "Microfone aberto para pergunta"
    );

    microfone.passa_tempo(tempo);

    microfone.desliga();

    log->register_log(
        "Pergunta encerrada"
    );
}

void Inquiridor::replica(
    int tempo,
    LogSistem* log
) {

    cout << endl;

    cout << "\033[33m";

    cout << "================================" << endl;

    cout << "CANDIDATO: " << nome << " - " << partido << endl;

    cout << "ETAPA: RÉPLICA" << endl;

    cout << "================================" << endl;

    cout << "\033[0m";

    notificar_eleitores(
        "Candidato " + nome + " está falando (RÉPLICA)"
    );

    microfone.liga();

    log->register_log(
        "Microfone aberto para réplica"
    );

    microfone.passa_tempo(tempo);

    microfone.desliga();

    log->register_log(
        "Réplica encerrada"
    );
}