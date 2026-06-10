#include "EstadoProximaRodada.hpp"
#include "EstadoPergunta.hpp"
#include "MediarDebate.hpp"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void EstadoProximaRodada::executar(
    MediarDebate* mediador,
    ConfiguraTempo* config,
    LogSistem* log
)
{
	cout << endl;
	cout << "\033[94m";
	cout << "########################################" << endl;
	cout << "[STATE ATIVO]" << endl;
	cout << "EstadoProximaRodada" << endl;
	cout << "########################################" << endl;
	cout << "\033[0m";
	cout << endl;
	cout << "\033[32m";
	cout << "AVANÇANDO PARA PRÓXIMA RODADA" << endl;
	cout << "\033[0m";

	mediador->proxima_rodada();

	if(mediador->encerrado())
	{
		return;
	}

	cout << "\033[36m";
	cout << "[STATE]" << endl;
	cout << "Transição para EstadoPergunta" << endl;
	cout << "\033[0m";

	this_thread::sleep_for(
	    chrono::milliseconds(2000)
	);

	mediador->alterar_estado(
	    new EstadoPergunta()
	);
}