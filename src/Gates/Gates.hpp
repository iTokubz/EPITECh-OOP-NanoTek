/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Gates
*/

#ifndef GATES_HPP_
#define GATES_HPP_

#include "../Component/IComponent.hpp"

namespace nts {

    class Gates {
        public:
            static Tristate Gate4001(Tristate, Tristate);
            static Tristate Gate4011(Tristate, Tristate);
            static Tristate Gate4071(Tristate, Tristate);
            static Tristate Gate4030(Tristate, Tristate);
            static Tristate Gate4081(Tristate, Tristate);
            static Tristate Gate4069(Tristate);
    };
}

#endif /* !GATES_HPP_ */
