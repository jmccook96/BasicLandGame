//
// Created by James McCook on 24/09/2024.
//

#ifndef CARD_H
#define CARD_H

#include <cstdint>
#include <string>

class Player;

enum CardType : int8_t
{
    NONE,
    Forest,
    Plains,
    Mountain,
    Swamp,
    Island,
    COUNT,

    FIRST = NONE + 1,
};

class Card {
    CardType m_type;
public:
    explicit Card(const CardType &type) : m_type(type) {}
    virtual ~Card() = default;

    [[nodiscard]] const CardType& GetType() const { return m_type; }

    // TODO: Const these.
    virtual void ActionCardName(Player& owner, Player& opponent)    const { }
    virtual bool CanEffectBePlayed(Player& owner, Player& opponent) const { return false; }

    [[nodiscard]] std::string GetName() const          { return GetName(m_type); };
    [[nodiscard]] std::string GetCardsEffect() const   { return GetCardsEffect(m_type); }
    [[nodiscard]] char GetLetterRepresentation() const { return GetLetterRepresentation(m_type); };

    static std::string GetName(CardType type);
    static std::string GetCardsEffect(CardType type);
    static char GetLetterRepresentation(CardType type);
private:
};


#endif //CARD_H
