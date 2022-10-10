/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** INPUT
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "IComponent.hpp"

namespace nts {
    class Input : public IComponent {
        public:
            Input();
            virtual ~Input();

            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &oter, std::size_t otherPin) override;
            void setValue(const std::string &value);
            Tristate getValue() const;
        private:
            std::pair<size_t, size_t> _links;
            IComponent *_component;
            Tristate _value;
            Tristate _oldValue;
    };
}

#endif /* !INPUT_HPP_ */