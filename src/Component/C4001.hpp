/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** 4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "IComponent.hpp"

namespace nts {
    class C4001 : public IComponent {
        public:
            C4001();
            virtual ~C4001();
            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &oter, std::size_t otherPin) override;
        private:
            std::map<std::size_t, std::pair<IComponent *, std::size_t>> _link;
    };
}

#endif /* !C4001_HPP_ */
