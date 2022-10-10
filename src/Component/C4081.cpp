/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** C4081
*/

#include "C4081.hpp"
#include "../Gates/Gates.hpp"

nts::C4081::C4081()
{
}

nts::C4081::~C4081()
{
}

void nts::C4081::dump() const
{
    std::cout << "Component 4081" << std::endl;
}

void nts::C4081::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::C4081::compute(std::size_t pin)
{
    std::size_t first;
    std::size_t second;

    if (pin == 3 || pin == 10) {
        first = pin - 1;
        second = pin - 2;
    } else if (pin == 4 || pin == 11) {
        first = pin + 1;
        second = pin + 2;
    }
    if (_link.find(first) == _link.end() || _link.find(second) == _link.end()) {
        throw Error("One pin insn't linked (C4081)");
    }
    Tristate firstVal = _link.find(first)->second.first->compute(_link.find(first)->second.second);
    Tristate secondVal = _link.find(second)->second.first->compute(_link.find(second)->second.second);
    return (Gates::Gate4081(firstVal, secondVal));
}

void nts::C4081::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    if (_link.find(pin) == _link.end()) {
        if ((pin == 3 || pin == 4 || pin == 11 || pin == 10)) {
            _link[pin].first = &other;
            _link[pin].second = otherPin;
        } else if ((pin == 1 || pin == 2 || pin == 5 || pin == 6 || pin == 13 || pin == 12 || pin == 9 || pin == 8)) {
            _link[pin].first = &other;
            _link[pin].second = otherPin;
        } else {
            throw Error("It doesnt match with the 4081 component");
        }
    } else {
        throw Error("pin already linked");
    }
}

