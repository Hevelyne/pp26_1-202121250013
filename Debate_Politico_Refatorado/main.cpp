#include "FachadaDebate.hpp"
#include "Eleitor.hpp"

int main() {

    FachadaDebate* sistema =
        FachadaDebate::get_instance();

    sistema->configuracao(
        10,
        20,
        15,
        15
    );

    Inquiridor candidato1(
        "Marcelo",
        "Partido A"
    );

    Inquirido candidato2(
        "Fernando",
        "Partido B"
    );

    Eleitor e1("Hevelyne");
    Eleitor e2("Cynthia");
    Eleitor e3("Thiago");

    candidato1.anexar_eleitor(&e1);
    candidato1.anexar_eleitor(&e2);

    candidato2.anexar_eleitor(&e3);

    sistema->executar_debate(
        &candidato1,
        &candidato2
    );

    return 0;
}
