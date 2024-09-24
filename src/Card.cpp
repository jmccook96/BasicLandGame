//
// Created by James McCook on 24/09/2024.
//

#include "Card.h"

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

std::string Card::GetCardsEffect(CardType type) {
    switch (type) {
        case CardType::Swamp:    return "Forces opponent to discard a random card.";
        case CardType::Plains:   return "Returns a random card from graveyard to your hand.";
        case CardType::Mountain: return "Destroys a random card your opponent controls.";
        case CardType::Island:   return "Draws a card.";
        case CardType::Forest: // Fall-through
        default: return "Currently nothing UwU";
    }
    return "";
}

char Card::GetLetterRepresentation(CardType typeIn)
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
