/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <memory>
#include <vector>
#include <functional>
#include <iostream>
#include <ostream>
#include "../Component/IComponent.hpp"
#include "../Component/C4001.hpp"
#include "../Component/C4011.hpp"
#include "../Component/C4081.hpp"
#include "../Component/C4030.hpp"
#include "../Component/C4071.hpp"
#include "../Component/Input.hpp"
#include "../Component/Output.hpp"
#include "../Component/True.hpp"
#include "../Component/False.hpp"
#include "../Component/Clock.hpp"
#include "../Component/C4069.hpp"

namespace nts {

    class Factory {
        public:
            Factory();
            static std::unique_ptr<nts::IComponent> createComponent(const std::string &name);

        private:
            static std::unique_ptr<IComponent> createFalse();
            static std::unique_ptr<IComponent> createTrue();
            // std::unique_ptr<IComponent> createClock();
            // std::unique_ptr<IComponent> create4040();
            // std::unique_ptr<IComponent> create4069();
            static std::unique_ptr<IComponent> createClock();
            static std::unique_ptr<IComponent> create4071();
            static std::unique_ptr<IComponent> create4001();
            static std::unique_ptr<IComponent> create4011();
            static std::unique_ptr<IComponent> create4069();
            static std::unique_ptr<IComponent> create4030();
            static std::unique_ptr<IComponent> create4081();
            static std::unique_ptr<IComponent> createInput();
            static std::unique_ptr<IComponent> createOutput();
    };
}

#endif /* !FACTORY_HPP_ */
