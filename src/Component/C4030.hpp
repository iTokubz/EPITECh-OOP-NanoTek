/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** 4030
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "IComponent.hpp"

namespace nts {

    class C4030 : public IComponent {
        public:
            C4030();
            virtual ~C4030();

            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &oter, std::size_t otherPin) override;
        private:
            std::map<size_t, std::pair<IComponent *, size_t>> _link;
    };
}

#endif /* !C4030_HPP_ */