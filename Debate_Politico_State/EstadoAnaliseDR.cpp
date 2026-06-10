#include "EstadoAnaliseDR.hpp"
#include "EstadoDireitoResposta.hpp"
#include "EstadoPergunta.hpp"
#include "MediarDebate.hpp"
#include "EstadoProximaRodada.hpp"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void EstadoAnaliseDR::executar(

    MediarDebate* mediador,
    ConfiguraTempo* config,
    LogSistem* log
)
{
    cout << endl;
    cout << "\033[33m";
    cout << "[STATE ATIVO]" << endl;
    cout << "EstadoAnaliseDR" << endl;
    cout << "\033[0m";
    cout << endl;
    cout << "\033[35m";
    cout << "====================================" << endl;
    cout << "MEDIADOR ANALISANDO" << endl;
    cout << "SOLICITAÇÕES DE DR" << endl;
    cout << "====================================" << endl;
    cout << "\033[0m";
    
    mediador->avaliar_solicitacoes();
    
    if(
        mediador->possui_DR_aprovados()
    )
    {
        cout << endl;
        cout << "\033[32m";
        cout << "[MEDIADOR]" << endl;
        cout << "Solicitações aprovadas" << endl;
        cout << "Fluxo normal será interrompido" << endl;
        cout << "\033[0m";
    }
    else
    {
        cout << endl;
        cout << "\033[33m";
        cout << "[MEDIADOR]" << endl;
        cout << "Nenhum DR aprovado" << endl;
        cout << "Fluxo normal continua" << endl;
        cout << "\033[0m";
    

        this_thread::sleep_for(
            chrono::milliseconds(2000)
        );

        mediador->alterar_estado(
            new EstadoProximaRodada()
        );
    }
}

