//
// Created by James McCook on 24/09/2024.
//

#ifndef MOUNTAIN_H
#define MOUNTAIN_H
#include <Card.h>

class Mountain_Card final : public Card {
public:
    Mountain_Card();

    void ActionCard(Player& owner, Player& opponent) const override;
    bool CanEffectBePlayed(Player& owner, Player& opponent) const override;
};



#endif //MOUNTAIN_H
