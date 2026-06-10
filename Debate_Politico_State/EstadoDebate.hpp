#ifndef ESTADODEBATE_HPP
#define ESTADODEBATE_HPP

class MediarDebate;
class ConfiguraTempo;
class LogSistem;

class EstadoDebate
{
public:

    virtual void executar(
        MediarDebate* mediador,
        ConfiguraTempo* config,
        LogSistem* log
    ) = 0;

    virtual ~EstadoDebate() = default;
};

#endif