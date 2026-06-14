#pragma once 
#include <SFML/Graphics.hpp>

// keeps track of which screen we're currently on
enum State {Menu, Playing, Gameover};

// main class that runs the whole game, holds the window and switches between screens
class Game{
    private:
        int highscore;     // best score across this session
        int currentscore;  // score from the last finished run, shown on game over screen
        sf::RenderWindow window;
        State state;
        sf::Texture backgroundT; // shared background image used on all screens

        // the three screens of the game
        void mainmenu();
        void gameover();
        void gamescreen();

    public:
        Game();
        int get_highscore();
        void set_highscore(int score);
        void run(); // main loop
};