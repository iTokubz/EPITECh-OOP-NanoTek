/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** printState
*/

#include "printState.hpp"

std::string printTristate(nts::Tristate value)
{
    if (value == nts::FALSE)
        return "0";
    else if (value == nts::TRUE)
        return "1";
    else
        return "U";
}