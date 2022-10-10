/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Clock
*/

#include "Clock.hpp"

nts::Clock::Clock() : _value(UNDEFINED), _oldValue(UNDEFINED), _component(nullptr), _links({0,0}), _realValue(UNDEFINED)
{
}

nts::Clock::~Clock()
{
}

void nts::Clock::dump() const
{
    std::cout << "Component Clock" << std::endl;
}

void nts::Clock::simulate(std::size_t tick)
{
    if (tick > 0) {
        Tristate temp = _value;
        _value = _oldValue;
        _oldValue = temp;
    }
    _realValue = _value;
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    if (pin != 1)
        return (Tristate::UNDEFINED);
    return _value;
}

void nts::Clock::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw Error("Clock pin must be set to 1");
    else if (_component != nullptr)
        throw Error("Clock component already linked");
    _component = &other;
    _links = {pin, otherPin};
}

void nts::Clock::setValue(const std::string &value)
{
    if (value == "1") {
        _oldValue = FALSE;
        _value = TRUE;
    } else if (value == "0") {
        _oldValue = TRUE;
        _value = FALSE;
    } else {
        _oldValue = UNDEFINED;
        _value = UNDEFINED;
    }
}

nts::Tristate nts::Clock::getValue() const
{
    return _realValue;
}


