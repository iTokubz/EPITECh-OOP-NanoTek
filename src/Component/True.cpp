/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** True
*/

#include "True.hpp"

nts::True::True() : _link({0,0}), _component(nullptr)
{
}

nts::True::~True()
{
}

void nts::True::dump() const
{
    std::cout << "Component True" << std::endl;
}

void nts::True::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    if (pin != 1)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::TRUE);
}

void nts::True::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        std::cerr << "True pin must be 1" << std::endl;
        throw std::exception();
    }
    else if (_component != nullptr) {
        std::cerr << "Component True already linked" << std::endl;
        throw std::exception();
    }
    _component = &other;
    _link = {pin, otherPin};
}

