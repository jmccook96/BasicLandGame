//
// Created by James McCook on 24/09/2024.
//

#ifndef GAMERULEDEFS_H
#define GAMERULEDEFS_H

#include <random>
#include <ctime>

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


#endif //GAMERULEDEFS_H
