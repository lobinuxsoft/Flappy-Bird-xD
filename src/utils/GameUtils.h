#pragma once

namespace GameUtils
{
    const char gameVersion[] = "version 2.0";

    enum class GameState
    {
        MainMenu,
        Gameplay,
        Tutorial,
        Credits,
        Quit
    };
}