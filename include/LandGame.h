//
// Created by James McCook on 24/09/2024.
//

#ifndef LANDGAMEDEMO_H
#define LANDGAMEDEMO_H

#include "Player.h"

class LandGame
{
    Player m_player, m_playerAI;
public:
    LandGame();

    void RunGame();

private:
    void TakeTurn_User();
    void TakeTurn_AI();

    static char GetInput();

    static void OnTurnStart(Player& playersTurn);

    static bool ActionInput(char input, Player& playersTurn, Player& opponentPlayer);

    static void DisplayTurnControls();
    static void DisplayMap(const std::map<CardType, int>& map);
    static void DisplayUsersContent(const Player& player, bool bDisplayField, bool bDisplayHand);

    static CardType GetTypeFromLetter(char input);
    static bool HasPlayerWon(const Player& player);
};


#endif //LANDGAMEDEMO_H
