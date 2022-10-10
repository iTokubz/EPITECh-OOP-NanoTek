/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** False
*/

#include "IComponent.hpp"

#ifndef FALSE_HPP_
#define FALSE_HPP_

namespace nts {

    class False : public IComponent {
        public:
            False();
            virtual ~False();
            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        private:
            std::pair<std::size_t, std::size_t> _link;
            IComponent *_component;
    };
}

#endif /* !FALSE_HPP_ */