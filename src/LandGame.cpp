//
// Created by James McCook on 24/09/2024.
//

#include "LandGame.h"

#include <iostream>

#define DEFAULT_DECK_LIST {Forest, Plains, Mountain, Swamp, Island}

LandGame::LandGame()
    : m_player(DEFAULT_DECK_LIST, "PLAYER")
    , m_playerAI(DEFAULT_DECK_LIST, "AI")
{
}

void LandGame::RunGame()
{
    // Display information
    while (true)
    {
        std::cout << "Player turn!\n" << std::endl;
        TakeTurn_User();
        if (HasPlayerWon(m_player)) {
            std::cout << "Player won!\n" << std::endl;
            break;
        }

        std::cout << "AI turn!\n" << std::endl;
        TakeTurn_AI();
        if (HasPlayerWon(m_playerAI)) {
            std::cout << "AI won!\n" << std::endl;
            break;
        }
    }
}

void LandGame::TakeTurn_User()
{
    OnTurnStart(m_player);
    DisplayUsersContent(m_player, true, true);

    bool bValidTurn = false;

    while (!bValidTurn)
    {
        DisplayTurnControls();
        char input = GetInput();
        bValidTurn = ActionInput(input, m_player, m_playerAI);
    }
}

void LandGame::TakeTurn_AI()
{
    OnTurnStart(m_playerAI);
    // Iterate over hand until we find a card that makes sense to play.
    for (int cardIdx = m_playerAI.GetHand().size() - 1; cardIdx >= 0; cardIdx--) {
        Card* pCard = m_playerAI.GetHand()[cardIdx];
        if (pCard->CanEffectBePlayed(m_playerAI, m_player)) {
            ActionInput(pCard->GetLetterRepresentation(), m_playerAI, m_player);
            if (pCard->GetType() != Forest) // TODO: Migrate to a turn counter system.
                return;
        }
    }
    ActionInput(m_playerAI.GetHand()[0]->GetLetterRepresentation(), m_playerAI, m_player);
}


char LandGame::GetInput()
{
    std::string input;
    std::cin >> input;
    return *input.c_str();
}

void LandGame::OnTurnStart(Player& playersTurn)
{
    // Draw a card
    playersTurn.DrawCard();
}

bool LandGame::ActionInput(const char input, Player& playersTurn, Player& opponentPlayer)
{
    if (input == '?')
    {
        std::cout << "Cards Effects: " << std::endl;
        DisplayCardEffects();

        std::cout << "Players content:" << std::endl;
        DisplayUsersContent(playersTurn, true, true);

        std::cout << "AIs field:" << std::endl;
        DisplayUsersContent(opponentPlayer, true, false);
        return false;
    }

    const CardType type = GetTypeFromLetter(input);
    if (playersTurn.PlayCard(type, opponentPlayer)) {
        // Special case for Forests currently hard coded.
        if (type == Forest)
            return false; // Return false to allow player to play again.

        return true;
    }

    return false;
}

void LandGame::DisplayCardEffects() {
    for (int typeIdx = FIRST; typeIdx < CardType::COUNT; ++typeIdx) {
        CardType type = CardType(typeIdx);
        std::cout << "Card: " << Card::GetName(type) << ", Effect: \n" <<
            Card::GetCardsEffect(type) << std::endl;
    }
}

void LandGame::DisplayTurnControls()
{
    std::cout << "Enter land to play (F, P, M, S, I) or '?' for field recap and information: " << std::endl;
}

void LandGame::DisplayMap(const std::map<CardType, int>& map)
{
    for (const auto& pos : map)
    {
        std::cout << Card::GetLetterRepresentation(pos.first) << " (" <<
            Card::GetName(pos.first) << "):" << pos.second << ", ";
    }
    std::cout << std::endl;
}

void LandGame::DisplayUsersContent(const Player& player, bool bDisplayField, bool bDisplayHand)
{
    if (bDisplayHand)
    {
        std::cout << "Cards in hand: " << std::endl;
        DisplayMap(player.CountHand());
    }
    if (bDisplayField)
    {
        std::cout << "Cards on field: " << std::endl;
        DisplayMap(player.GetField());
    }
    std::cout << "--------------------------" << std::endl;
}

CardType LandGame::GetTypeFromLetter(char input)
{
    switch (std::toupper(input))
    {
    case 'F': return Forest;
    case 'P': return Plains;
    case 'M': return Mountain;
    case 'S': return Swamp;
    case 'I': return Island;
    default:  return NONE;
    }
}

bool LandGame::HasPlayerWon(const Player& player)
{
    int iUniqueLands = 0;
    for (const auto& landPair : player.GetField())
    {
        if (landPair.second >= DUPLICATE_CARDS_NEEDED_FOR_WIN)
            return true;

        if (landPair.second > 0)
            iUniqueLands++;
    }

    return iUniqueLands >= UNIQUE_CARDS_NEEDED_FOR_WIN;
}
