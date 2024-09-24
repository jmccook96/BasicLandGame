//
// Created by James McCook on 24/09/2024.
//

#ifndef GAMERULEDEFS_H
#define GAMERULEDEFS_H

#include <random>
#include <ctime>

#include "Forest.h"
#include "Island.h"
#include "Mountain.h"
#include "Plains.h"
#include "Swamp.h"

// The number of card types per deck
#define CARD_TYPES_PER_DECK 5

// The number of duplicates of a type card per deck.
#define CARDS_PER_TYPE 7

// Win condition counts.
#define DUPLICATE_CARDS_NEEDED_FOR_WIN 5
#define UNIQUE_CARDS_NEEDED_FOR_WIN 5

inline std::default_random_engine GetRandomEngine() {
    static auto s_rng = std::default_random_engine {};
    s_rng.seed(std::time(nullptr));
    return s_rng;
}

inline CardType GetRandomLandType()
{
    static std::minstd_rand _rand(80085);
    CardType type = CardType(_rand() % COUNT);
    while (type == NONE)
        type = CardType(_rand() % COUNT);

    return type;
}

// This is just fucking gross please don't judge me. TODO: Anything else
inline Card* MakeCardOfType(const CardType& type) {
    switch (type) {
        case CardType::Forest:   return new Forest_Card();
        case CardType::Island:   return new Island_Card();
        case CardType::Mountain: return new Mountain_Card();
        case CardType::Plains:   return new Plains_Card();
        case CardType::Swamp:    return new Swamp_Card();
        default: return nullptr;
    }
}

#endif //GAMERULEDEFS_H
