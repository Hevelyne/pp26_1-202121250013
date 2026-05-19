#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observer {
public:
    
    virtual void atualizar(std::string msg) = 0;

    virtual ~Observer() = default;
};

#endif


