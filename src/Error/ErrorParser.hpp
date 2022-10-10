/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** ErrorParser
*/

#ifndef ERRORPARSER_HPP_
#define ERRORPARSER_HPP_

#include <string>
#include "Error.hpp"

namespace nts {

    class ErrorParser : public Error{
        public:
            ErrorParser(std::string const &what);
            ErrorParser(const char *what);
            ~ErrorParser();
        private:
            std::string _what;
    };
}

#endif /* !ERRORPARSER_HPP_ */
