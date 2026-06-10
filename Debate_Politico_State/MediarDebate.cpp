#include "MediarDebate.hpp"
#include "EstadoPergunta.hpp"
#include "EstadoResposta.hpp"
#include "EstadoReplica.hpp"
#include "EstadoTreplica.hpp"
#include "EstadoAnaliseDR.hpp"
#include "EstadoDireitoResposta.hpp"
#include "ColaboradorPolitico.hpp"
#include "LogSistem.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <typeinfo> 

using namespace std;

/* =========================
   efeito digitação
========================= */
void digitando(string texto, int vel = 20)
{
    for(char c : texto)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(vel));
    }
    cout << endl;
}

/* =========================
   CONSTRUTOR
========================= */
MediarDebate::MediarDebate()
{
    estadoAtual = new EstadoPergunta();

    indicePergunta = 0;
    indiceResposta = 1;

    rodadaAtual = 0;
    maxRodadas = 1;

    debateEncerrado = false;
    bloqueioDR = false;
}

/* =========================
   DESTRUTOR
========================= */
MediarDebate::~MediarDebate()
{
    delete estadoAtual;

    for(auto p : participantes)
        delete p;
}

/* =========================
   PARTICIPANTES
========================= */
void MediarDebate::adicionar_participante(ColaboradorPolitico* p)
{
    participantes.push_back(p);
}

int MediarDebate::quantidade_participantes()
{
    return participantes.size();
}

ColaboradorPolitico* MediarDebate::get_participante(int indice)
{
    return participantes[indice];
}

/* =========================
   ESTADO
========================= */

void MediarDebate::alterar_estado(
    EstadoDebate* estado
)
{
    string origem =
        typeid(*estadoAtual).name();

    string destino =
        typeid(*estado).name();

    /* ---------- ORIGEM ---------- */

    if(origem.find("EstadoPergunta") != string::npos)
        origem = "EstadoPergunta";

    if(origem.find("EstadoResposta") != string::npos)
        origem = "EstadoResposta";

    if(origem.find("EstadoReplica") != string::npos)
        origem = "EstadoReplica";

    if(origem.find("EstadoTreplica") != string::npos)
        origem = "EstadoTreplica";

    if(origem.find("EstadoAnaliseDR") != string::npos)
        origem = "EstadoAnaliseDR";

    if(origem.find("EstadoDireitoResposta") != string::npos)
        origem = "EstadoDireitoResposta";

    if(origem.find("EstadoProximaRodada") != string::npos)
        origem = "EstadoProximaRodada";

    /* ---------- DESTINO ---------- */

    if(destino.find("EstadoPergunta") != string::npos)
        destino = "EstadoPergunta";

    if(destino.find("EstadoResposta") != string::npos)
        destino = "EstadoResposta";

    if(destino.find("EstadoReplica") != string::npos)
        destino = "EstadoReplica";

    if(destino.find("EstadoTreplica") != string::npos)
        destino = "EstadoTreplica";

    if(destino.find("EstadoAnaliseDR") != string::npos)
        destino = "EstadoAnaliseDR";

    if(destino.find("EstadoDireitoResposta") != string::npos)
        destino = "EstadoDireitoResposta";

    if(destino.find("EstadoProximaRodada") != string::npos)
        destino = "EstadoProximaRodada";

    cout << endl;
    cout << "\033[31m";

    digitando(
        "========================================", 5
    );

    digitando(
        "[STATE] TRANSICAO DE ESTADO", 25
    );

    digitando(
        "DE: " + origem, 20
    );

    digitando(
        "PARA: " + destino, 20
    );

    digitando(
        "========================================", 5
    );

    cout << "\033[0m";




    
    delete estadoAtual;  // mantem

    estadoAtual = estado;  // mantem 
}

EstadoDebate* MediarDebate::get_estado()
{
    return estadoAtual;
}

/* =========================
   RODADA / FLUXO
========================= */
ColaboradorPolitico* MediarDebate::politico_pergunta()
{
    return participantes[indicePergunta % participantes.size()];
}

ColaboradorPolitico* MediarDebate::politico_responde()
{
    return participantes[indiceResposta % participantes.size()];
}

