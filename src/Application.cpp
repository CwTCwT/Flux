#include "Application.h"

#include <ctime>
#include <iostream>

int main() {
    Application app;
    app.startGame();
}

void Application::startGame() {
    update();
}

void Application::update() {
    int frames = 0;

    clock_t nextUpdate = clock();
    clock_t lastFpsCount = clock();

    while (!window.isClosed()) {
        int skipped = 0;

        double elapsed = double(clock() - lastFpsCount) / CLOCKS_PER_SEC;

        if (elapsed > 1) {
            lastFpsCount = clock();
            framesPerSecond = frames;
            std::cout << frames << std::endl;
            frames = 0;
        }

        while (clock() > nextUpdate && skipped < maxSkip) {
            currentScene.update();
            nextUpdate += skipTime;
            skipped++;
        }

        renderer.update();

        window.update();
        frames++;
    }
}
