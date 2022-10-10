/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** 4011
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include "IComponent.hpp"

namespace nts {
    class C4011 : public IComponent {
        public:
            C4011();
            virtual ~C4011();

            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &oter, std::size_t otherPin) override;
        private:
            std::map<size_t, std::pair<IComponent *, size_t>> _link;
    };
}

#endif /* !C4011_HPP_ */