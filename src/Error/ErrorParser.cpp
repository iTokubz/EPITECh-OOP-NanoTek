/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** ErrorParser
*/

#include "ErrorParser.hpp"

nts::ErrorParser::ErrorParser(std::string const &what): Error(what)
{
}

nts::ErrorParser::ErrorParser(const char *what): Error(what)
{
}

nts::ErrorParser::~ErrorParser()
{
}