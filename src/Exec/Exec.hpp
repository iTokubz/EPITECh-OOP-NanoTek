/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Exec
*/

#ifndef EXEC_HPP_
#define EXEC_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include "../Factory/Factory.hpp"
#include "../Parser/Parser.hpp"

namespace nts {

    class Exec {
        public:
            Exec(std::string &file);
            ~Exec();
            size_t getPower();
            void simulate();
            void exit();
            void dump();
            void display();
            void loop();
            void shellExec(std::string &exec);
            void execDump();
            void fillMap();
            void linkComponent();

        private:
            size_t _power;
            Factory _factory;
            Parser _parser;
            std::size_t _tick;
            std::map<std::string, std::unique_ptr<IComponent>> _components;
    };

}
#endif /* !EXEC_HPP_ */
