//
// Created by James McCook on 24/09/2024.
//

#include "Swamp.h"

#include <Player.h>

Swamp_Card::Swamp_Card()
    : Card(CardType::Swamp)
{
}

void Swamp_Card::ActionCard(Player &owner, Player &opponent) const {
    opponent.DiscardRandomCard();
}

bool Swamp_Card::CanEffectBePlayed(Player &owner, Player &opponent) const {
    // Check opponent has a hand
    for (const auto& pos : opponent.CountHand())
        if (pos.second > 0)
            return true;

    return false;
}


