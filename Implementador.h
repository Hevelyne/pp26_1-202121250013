#ifndef IMPLEMENTADOR_H
#define IMPLEMENTADOR_H

#include <string>

// Interface
class Implementador {
public:
    virtual void getDados(std::string tipo) = 0;
    virtual ~Implementador() {}
};

// Implementação BD
class PublicacaoImplBD : public Implementador {
public:
    void getDados(std::string tipo) override;
};

// Implementação XML
class PublicacaoImplXML : public Implementador {
public:
    void getDados(std::string tipo) override;
};

#endif