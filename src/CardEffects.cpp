//
// Created by James McCook on 24/09/2024.
//

#include "CardEffects.h"

#include <random>

#include "Player.h"

bool CardEffects::ExecuteEffect(CardType type, Player playerActing, Player targetPlayer)
{
    switch (type)
    {
        case Swamp:  return ExecuteSwamp(playerActing, targetPlayer);
        case Forest: return ExecuteForest(playerActing, targetPlayer);
        case Plains: return ExecutePlains(playerActing, targetPlayer);
        case Island: return ExecuteIsland(playerActing, targetPlayer);
        case Mountain: return ExecuteMountain(playerActing, targetPlayer);
    }
    return false;
}

bool CardEffects::ExecuteSwamp(Player playerActing, Player targetPlayer)
{
    while (!targetPlayer.DiscardCard(GetRandomLandType()));
    return true;
}

bool CardEffects::ExecuteForest(Player playerActing, Player targetPlayer)
{
    // Just want to return to allow user to play again.
    return false;
}

bool CardEffects::ExecutePlains(Player playerActing, Player targetPlayer)
{
    if (playerActing.GetGraveyardLandsCount() == 0)
        return false;

    while (!playerActing.ReturnRandomLandFromGraveyard());
    return true;
}

bool CardEffects::ExecuteIsland(Player playerActing, Player targetPlayer)
{
    playerActing.DrawCard();
    return true;
}

bool CardEffects::ExecuteMountain(Player playerActing, Player targetPlayer)
{
    return targetPlayer.DestroyRandomLand();
}

CardType CardEffects::GetRandomLandType()
{
    static std::minstd_rand _rand(80085);
    CardType type = CardType(_rand() % COUNT);
    if (type == NONE)
        type = CardType(_rand() % COUNT);

    return type;
}
