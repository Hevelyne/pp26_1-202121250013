#include "FachadaDebate.hpp"
#include "PoliticoBuilder.hpp"
#include "EleitorBuilder.hpp"

// EEIITAAA

int main()
{
    FachadaDebate* sistema =
        FachadaDebate::get_instance();

    sistema->configuracao(
        10, // pergunta
        20, // resposta
        15, // replica
        15, // treplica
        60, // DR
        2   // rodadas
    );

    ColaboradorPolitico* p1 =
        PoliticoBuilder()
        .set_nome("Marcelo")
        .set_partido("Partido A")
        .set_cargo("Governador")
        .set_estado("PE")
        .set_numero(1111)
        .build();

    ColaboradorPolitico* p2 =
        PoliticoBuilder()
        .set_nome("Fernando")
        .set_partido("Partido B")
        .set_cargo("Senador")
        .set_estado("PE")
        .set_numero(2222)
        .build();

    ColaboradorPolitico* p3 =
        PoliticoBuilder()
        .set_nome("Carlos")
        .set_partido("Partido C")
        .set_cargo("Deputado")
        .set_estado("PE")
        .set_numero(3333)
        .build();

    Eleitor* e1 =
        EleitorBuilder()
        .set_nome("Hevelyne")
        .build();

    Eleitor* e2 =
        EleitorBuilder()
        .set_nome("Cynthia")
        .build();

    p1->anexar_eleitor(e1);

    p2->anexar_eleitor(e2);

    sistema->adicionar_participante(p1);

    sistema->adicionar_participante(p2);

    sistema->adicionar_participante(p3);

    /*
     * Exemplo:
     * Carlos solicita DR
     */
    p3->apertar_botao_DR();

    sistema->executar_debate();

    delete p1;
    delete p2;
    delete p3;

    delete e1;
    delete e2;

    return 0;
}

