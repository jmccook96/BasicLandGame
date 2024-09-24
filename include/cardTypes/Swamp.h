//
// Created by James McCook on 24/09/2024.
//

#ifndef SWAMP_H
#define SWAMP_H

#include <Card.h>

class Swamp_Card final : public Card {
public:
    Swamp_Card();

    void ActionCardName(Player& owner, Player& opponent) const override;
    bool CanEffectBePlayed(Player& owner, Player& opponent) const override;
};

#endif //SWAMP_H
