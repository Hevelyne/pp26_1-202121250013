#include "EstadoDireitoResposta.hpp"
#include "EstadoPergunta.hpp"
#include "EstadoProximaRodada.hpp"

#include "ColaboradorPolitico.hpp"
#include "MediarDebate.hpp"
#include "ConfiguraTempo.hpp"
#include "LogSistem.hpp"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void EstadoDireitoResposta::executar(
    MediarDebate* mediador,
    ConfiguraTempo* config,
    LogSistem* log
)
{
    cout << endl;
    cout << "\033[32m";
    cout << "[STATE ATIVO]" << endl;
    cout << "EstadoDireitoResposta" << endl;
    cout << "\033[0m";
    cout << endl;
    cout << "\033[32m";
    cout << "####################################" << endl;
    cout << "DIREITO DE RESPOSTA" << endl;
    cout << "####################################" << endl;
    cout << "\033[0m";

    while(
        mediador->possui_DR_aprovados()
    )
    {
        ColaboradorPolitico* politico =
            mediador->proximo_DR();

        if(politico == nullptr)
        {
            break;
        }

        cout << endl;
        cout << "\033[32m";
        cout << "====================================" << endl;
        cout << "DIREITO DE RESPOSTA CONCEDIDO" << endl;
        cout << "====================================" << endl;
        cout << "CANDIDATO: " << politico->get_nome() << endl;
        cout << "PARTIDO: " << politico->get_partido() << endl;
        cout << "====================================" << endl;
        cout << "\033[0m";

        log->register_log(
            "Direito de Resposta concedido para "
            + politico->get_nome()
        );

        politico->executar_direito_resposta(
            config->get_temp_DR(),
            log
        );
    }

    cout << endl;
    cout << "\033[33m";
    cout << "####################################" << endl;
    cout << " RETORNANDO AO FLUXO NORMAL" << endl;
    cout << " DO DEBATE" << endl;
    cout<< "####################################" << endl;
    cout << "\033[0m";
    cout << "\033[36m";
    cout << "[STATE]" << endl;
    cout << "Transição para EstadoProximaRodada" << endl;
    cout << "\033[0m";

    this_thread::sleep_for(
        chrono::milliseconds(2000)
    );

    mediador->alterar_estado(
        new EstadoProximaRodada()
    );
}