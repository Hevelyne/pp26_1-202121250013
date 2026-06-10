#include "ColaboradorPolitico.hpp"
#include "LogSistem.hpp"

using namespace std;

/* =========================
   CONSTRUTOR
========================= */
ColaboradorPolitico::ColaboradorPolitico(
    string nome,
    string partido,
    string cargo,
    string estado,
    int numeroEleitoral
)
:
Entidade(nome)
{
    this->partido = partido;
    this->cargo = cargo;
    this->estado = estado;
    this->numeroEleitoral = numeroEleitoral;

    solicitouDR = false;
    mediador = nullptr;
}

/* =========================
   GETTERS
========================= */
string ColaboradorPolitico::get_partido() { return partido; }
string ColaboradorPolitico::get_cargo() { return cargo; }
string ColaboradorPolitico::get_estado() { return estado; }

int ColaboradorPolitico::get_numero_eleitoral()
{
    return numeroEleitoral;
}

/* =========================
   MEDIADOR
========================= */
void ColaboradorPolitico::set_mediador(MediadorBase* m)
{
    mediador = m;
}

/* =========================
   OBSERVER
========================= */
void ColaboradorPolitico::anexar_eleitor(Observer* obs)
{
    eleitores.push_back(obs);
}

void ColaboradorPolitico::remover_eleitor(Observer* obs)
{
    for (int i = 0; i < (int)eleitores.size(); i++)
    {
        if (eleitores[i] == obs)
        {
            eleitores.erase(eleitores.begin() + i);
            break;
        }
    }
}

void ColaboradorPolitico::notificar_eleitores(string msg)
{
    cout << endl;
    cout << "\033[36m";
    cout << "[OBSERVER]" << endl;
    cout << "\033[0m";

    for (auto eleitor : eleitores)
    {
        eleitor->atualizar(msg);
    }
}

/* =========================
   STATE 
========================= */
void ColaboradorPolitico::falar(
    string etapa,
    int tempo,
    LogSistem* log
)
{
    cout << endl;
    cout << "\033[33m";

    cout << "================================" << endl;
    cout << "CANDIDATO: " << nome << endl;
    cout << "PARTIDO: " << partido << endl;
    cout << "CARGO: " << cargo << endl;
    cout << "ESTADO: " << estado << endl;
    cout << "NUMERO: " << numeroEleitoral << endl;
    cout << "ETAPA: " << etapa << endl;
    cout << "================================" << endl;

    cout << "\033[0m";

    notificar_eleitores(
        "Candidato " + nome + " esta falando na etapa " + etapa
    );

    microfone.liga();

    log->register_log(
        "Microfone aberto para " + etapa
    );

    microfone.passa_tempo(tempo);

    microfone.desliga();

    log->register_log(
        etapa + " encerrada"
    );
}

/* =========================
   DR
========================= */
void ColaboradorPolitico::apertar_botao_DR()
{
    if (!mediador || solicitouDR)
        return;

    solicitouDR = true;

    cout << endl;

    cout << "\033[31m";

    cout
        << "[MEDIATOR]"
        << endl;

    cout
        << nome
        << " entrou na fila de Direito de Resposta"
        << endl;

    cout << "\033[0m";

    mediador->solicitar_DR(this);
   
   
   
   
   
   
   
    /*cout << endl;
    cout << "\033[33m";
    cout << "********************************" << endl;
    cout << "SOLICITACAO DE DIREITO DE RESPOSTA" << endl;
    cout << nome << endl;
    cout << "********************************" << endl;
    cout << "\033[0m";

    mediador->solicitar_DR(this);*/
}

bool ColaboradorPolitico::possui_DR()
{
    return solicitouDR;
}

void ColaboradorPolitico::limpar_DR()
{
    solicitouDR = false;
}

/* =========================
   Execução Direito de Resposta
========================= */
void ColaboradorPolitico::executar_direito_resposta(
    int tempo,
    LogSistem* log
)
{
    cout << endl;
    cout << "\033[32m";

    cout << "################################" << endl;
    cout << "DIREITO DE RESPOSTA CONCEDIDO" << endl;
    cout << "CANDIDATO: " << nome << endl;
    cout << "PARTIDO: " << partido << endl;
    cout << "################################" << endl;

    cout << "\033[0m";

    notificar_eleitores(
        nome + " esta exercendo Direito de Resposta"
    );

    microfone.liga();

    log->register_log("Inicio Direito de Resposta");

    microfone.passa_tempo(tempo);

    microfone.desliga();

    log->register_log("Fim Direito de Resposta");

    solicitouDR = false;
}

/* =========================
   PROTOTYPE 
========================= */
Prototype* ColaboradorPolitico::clone()
{
    ColaboradorPolitico* copia =
        new ColaboradorPolitico(
            nome,
            partido,
            cargo,
            estado,
            numeroEleitoral
        );

    
    copia->solicitouDR = this->solicitouDR;

    return copia;
}


/* =========================
   DESTRUCTOR
========================= */
ColaboradorPolitico::~ColaboradorPolitico()
{
}