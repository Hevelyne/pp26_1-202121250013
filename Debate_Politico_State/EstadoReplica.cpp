#include "EstadoReplica.hpp"
#include "EstadoTreplica.hpp"

#include "MediarDebate.hpp"
#include "LogSistem.hpp"
#include "ColaboradorPolitico.hpp"

#include <iostream>

#include <thread>
#include <chrono>

using namespace std;



void EstadoReplica::executar(MediarDebate* m, ConfiguraTempo* c, LogSistem* l)
{
    
    cout << endl;
    cout << "\033[36m";
    cout
        << "[STATE ATIVO]"
        << endl;
    cout
        << "EstadoReplica"
        << endl;
    cout << "\033[0m";
    
    
    
    cout << "\033[36m";
    cout << "\n====================================\n";
    cout << "ETAPA 3 - RÉPLICA\n";
    cout << "====================================\n";
    cout << "\033[0m";

    l->register_log("RÉPLICA");

    m->politico_pergunta()->falar(
    "RÉPLICA",
    c->get_temp_replica(),
    l
    );
    
    cout << endl;
    cout << "\033[36m";
    cout << "[STATE]" << endl;
    cout << "Transição para EstadoTreplica..." << endl;
    cout << "\033[0m";

    this_thread::sleep_for(
        chrono::milliseconds(2000)
    );

    m->alterar_estado(new EstadoTreplica());
}