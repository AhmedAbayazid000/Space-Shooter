#pragma once 
#include <SFML/Graphics.hpp>
//Enumerator to show the current game screen
enum State {Menu, Playing ,Gameover};

class Game{
    private:
        int highscore;
        int currentscore;
        sf::RenderWindow window;
        State state;
        //Background texture 
        sf::Texture backgroundT;
        // sf::Sprite backgroundS;
        //Diffrent game screens
        void mainmenu();
        void gameover();
        void gamescreen();
        int score;
    public:
        Game();
        int get_highscore();
        void set_highscore(int score);
        void run();

};