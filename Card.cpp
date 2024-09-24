//
// Created by James McCook on 24/09/2024.
//

#include "Card.h"

Card::Card(LandType t)
    : type(t)
{
}

std::string Card::GetName() const { return GetName(type); }
std::string Card::GetName(LandType typeIn)
{
    switch (typeIn)
    {
        case LandType::Swamp:    return "Swamp";
        case LandType::Forest:   return "Forest";
        case LandType::Plains:   return "Plains";
        case LandType::Island:   return "Island";
        case LandType::Mountain: return "Mountains";
        case LandType::NONE:
            default: return "Unknown";
    }
}

char Card::GetLetter() const { return GetLetter(type); }
char Card::GetLetter(LandType typeIn)
{
    switch (typeIn)
    {
        case LandType::Swamp:    return 'S';
        case LandType::Forest:   return 'F';
        case LandType::Plains:   return 'P';
        case LandType::Island:   return 'I';
        case LandType::Mountain: return 'M';
        default: break;
    }
    return '?';
}
