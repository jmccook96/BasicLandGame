//
// Created by James McCook on 24/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <vector>
#include "Card.h"
#include "GameRuleDefs.h"

class Player
{
    std::vector<Card> m_hand;
    std::vector<Card> m_deck; // TODO: Consider migrating deck logic to a standalone class.
    std::vector<Card> m_graveyard;

    std::map<CardType, int> m_field;

    std::string m_name;
public:
    Player(const std::vector<CardType>& cardTypes, const std::string& username);

    void DrawCard();
    bool PlayCard(CardType cardType);
    bool HasCardInHand(CardType cardType) const;
    // Returns if successfully moves card from hand to graveyard.
    bool DiscardCard(CardType cardType);

    const std::vector<Card>& GetHand() const { return m_hand; }
    const std::map<CardType, int>& GetField() const { return m_field; }

    int GetFieldLandsCount() const;
    int GetGraveyardLandsCount() const { return (int)m_graveyard.size(); }

    std::map<CardType, int> CountHand() const;

    // Card effects to be executed.
    bool DestroyLand(CardType type);
    bool DestroyRandomLand();
    bool ReturnLandFromGraveyard(CardType type);
    bool ReturnRandomLandFromGraveyard();

private:
    void GenerateField();
    void GenerateDeck(const std::vector<CardType>& cardTypes);
    void DrawOpeningHand();

    void ShuffleDeck();
    void MoveGraveyardToDeck();

    // Returns the index of the first card in the hand that matches the card letter.
    // Returns -1 if no card is found.
    int GetHandIndexByLetter(CardType cardType) const;

    static std::map<CardType, int> CountList(std::vector<Card> list);

    void LogMessage(const std::string& message);
};

#endif //PLAYER_H
