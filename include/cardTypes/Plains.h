//
// Created by James McCook on 24/09/2024.
//

#ifndef PLAINS_H
#define PLAINS_H
#include <Card.h>


class Plains_Card final : public Card {
public:
    Plains_Card();

    void ActionCardName(Player& owner, Player& opponent) const override;
    bool CanEffectBePlayed(Player& owner, Player& opponent) const override;
};

#endif //PLAINS_H
