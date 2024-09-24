//
// Created by James McCook on 24/09/2024.
//

#ifndef CARD_H
#define CARD_H

#include <cstdint>
#include <string>

enum CardType : int8_t
{
    NONE,
    Forest,
    Plains,
    Mountain,
    Swamp,
    Island,
    COUNT
};

class Card
{
    CardType type;
public:
    Card(CardType t);

    CardType GetType() const { return type; }

    std::string GetName() const;
    static std::string GetName(CardType type);
    char GetLetter() const;
    static char GetLetter(CardType type);
};


#endif //CARD_H
