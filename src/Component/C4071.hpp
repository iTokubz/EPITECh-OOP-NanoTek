/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** 4071
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "IComponent.hpp"

namespace nts {
    class C4071 : public IComponent {
        public:
            C4071();
            virtual ~C4071();
            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &oter, std::size_t otherPin) override;
        private:
            std::map<std::size_t, std::pair<IComponent *, std::size_t>> _link;
    };
}

#endif /* !C4071_HPP_ */
