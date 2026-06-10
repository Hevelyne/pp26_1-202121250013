#ifndef MEDIARDEBATE_HPP
#define MEDIARDEBATE_HPP

#include <vector>
#include <queue>

#include "MediadorBase.hpp"

class EstadoDebate;
class ColaboradorPolitico;
class ConfiguraTempo;
class LogSistem;

using namespace std;

class MediarDebate :
    public MediadorBase
{
private:

    vector<ColaboradorPolitico*> participantes;

    EstadoDebate* estadoAtual;

    queue<ColaboradorPolitico*> filaSolicitacoesDR;

    queue<ColaboradorPolitico*> filaAprovadosDR;

    bool bloqueioDR;

    int indicePergunta;

    int indiceResposta;

    int rodadaAtual;

    int maxRodadas;

    bool debateEncerrado;

public:

    MediarDebate();

    virtual ~MediarDebate();

    void adicionar_participante(
        ColaboradorPolitico* p
    );

    int quantidade_participantes();

    ColaboradorPolitico*
    get_participante(
        int indice
    );

    void alterar_estado(
        EstadoDebate* estado
    );

    EstadoDebate*
    get_estado();

    ColaboradorPolitico*
    politico_pergunta();

    ColaboradorPolitico*
    politico_responde();

    void proxima_rodada();

    void solicitar_DR(
        ColaboradorPolitico* politico
    ) override;

    bool possui_solicitacoes_DR();

    void avaliar_solicitacoes();

    bool possui_DR_aprovados();

    ColaboradorPolitico*
    proximo_DR();

    void limpar_filas_DR();

    void bloquear_DR();

    void desbloquear_DR();

    bool DR_bloqueado();

    void set_max_rodadas(
        int qtd
    );

    bool encerrado();

    void encerrar();

    void debate(
        ConfiguraTempo* config,
        LogSistem* log
    ) override;
};

#endif