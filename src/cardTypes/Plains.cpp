//
// Created by James McCook on 24/09/2024.
//

#include "Plains.h"

#include <Player.h>

Plains_Card::Plains_Card()
    : Card(CardType::Plains)
{
}

void Plains_Card::ActionCard(Player &owner, Player &opponent) const {
    owner.ReturnRandomLandFromGraveyard();
}

bool Plains_Card::CanEffectBePlayed(Player &owner, Player &opponent) const {
    // Check owner has a graveyard
    return owner.GetGraveyardLandsCount() > 0;
}
