/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "IComponent.hpp"

namespace nts {

    class Clock  : public IComponent {
        public:
            Clock();
            virtual ~Clock();
            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
            void setValue(const std::string &value);
            Tristate getValue() const;
        private:
            std::pair<std::size_t, std::size_t> _links;
            IComponent *_component;
            Tristate _value;
            Tristate _oldValue;
            Tristate _realValue;
    };
}

#endif /* !CLOCK_HPP_ */
