//
// Created by James McCook on 24/09/2024.
//

#ifndef ISLAND_H
#define ISLAND_H

#include <Card.h>

class Island_Card final : public Card {
public:
    Island_Card();

    void ActionCard(Player& owner, Player& opponent) const override;
    bool CanEffectBePlayed(Player& owner, Player& opponent) const override;
};

#endif //ISLAND_H
