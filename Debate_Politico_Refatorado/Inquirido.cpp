#include "Inquirido.hpp"

using namespace std;

Inquirido::Inquirido(
    string nome,
    string partido
) : ColaboradorPolitico(nome, partido) {}

void Inquirido::responder(
    int tempo,
    LogSistem* log
) {

    cout << endl;

    cout << "\033[35m";

    cout << "================================" << endl;

    cout << "CANDIDATO: " << nome << " - " << partido << endl;

    cout << "ETAPA: RESPOSTA" << endl;

    cout << "================================"<< endl;

    cout << "\033[0m";

    notificar_eleitores(
        "Candidato "
        + nome +
        " está falando (RESPOSTA)"
    );

    microfone.liga();

    log->register_log(
        "Microfone aberto para resposta"
    );

    microfone.passa_tempo(tempo);

    microfone.desliga();

    log->register_log(
        "Resposta encerrada"
    );
}

void Inquirido::treplica(
    int tempo,
    LogSistem* log
) {

    cout << endl;

    cout << "\033[35m";

    cout << "================================"<< endl;

    cout << "CANDIDATO: "<< nome << " - " << partido << endl;

    cout << "ETAPA: TRÉPLICA" << endl;

    cout << "================================" << endl;

    cout << "\033[0m";

    notificar_eleitores(
        "Candidato "
        + nome +
        " está falando (TRÉPLICA)"
    );

    microfone.liga();

    log->register_log(
        "Microfone aberto para tréplica"
    );

    microfone.passa_tempo(tempo);

    microfone.desliga();

    log->register_log(
        "Tréplica encerrada"
    );
}
