#ifndef CONFIGURATEMPO_HPP
#define CONFIGURATEMPO_HPP

class ConfiguraTempo
{
private:

    int pergunta;

    int resposta;

    int replica;

    int treplica;

    int direitoResposta;

public:

    void set_temp_pergunta(
        int t
    );

    int get_temp_pergunta();

    void set_temp_resposta(
        int t
    );

    int get_temp_resposta();

    void set_temp_replica(
        int t
    );

    int get_temp_replica();

    void set_temp_treplica(
        int t
    );

    int get_temp_treplica();

    void set_temp_DR(
        int t
    );

    int get_temp_DR();
};

#endif