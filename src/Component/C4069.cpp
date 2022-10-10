/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** C4069
*/

#include "C4069.hpp"
#include "../Gates/Gates.hpp"

nts::C4069::C4069()
{
}

nts::C4069::~C4069()
{
}

void nts::C4069::dump() const
{
    std::cout << "Component 4069" << std::endl;
}

void nts::C4069::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::C4069::compute(std::size_t pin)
{
    std::size_t first;

    if (pin == 2 || pin == 4 || pin == 6)
        first = pin - 1;
    if (pin == 12 || pin == 8 || pin == 10)
        first = pin + 1;


    if (_link.find(first) == _link.end()) {
        throw Error("One pin insn't linked (C4069)");
    }
    Tristate firstVal = _link.find(first)->second.first->compute(_link.find(first)->second.second);
    return (Gates::Gate4069(firstVal));
}

void nts::C4069::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    if (_link.find(pin) == _link.end()) {
        if ((pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12)) {
            _link[pin].first = &other;
            _link[pin].second = otherPin;
        } else if ((pin == 1 || pin == 3 || pin == 5 || pin == 9 || pin == 11 || pin == 13)) {
            _link[pin].first = &other;
            _link[pin].second = otherPin;
        } else {
            throw Error("It doesnt match with the 4069 component");
        }
    } else {
        throw Error("pin already linked");
    }
}
