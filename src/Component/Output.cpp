/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output() : _value(UNDEFINED), _component(nullptr), _links({0,0})
{
}

nts::Output::~Output()
{
}

void nts::Output::dump() const
{
    std::cout << "Component Output" << std::endl;
}

void nts::Output::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    if (pin != 1)
        throw Error("outpout pin must be 1");
    if (_component == nullptr)
        return (nts::Tristate::UNDEFINED);
    _value = _component->compute(_links.second);
    return (_value);
}

void nts::Output::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw Error("Outpout pin must be 1");
    else if (_component != nullptr)
        throw Error("Outpout already linked");
    _component = &other;
    _links = {pin, otherPin};
}

nts::Tristate nts::Output::getValue() const
{
    return _value;
}
