//
// Created by James McCook on 24/09/2024.
//

#include "Island.h"

#include <Player.h>

Island_Card::Island_Card()
    : Card(CardType::Island)
{
}

void Island_Card::ActionCard(Player &owner, Player&) const {
    owner.DrawCard();
}

bool Island_Card::CanEffectBePlayed(Player&, Player&) const {
    // TODO: Check if able to draw a card?
    return true; // Can always be played
}
