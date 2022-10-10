/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Parser
*/

#include "Parser.hpp"
#include <algorithm>

nts::Parser::Parser() : _parsing(false)
{
}

nts::Parser::~Parser()
{
}

void nts::Parser::regexParsingComponent(std::string str)
{
    std::vector<std::string> validComponents = {"4001", "4011", "4030", "4069", "4071", "4081", "false", "true", "input", "output", "clock"};

    const std::regex regexStr("^([a-zA-Z\\d]+)\\s+([a-zA-Z\\d_]+)$");
    std::smatch match;
    if (str.empty() || str == ".chipsets:")
        return;
    if (std::regex_search(str, match, regexStr)) {
        std::pair<std::string, std::string> pair;
        pair.first = match[1].str();
        if (std::find(validComponents.begin(), validComponents.end(), match[1]) != validComponents.end()) {
        pair.second = match[2].str();
        _parsedComponents.push_back(pair);
        return;
        }
        throw ErrorParser("Invalid Component");
    }
    throw ErrorParser("Invalid Component");
}

void nts::Parser::checkLinksName()
{
    std::size_t firstStrError = 0;
    std::size_t secondStrError = 0;
    std::string ErrorFirstStr;
    std::string ErrorSecondStr;

    for (auto &s : _parsedLinks) {
        firstStrError = 0;
        secondStrError = 0;
        for (auto &c : _parsedComponents) {
            if (c.second == s.firstStr)
                ++firstStrError;
            if (c.second == s.secondStr)
                ++secondStrError;
        }
        if (firstStrError != 1) {
            ErrorFirstStr = "Unknown component name '" + s.firstStr + "'";
            throw ErrorParser(ErrorFirstStr);
        }
        if (secondStrError != 1) {
            ErrorSecondStr = "Unknown component name '" + s.secondStr + "'";
            throw ErrorParser(ErrorSecondStr);
        }
    }
}

void nts::Parser::regexParsingLinks(std::string str)
{
    const std::regex regexStr("^([a-zA-Z_\\d]+):(\\d)\\s+([a-zA-Z]+):(\\d+)$");
    std::smatch match;
    links_t link;

    if (str.empty() || str == ".links:")
        return;
    if (std::regex_search(str, match, regexStr)) {
        link.firstStr = match[1].str();
        link.firstValue = stoi(match[2].str());
        link.secondStr = match[3].str();
        link.secondValue = stoi(match[4].str());
        _parsedLinks.push_back(link);
        return;
    }
    throw ErrorParser("Invalid Links");
}

void nts::Parser::parseLinks()
{

    for (auto &s: this->getCleanTab()) {
        if (s == ".links:")
            _parsing = true;
        if (_parsing == true)
            this->regexParsingLinks(s);
    }
}

void nts::Parser::parseComponent()
{
    for (auto &s: this->getCleanTab()) {
        if (s == ".links:")
            break;
        this->regexParsingComponent(s);
    }
}

std::vector<std::pair<std::string, std::string>> nts::Parser::getComponents()
{
    return this->_parsedComponents;
}

std::vector<nts::links_t> nts::Parser::getParsedLinks()
{
    return this->_parsedLinks;
}

void nts::Parser::checkShareName()
{
    std::size_t countOccurrences;

    for (auto &s: _parsedComponents) {
            countOccurrences = 0;
        for (auto &c: _parsedComponents) {
            if (s.second == c.second)
                ++countOccurrences;
        }
        if (countOccurrences > 1)
            throw Error("Components can't share the same name");
    }
}

void nts::Parser::parseAll(const std::string &file)
{
    try {
        _cleanTab = this->eraseComment(file);
        this->parseComponent();
        this->parseLinks();
        this->checkShareName();
        this->checkLinksName();
    } catch (Error::exception &e) {
        throw;
    }
}

std::vector<std::string> nts::Parser::getCleanTab()
{
    return this->_cleanTab;
}

std::vector<std::string> nts::Parser::eraseComment(std::string str)
{
    std::fstream nts_file(str, std::ios::in);

    if (!nts_file)
        throw ErrorParser("This file doesn't exist: no such file or directory");
    if (str.substr(str.size() - 4) != ".nts")
        throw ErrorParser("This format is not supported by the requested ressource for the requested method");
    std::string line;
    size_t to_find;
    size_t count = 0;
    size_t good = 0;
    std::vector<std::string> tab;

    while (getline(nts_file, line)) {
        to_find = line.find('#');
        if (to_find != std::string::npos) {
            line.erase(line.begin(), line.end());
            ++count;
        }
        if (good == count) {
            tab.push_back(line);
            --good;
        }
        ++good;
    }
    return (tab);
}


