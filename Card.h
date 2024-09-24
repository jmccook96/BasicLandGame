//
// Created by James McCook on 24/09/2024.
//

#ifndef CARD_H
#define CARD_H

#include <cstdint>
#include <string>

enum LandType : int8_t
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
    LandType type;
public:
    Card(LandType t);

    LandType GetType() const { return type; }

    std::string GetName() const;
    static std::string GetName(LandType type);
    char GetLetter() const;
    static char GetLetter(LandType type);
};


#endif //CARD_H
