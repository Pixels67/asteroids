#include "Core/Game.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr std::string TITLE= "Asteroids";

int main() {
    Game game({WINDOW_WIDTH, WINDOW_HEIGHT, TITLE});

    while (game.IsRunning()) {
        game.Update(GetFrameTime());
    }
}
