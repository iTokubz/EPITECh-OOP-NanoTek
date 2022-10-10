/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** IComponent
*/



#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <map>
#include "../Error/Error.hpp"

namespace nts {

    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void dump () const = 0;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute( std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
}


#endif /* !ICOMPONENT_HPP_ */
