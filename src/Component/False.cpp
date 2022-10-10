/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** False
*/

#include "False.hpp"

nts::False::False() : _link({0,0}), _component(nullptr)
{
}

nts::False::~False()
{
}

void nts::False::dump() const
{
    std::cout << "Component False" << std::endl;
}

void nts::False::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::False::compute(std::size_t pin)
{
    if (pin != 1)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::FALSE);
}

void nts::False::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        throw Error("False pin must be 1");
    }
    else if (_component != nullptr) {
        throw Error("False already linked");
    }
    _component = &other;
    _link = {pin, otherPin};
}