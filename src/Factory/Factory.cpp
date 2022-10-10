/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Factory
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &name)
{
    if (name == "4001")
        return create4001();
    else if (name == "4011")
        return create4011();
    else if (name == "4081")
        return create4081();
    else if (name == "4030")
        return  create4030();
    else if (name == "4069")
        return create4069();
    else if (name == "4071")
        return create4071();
    else if (name == "input")
        return createInput();
    else if (name == "output")
        return createOutput();
    else if (name == "false")
        return createFalse();
    else if (name == "true")
        return createTrue();
    else if (name == "clock")
        return createClock();
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::Factory::create4069()
{
    return std::make_unique<C4069>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createClock()
{
    return std::make_unique<Clock>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createTrue()
{
    return std::make_unique<True>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createFalse()
{
    return std::make_unique<False>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4071()
{
    return (std::make_unique<C4071>());
}

std::unique_ptr<nts::IComponent> nts::Factory::create4001()
{
    return std::make_unique<C4001>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4011()
{
    return std::make_unique<C4011>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4081()
{
    return std::make_unique<C4081>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4030()
{
    return std::make_unique<C4030>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createInput()
{
    return std::make_unique<Input>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createOutput()
{
    return std::make_unique<Output>();
}






