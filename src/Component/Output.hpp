/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "IComponent.hpp"

namespace nts {
    class Output : public IComponent {
        public:
            Output();
            ~Output();

            void simulate(std::size_t tick) override;
            void dump() const override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &oter, std::size_t otherPin) override;
            Tristate getValue() const;
        private:
            std::pair<std::size_t, std::size_t> _links;
            IComponent *_component;
            Tristate _value;
    };
}

#endif /* !OUTPUT_HPP_ */
