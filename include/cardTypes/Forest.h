//
// Created by James McCook on 24/09/2024.
//

#ifndef FOREST_H
#define FOREST_H
#include <Card.h>

class Forest_Card final : public Card {
public:
    Forest_Card();

    void ActionCard(Player& owner, Player& opponent) const override;
    bool CanEffectBePlayed(Player& owner, Player& opponent) const override;
};

#endif //FOREST_H
