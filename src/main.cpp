#include <regex>
#include <string>
#include <iostream>
#include "Exec/Exec.hpp"
#include "Error/Error.hpp"

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cerr << "Missing arguments" << std::endl;
        return (84);
    }
    std::string exec;
    std::string file(av[1]);
    try {
        nts::Exec Shell(file);
        std::cout << "> ";
        while (Shell.getPower() == 1 && std::getline(std::cin, exec)) {
            if (exec == "exit")
                    break;
            else {
                Shell.shellExec(exec);
            }
            std::cout << "> ";
        }
    } catch (nts::Error::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    } catch (...) {
        std::cerr << "Unknown Error" << std::endl;
        return (84);
    }
}