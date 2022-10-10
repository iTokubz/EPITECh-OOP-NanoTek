/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Input
*/

#include "Input.hpp"
#include "../printState.hpp"

nts::Input::Input() : _oldValue(UNDEFINED), _links({0,0}), _component(nullptr), _value(UNDEFINED)
{
}

nts::Input::~Input()
{
}

void nts::Input::dump() const
{
    std::cout << "Component Input";
    if (_component)
        std::cout << "is linked to the pin " << _links.second << " from the component ";
    else
        std::cout << " isn't linked" << std::endl;
    std::cout << "his value is " << printTristate(this->getValue()) << std::endl;
}

void nts::Input::simulate(std::size_t tick)
{
    _oldValue = _value;
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    if (pin != 1)
        return (nts::Tristate::UNDEFINED);
    return (_oldValue);
}

void nts::Input::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw Error("The pin must be 1.");
    else if (_component != nullptr) {
        throw Error("Input already linked.");
    }
    _component = &other;
    _links = {pin, otherPin};
}

void nts::Input::setValue(const std::string &value)
{
    if (value == "1")
        _value = TRUE;
    else if (value == "0")
        _value = FALSE;
    else
        _value = UNDEFINED;
}

nts::Tristate nts::Input::getValue() const
{
    return _oldValue;
}