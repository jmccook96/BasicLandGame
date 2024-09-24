//
// Created by James McCook on 24/09/2024.
//

#include "Card.h"

Card::Card(CardType t)
    : type(t)
{
}

std::string Card::GetName() const { return GetName(type); }
std::string Card::GetName(CardType typeIn)
{
    switch (typeIn)
    {
        case CardType::Swamp:    return "Swamp";
        case CardType::Forest:   return "Forest";
        case CardType::Plains:   return "Plains";
        case CardType::Island:   return "Island";
        case CardType::Mountain: return "Mountains";
        case CardType::NONE:
            default: return "Unknown";
    }
}

char Card::GetLetter() const { return GetLetter(type); }
char Card::GetLetter(CardType typeIn)
{
    switch (typeIn)
    {
        case CardType::Swamp:    return 'S';
        case CardType::Forest:   return 'F';
        case CardType::Plains:   return 'P';
        case CardType::Island:   return 'I';
        case CardType::Mountain: return 'M';
        default: break;
    }
    return '?';
}
