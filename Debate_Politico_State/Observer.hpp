#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

using namespace std;

class Observer
{
public:

    virtual void atualizar(
        string mensagem
    ) = 0;

    virtual ~Observer() = default;
};

#endif

