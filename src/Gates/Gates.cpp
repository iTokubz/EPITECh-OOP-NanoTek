/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-axel.derbisz
** File description:
** Gate4001
*/

#include "Gates.hpp"

nts::Tristate nts::Gates::Gate4001(Tristate firstValue, Tristate secondValue)
{
    if (firstValue == TRUE || secondValue == TRUE)
        return (FALSE);
    if (firstValue == FALSE && secondValue == FALSE)
        return (TRUE);
    return (UNDEFINED);
}

nts::Tristate nts::Gates::Gate4011(Tristate firstValue, Tristate secondValue)
{
    if (firstValue == TRUE && secondValue == TRUE)
        return (FALSE);
    if (firstValue == FALSE || secondValue == FALSE)
        return (TRUE);
    return (UNDEFINED);
}

nts::Tristate nts::Gates::Gate4071(Tristate firstValue, Tristate secondValue)
{
    if (firstValue == FALSE && secondValue == FALSE)
        return (FALSE);
    if (firstValue == TRUE || secondValue == TRUE)
        return (TRUE);
    return (UNDEFINED);
}

nts::Tristate nts::Gates::Gate4030(Tristate firstValue, Tristate secondValue)
{
    if (firstValue == UNDEFINED || secondValue == UNDEFINED)
        return (UNDEFINED);
    if (firstValue != secondValue)
        return (TRUE);
    return (FALSE);
}

nts::Tristate nts::Gates::Gate4069(Tristate firstValue)
{
    if (firstValue == UNDEFINED)
        return (UNDEFINED);
    if (firstValue == TRUE)
        return (FALSE);
    return (TRUE);
}

nts::Tristate nts::Gates::Gate4081(Tristate firstValue, Tristate secondValue)
{
    if (firstValue == FALSE || secondValue == FALSE)
        return (FALSE);
    else if (firstValue == TRUE && secondValue == TRUE)
        return (TRUE);
    return (UNDEFINED);
}