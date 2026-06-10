#include "EstadoResposta.hpp"
#include "EstadoReplica.hpp"

#include "MediarDebate.hpp"
#include "LogSistem.hpp"
#include "ColaboradorPolitico.hpp"

#include <iostream>

#include <thread>
#include <chrono>

using namespace std;


void EstadoResposta::executar(
    MediarDebate* m,
    ConfiguraTempo* c,
    LogSistem* l
)
{
    cout << endl;

    cout << "\033[35m";

    cout
        << "[STATE ATIVO]"
        << endl;

    cout
        << "EstadoResposta"
        << endl;

    cout << "\033[0m";

    cout << "\033[35m";

    cout << "\n====================================\n";
    cout << "ETAPA 2 - RESPOSTA\n";
    cout << "====================================\n";
    cout << "\033[0m";


    l->register_log("RESPOSTA");

    m->politico_responde()->falar(
        "RESPOSTA",
        c->get_temp_resposta(),
        l
    );
    
    cout << endl;
    cout << "\033[36m";
    cout << "[STATE]" << endl;
    cout << "Transição para EstadoReplica..." << endl;
    cout << "\033[0m";

    this_thread::sleep_for(
            chrono::milliseconds(2000)
    );

    m->alterar_estado(
        new EstadoReplica()
    );
    
}
