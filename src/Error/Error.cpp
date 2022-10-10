/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Error
*/

#include "Error.hpp"

nts::Error::Error(std::string const &what) : _what(what)
{
}

nts::Error::Error(const char *what) : _what(std::string(what))
{
}

nts::Error::~Error()
{
}

const char *nts::Error::what() const throw()
{
    return (_what.c_str());
}
