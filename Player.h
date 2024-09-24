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

    std::map<LandType, int> m_field;

    std::string m_name;
public:
    Player(const std::vector<LandType>& cardTypes, const std::string& username);

    void DrawCard();
    bool PlayCard(LandType cardType);
    bool HasCardInHand(LandType cardType) const;
    // Returns if successfully moves card from hand to graveyard.
    bool DiscardCard(LandType cardType);

    const std::vector<Card>& GetHand() const { return m_hand; }
    const std::map<LandType, int>& GetField() const { return m_field; }

    int GetFieldLandsCount() const;
    int GetGraveyardLandsCount() const { return (int)m_graveyard.size(); }

    std::map<LandType, int> CountHand() const;

    // Card effects to be executed.
    bool DestroyLand(LandType type);
    bool DestroyRandomLand();
    bool ReturnLandFromGraveyard(LandType type);
    bool ReturnRandomLandFromGraveyard();

private:
    void GenerateField();
    void GenerateDeck(const std::vector<LandType>& cardTypes);
    void DrawOpeningHand();

    void ShuffleDeck();
    void MoveGraveyardToDeck();

    // Returns the index of the first card in the hand that matches the card letter.
    // Returns -1 if no card is found.
    int GetHandIndexByLetter(LandType cardType) const;

    static std::map<LandType, int> CountList(std::vector<Card> list);

    void LogMessage(const std::string& message);
};

#endif //PLAYER_H
