/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>

namespace nts {

    class Error : virtual public std::exception {
        public:
            Error(std::string const &what);
            Error(const char *what);
            ~Error();
            virtual const char *what() const throw();
        private:
            std::string _what;
    };
}

#endif /* !ERROR_HPP_ */
