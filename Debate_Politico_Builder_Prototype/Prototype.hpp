#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP

class Prototype {

public:

    virtual Prototype* clone() = 0;

    virtual ~Prototype() = default;
};

#endif