/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include "../Error/ErrorParser.hpp"

namespace nts {

    typedef struct linksData_s {
        std::string firstStr;
        std::size_t firstValue;
        std::string secondStr;
        std::size_t secondValue;
    } links_t;

    class Parser {
        public:
            Parser();
            virtual ~Parser();
            std::vector<std::string> getCleanTab();
            std::vector<std::pair<std::string, std::string>> getComponents();
            std::vector<linksData_s> getParsedLinks();
            std::vector<std::string> eraseComment(std::string str);
            void parseAll(const std::string &file);
            void parseComponent(const std::string &file);
            void parseComponent();
            void checkLinksName();
            void checkShareName();
            void regexParsingLinks(std::string);
            void regexParsingComponent(std::string);
            void parseLinks();
        private:
        bool _parsing;
        std::vector<std::string> _cleanTab;
        std::vector<std::pair<std::string, std::string>> _parsedComponents;
        std::vector<linksData_s> _parsedLinks;
    };
}

#endif /* !PARSER_HPP_ */
