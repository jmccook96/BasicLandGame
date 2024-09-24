//
// Created by James McCook on 24/09/2024.
//

#include "Mountain.h"

#include <Player.h>

Mountain_Card::Mountain_Card()
    : Card(CardType::Mountain)
{
}

void Mountain_Card::ActionCard(Player&, Player &opponent) const {
    opponent.DestroyRandomLand();
}

bool Mountain_Card::CanEffectBePlayed(Player&, Player &opponent) const {
    // Check opponent has a field
    return opponent.GetFieldCardCount() > 0;
}


