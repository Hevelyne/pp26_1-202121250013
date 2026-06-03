/*#include "FachadaDebate.hpp"
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
}*/

#include "FachadaDebate.hpp"

#include "PoliticoBuilder.hpp"
#include "EleitorBuilder.hpp"  // inserção do Builder 

int main()
{
    FachadaDebate* sistema =
        FachadaDebate::get_instance();

    sistema->configuracao(
        10,
        20,
        15,
        15
    );

    Inquiridor* candidato1 =
        PoliticoBuilder()
            .set_nome("Marcelo")
            .set_partido("Partido A")
            .set_cargo("Governador")
            .set_estado("PE")
            .set_numero(1234)
            .build_inquiridor();

    Inquirido* candidato2 =
        PoliticoBuilder()
            .set_nome("Fernando")
            .set_partido("Partido B")
            .set_cargo("Senador")
            .set_estado("PE")
            .set_numero(5678)
            .build_inquirido();

    Eleitor* e1 =
        EleitorBuilder()
            .set_nome("Hevelyne")
            .build();

    Eleitor* e2 =
        EleitorBuilder()
            .set_nome("Cynthia")
            .build();

    Eleitor* e3 =
        EleitorBuilder()
            .set_nome("Thiago")
            .build();

    candidato1->anexar_eleitor(e1);
    candidato1->anexar_eleitor(e2);

    candidato2->anexar_eleitor(e3);

    Inquiridor* clone =
        dynamic_cast<Inquiridor*>(
            candidato1->clone()
        );

    sistema->executar_debate(
        candidato1,
        candidato2
    );

    delete clone;

    delete candidato1;
    delete candidato2;

    delete e1;
    delete e2;
    delete e3;

    return 0;
}


