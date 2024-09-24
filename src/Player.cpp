//
// Created by James McCook on 24/09/2024.
//

#include "Player.h"

#include <algorithm>
#include <iostream>
#include <random>

#include "CardEffects.h"

#define LOG std::cout << m_name << ": "

Player::Player(const std::vector<CardType>& cardTypes, const std::string& username)
    : m_name(username)
{
    GenerateField();
    GenerateDeck(cardTypes);
    ShuffleDeck();
    DrawOpeningHand();
}

void Player::GenerateField()
{
    for (int landIndex = (int)CardType::NONE + 1; landIndex < CardType::COUNT; landIndex++)
        m_field.insert_or_assign(CardType(landIndex), 0);
}

void Player::GenerateDeck(const std::vector<CardType>& cardTypes)
{
    for (CardType type : cardTypes)
        for (int cardCount = 0; cardCount < CARDS_PER_TYPE; cardCount++)
            m_deck.emplace_back(type);
}

void Player::DrawCard()
{
    if (m_deck.empty())
        MoveGraveyardToDeck();

    LOG << "Drew a card." << std::endl;
    m_hand.push_back(m_deck.back());
    m_deck.pop_back();
}

bool Player::PlayCard(CardType cardType)
{
    int index = GetHandIndexByLetter(cardType);
    if (index < 0)
        return false;

    m_field[cardType]++;
    LOG << "Played card " << Card::GetName(cardType) << std::endl;
    m_hand.erase(m_hand.begin() + index);
    return true;
}

bool Player::HasCardInHand(CardType cardType) const { return GetHandIndexByLetter(cardType) >= 0; }
bool Player::DiscardCard(CardType cardType)
{
    int index = GetHandIndexByLetter(cardType);
    if (index < 0)
        return false;

    m_graveyard.push_back(m_hand.at(index));
    m_hand.erase(m_hand.begin() + index);
    LOG << "Discarded card " << Card::GetName(cardType) << std::endl;
    return true;
}

int Player::GetFieldLandsCount() const
{
    int iRet = 0;
    for (int landIndex = NONE + 1; landIndex < COUNT; landIndex++)
    {
        auto pos = m_field.find((CardType)landIndex);
        if (pos == m_field.end())
            continue;

        iRet += pos->second;
    }

    return iRet;
}

std::map<CardType, int> Player::CountHand() const { return CountList(m_hand); }

bool Player::DestroyLand(CardType type)
{
    if (m_field[type] > 0)
    {
        m_field[type]--;
        LOG << "Destroyed land.";
        return true;
    }
    return false;
}

bool Player::DestroyRandomLand()
{
    // Ensure a land exists.
    if (GetFieldLandsCount() == 0)
        return false;

    while (!DestroyLand(CardEffects::GetRandomLandType()));
    return true;
}

bool Player::ReturnLandFromGraveyard(CardType type)
{
    for (int index = 0; index < m_graveyard.size(); ++index)
    {
        if (m_graveyard[index].GetType() != type)
            continue;

        m_hand.push_back(m_graveyard[index]);
        m_graveyard.erase(m_graveyard.begin() + index);
        LOG <<  "Returned " << m_hand.back().GetName() << " from graveyard to hand." << std::endl;
        return true;
    }
    return false;
}

bool Player::ReturnRandomLandFromGraveyard()
{
    if (m_graveyard.empty())
        return false;

    while (!ReturnLandFromGraveyard(CardEffects::GetRandomLandType()));
    return true;
}

void Player::DrawOpeningHand()
{
    while (m_hand.size() < 5)
        DrawCard();
}

void Player::ShuffleDeck()
{
    std::shuffle(m_deck.begin(), m_deck.end(), GetRandomEngine());
    LOG << "Deck shuffled!" << std::endl;
}

void Player::MoveGraveyardToDeck()
{
    LOG << "Shuffling graveyard into deck." << std::endl;
    m_deck = m_graveyard;  // Replace deck with the graveyard
    m_graveyard.clear(); // Flush the graveyard
    ShuffleDeck();     // Shuffle the deck
}

int Player::GetHandIndexByLetter(CardType cardType) const
{
    for (int cardIndex = 0; cardIndex < m_hand.size(); cardIndex++)
        if (m_hand[cardIndex].GetType() == cardType)
            return cardIndex;

    return -1;
}

std::map<CardType, int> Player::CountList(std::vector<Card> list)
{
    std::map<CardType, int> counts;
    for (int landIndex = (int)CardType::NONE + 1; landIndex < CardType::COUNT; landIndex++)
        counts.insert_or_assign(CardType(landIndex), 0);

    for (Card card : list)
        counts[card.GetType()]++;

    return counts;
}
