//
// Created by James McCook on 24/09/2024.
//

#ifndef CARDEFFECTS_H
#define CARDEFFECTS_H

class Player;
enum LandType : signed char;

class CardEffects
{
public:
    // Returns if the turn
    static bool ExecuteEffect(LandType type, Player playerActing, Player targetPlayer);

    static LandType GetRandomLandType();

private:
    static bool ExecuteSwamp(Player playerActing, Player targetPlayer);
    static bool ExecuteForest(Player playerActing, Player targetPlayer);
    static bool ExecutePlains(Player playerActing, Player targetPlayer);
    static bool ExecuteIsland(Player playerActing, Player targetPlayer);
    static bool ExecuteMountain(Player playerActing, Player targetPlayer);
};

#endif //CARDEFFECTS_H
