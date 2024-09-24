//
// Created by James McCook on 24/09/2024.
//

#include "Forest.h"

Forest_Card::Forest_Card()
    : Card(CardType::Forest)
{
}

void Forest_Card::ActionCardName(Player &owner, Player &opponent) const {
    // TODO: Add 1 to the playable card count for the turn.
}

bool Forest_Card::CanEffectBePlayed(Player&, Player& ) const {
    return true;
}


