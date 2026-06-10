#include "EstadoTreplica.hpp"
#include "EstadoAnaliseDR.hpp"
#include "MediarDebate.hpp"
#include "LogSistem.hpp"
#include "ColaboradorPolitico.hpp"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void EstadoTreplica::executar(MediarDebate* m, ConfiguraTempo* c, LogSistem* l)
{
    cout << endl;
    cout << "\033[32m";
    cout << "[STATE ATIVO]" << endl;
    cout << "EstadoTreplica" << endl;
    cout << "\033[0m";
    cout << "\033[34m";
    cout << "\n====================================\n";
    cout << "ETAPA 4 - TRÉPLICA\n";
    cout << "====================================\n";
    cout << "\033[0m";

    l->register_log("TRÉPLICA");

    m->politico_responde()->falar(
    "TRÉPLICA",
    c->get_temp_treplica(),
    l
    );
    
    cout << endl;
    cout << "\033[36m";
    cout << "[STATE]" << endl;
    cout << "Transição para EstadoAnaliseDR..." << endl;
    cout << "\033[0m";

    this_thread::sleep_for(
        chrono::milliseconds(2000)
    );

    m->alterar_estado(new EstadoAnaliseDR());
}