void MediarDebate::proxima_rodada()
{
    rodadaAtual++;

    indicePergunta++;
    indiceResposta++;

    if(rodadaAtual >= maxRodadas)
    {
        encerrar();
    }
}

/* =========================
   DIREITO DE RESPOSTA
========================= */

void MediarDebate::solicitar_DR(
    ColaboradorPolitico* politico
)
{
    cout << endl;

    cout << "\033[31m";

    cout
        << "[MEDIATOR]"
        << endl;

    cout
        << politico->get_nome()
        << " entrou na fila de DR"
        << endl;

    cout << "\033[0m";

    filaSolicitacoesDR.push(
        politico
    );
}

bool MediarDebate::possui_solicitacoes_DR()
{
    return !filaSolicitacoesDR.empty();
}

void MediarDebate::avaliar_solicitacoes()
{
    int ordem = 1;

    while(!filaSolicitacoesDR.empty())
    {
        ColaboradorPolitico* p =
            filaSolicitacoesDR.front();

        cout << endl;

        cout << "\033[32m";

        cout
            << "[MEDIATOR]"
            << endl;

        cout
            << "DR APROVADO #"
            << ordem
            << " -> "
            << p->get_nome()
            << endl;

        cout << "\033[0m";

        filaAprovadosDR.push(p);

        filaSolicitacoesDR.pop();

        ordem++;
    }
}


bool MediarDebate::possui_DR_aprovados()
{
    return !filaAprovadosDR.empty();
}

ColaboradorPolitico* MediarDebate::proximo_DR()
{
    if(filaAprovadosDR.empty()) return nullptr;

    ColaboradorPolitico* p = filaAprovadosDR.front();
    filaAprovadosDR.pop();
    return p;
}

void MediarDebate::limpar_filas_DR()
{
    while(!filaSolicitacoesDR.empty()) filaSolicitacoesDR.pop();
    while(!filaAprovadosDR.empty()) filaAprovadosDR.pop();
}

void MediarDebate::bloquear_DR()
{
    bloqueioDR = true;
}

void MediarDebate::desbloquear_DR()
{
    bloqueioDR = false;
}

bool MediarDebate::DR_bloqueado()
{
    return bloqueioDR;
}

/* =========================
   CONFIGURAÇÃO
========================= */
void MediarDebate::set_max_rodadas(int qtd)
{
    maxRodadas = qtd;
}

bool MediarDebate::encerrado()
{
    return debateEncerrado;
}

void MediarDebate::encerrar()
{
    debateEncerrado = true;
}

/* =========================
   LOOP PRINCIPAL
========================= */
void MediarDebate::debate(ConfiguraTempo* config, LogSistem* log)
{
    cout << "\033[36m";
    digitando("======================================", 10);
    digitando("       DEBATE POLÍTICO AO VIVO", 20);
    digitando("======================================", 10);
    cout << "\033[0m\n";

    log->register_log("INÍCIO DO DEBATE");
    
    cout << endl;

    cout << "\033[96m";

    digitando(
        "====================================", 5
    );
    digitando(
        "PADROES DE PROJETO EM EXECUCAO", 20
    );
    digitando(
        "====================================", 5
    );
    digitando(
        "[Singleton]  FachadaDebate", 15
    );
    digitando(
        "[Singleton]  LogSistem", 15
    );
    digitando(
        "[Mediator]   MediarDebate", 15
    );
    digitando(
        "[State]      Estados do Debate", 15
    );
    digitando(
        "[Observer]   Eleitores", 15
    );
    digitando(
        "[Builder]    PoliticoBuilder", 15
    );

    digitando(
        "[Builder]    EleitorBuilder", 15
    );

    digitando(
        "[Prototype]  Clone de entidades", 15
    );

    digitando(
        "====================================", 5
    );

    cout << "\033[0m";
    

    while(!debateEncerrado)
    {
        estadoAtual->executar(this, config, log);
    }

    cout << "\033[31m";
    digitando("======================================", 10);
    digitando("         FIM DO DEBATE", 20);
    digitando("======================================", 10);
    cout << "\033[0m";

    log->register_log("FIM DO DEBATE");
}