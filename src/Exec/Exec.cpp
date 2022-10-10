/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Exec
*/

#include "Exec.hpp"
#include "../Factory/Factory.hpp"
#include <utility>
#include "../printState.hpp"
#include <functional>
#include <algorithm>
#include <stdlib.h>

nts::Exec::Exec(std::string &file) : _power(1), _parser(), _tick(0)
{
    _parser.parseAll(file);
    fillMap();
    linkComponent();

}

nts::Exec::~Exec()
{
}

void nts::Exec::shellExec(std::string &exec)
{
    std::size_t to_find = exec.find('=');
    std::vector<std::string> commands = {"display", "exit", "dump", "simulate", "loop"};
    size_t i = 0;
    void (nts::Exec::*function[])() = {&nts::Exec::display, &nts::Exec::exit, &nts::Exec::dump, &nts::Exec::simulate, &nts::Exec::loop};

    for (std::vector<std::string>::iterator str = commands.begin(); str!= commands.end(); ++str) {
        if (exec == *str) {
            return (this->*function[i])();
        }
        ++i;
    }
    if (to_find != std::string::npos) {
        std::pair<std::string, std::string> pair;
        pair.first = exec.substr(0, to_find);
        pair.second = exec.substr(to_find + 1, exec.size());
        if ((pair.second != "1" && pair.second != "0" && pair.second != "U"))
            std::cerr << "Value must be 1 or 0 or U" << std::endl;
        for (auto it = _components.begin(); it != _components.end(); ++it) {
            if (pair.first == it->first && it->second.get() == dynamic_cast<Input *>(it->second.get())) {
                Input *ptr = dynamic_cast<Input *>(it->second.get());
                if (!ptr)
                    throw Error("failed to dynamic cast (Input)");
                ptr->setValue(pair.second);
                return;
            }
            if (pair.first == it->first && it->second.get() == dynamic_cast<Clock *>(it->second.get())) {
                Clock *ptr = dynamic_cast<Clock *>(it->second.get());
                if (!ptr)
                    throw Error("failed to dynamic cast (Clock)");
                ptr->setValue(pair.second);
                return;
            }
        }
        std::cerr << "Unknown component name: " << pair.first << std::endl;
    }
}

size_t nts::Exec::getPower()
{
    return this->_power;
}

void nts::Exec::loop()
{
    while (1) {
        this->simulate();
        sleep(1);
        this->display();
        sleep(1);
    }
}

void nts::Exec::fillMap()
{

    for (auto &s: _parser.getComponents()) {
        _components.insert(std::pair<std::string, std::unique_ptr<nts::IComponent>>(s.second, Factory::createComponent(s.first)));
    }
}

void nts::Exec::exit()
{
    this->_power = 0;
}

void nts::Exec::linkComponent()
{
    for (auto it : _parser.getParsedLinks()) {
        if (_components.find(it.firstStr) != _components.end() && _components.find(it.secondStr) != _components.end()) {
            _components.find(it.firstStr)->second->setLink(it.firstValue, *_components.find(it.secondStr)->second, it.secondValue);
            _components.find(it.secondStr)->second->setLink(it.secondValue, *_components.find(it.firstStr)->second, it.firstValue);
        }
    }
}

void nts::Exec::display()
{
    std::cout << "tick: " << _tick << std::endl;
    std::cout << "input(s):\n";
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        if (it->second.get() == dynamic_cast<Input *>(it->second.get())) {
            Input *ptr = dynamic_cast<Input *>(it->second.get());
            if (!ptr)
                throw Error("failed to dynamic cast (Input)");
            std::cout << "  " << it->first << ": ";
            std::cout << printTristate(ptr->getValue()) << std::endl;
        }
        if (it->second.get() == dynamic_cast<Clock *>(it->second.get())) {
            Clock *ptr = dynamic_cast<Clock *>(it->second.get());
            if (!ptr)
                throw Error("failed to dynamic cast (Clock)");
            std::cout << "  " << it->first << ": ";
            std::cout << printTristate(ptr->getValue()) << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        if (it->second.get() == dynamic_cast<Output *>(it->second.get())) {
            Output *ptr = dynamic_cast<Output *>(it->second.get());
            if (!ptr)
                throw Error("failed to dynamic cast (Output)");
            std::cout << "  " << it->first << ": ";
            std::cout << printTristate(ptr->getValue()) << std::endl;
        }
    }
}

void nts::Exec::execDump()
{
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        std::cout << "Key ["<< it->first << "]:";
        it->second->dump();
    }
}

void nts::Exec::dump()
{
    this->execDump();
}

void nts::Exec::simulate()
{
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        if (it->second.get() == dynamic_cast<Input *>(it->second.get())) {
            Input *ptr = dynamic_cast<Input *>(it->second.get());
            if (!ptr)
                throw Error("failed to dynamic cast (Input)");
            ptr->simulate(0);
        }
        if (it->second.get() == dynamic_cast<Clock *>(it->second.get())) {
            Clock *ptr = dynamic_cast<Clock *>(it->second.get());
            if (!ptr)
                throw Error("failed to dynamic cast (Clock)");
            ptr->simulate(_tick);
        }
    }
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        if (it->second.get() == dynamic_cast<Output *>(it->second.get())) {
            Output *ptr = dynamic_cast<Output *>(it->second.get());
            if (!ptr)
                throw Error("Failed to dynamic cast (Output)");
            ptr->compute(1);
        }
    }
    _tick += 1;
}
