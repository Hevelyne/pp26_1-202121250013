#include "EstadoPergunta.hpp"
#include "EstadoResposta.hpp"

#include "MediarDebate.hpp"
#include "LogSistem.hpp"
#include "ColaboradorPolitico.hpp"

#include <iostream>

#include <thread>
#include <chrono>

using namespace std;

void EstadoPergunta::executar(
    MediarDebate* m,
    ConfiguraTempo* c,
    LogSistem* l
)
{
    cout << endl;

    cout << "\033[34m";

    cout
        << "[STATE ATIVO]"
        << endl;

    cout
        << "EstadoPergunta"
        << endl;

    cout << "\033[0m";

    cout << "\033[33m";

    cout << "\n====================================\n";
    cout << "ETAPA 1 - PERGUNTA\n";
    cout << "====================================\n";

    cout << "\033[0m";

    l->register_log("PERGUNTA");

    m->politico_pergunta()->falar(
        "PERGUNTA",
        c->get_temp_pergunta(),
        l
    );
    
    cout << endl;
    cout << "\033[36m";
    cout << "[STATE]" << endl;
    cout << "Transição para EstadoResposta..." << endl;
    cout << "\033[0m";

    this_thread::sleep_for(
        chrono::milliseconds(2000)
    );
    
 
    m->alterar_estado(
        new EstadoResposta()
    );
}