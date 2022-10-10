/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** True
*/

#include "IComponent.hpp"

#ifndef TRUE_HPP_
#define TRUE_HPP_

namespace nts {

    class True : public IComponent {
        public:
            True();
            ~True();
            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        private:
            std::pair<std::size_t, std::size_t> _link;
            IComponent *_component;
    };
}

#endif /* !TRUE_HPP_ */
