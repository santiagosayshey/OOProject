#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"
#include <iostream>

typedef sf::Color c;
typedef sf::Text t;



MenuState::MenuState(Game* game, Player* player):
State(game, player)
{
    splash    = new Sprite(game->getPath()->s_splash,0,0,1280,720,1.5);

    play = new Button(1,"PLAY",50,game);
    quit = new Button(1,"PLAY",50,game);

    s_play    = new Sprite(game->getPath()->s_button,150,400,30,14,7);
    b_play    = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, "PLAY", 185, 430);
    play      = new Text(game->getPath()->f_main, 50, c::White, t::Bold, "PLAY", 190, 425);

    s_quit    = new Sprite(game->getPath()->s_button,150,550,30,14,7);
    b_quit    = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, "QUIT", 170, 580);
    quit      = new Text(game->getPath()->f_main, 50, c::White, t::Bold, "QUIT", 175, 575);

    b_title   = new Text(game->getPath()->f_main, 200, c::Black, t::Bold, "ROGUE", 1000, 425);
    title     = new Text(game->getPath()->f_main, 200, c::White, t::Bold, "ROGUE", 1010, 415);
}

MenuState::~MenuState()
{   
    delete splash;
    delete s_play;
    delete s_quit;
    delete b_play;
    delete b_quit;
    delete play;
    delete quit;
    delete b_title;
    delete title;
}

void MenuState::update(sf::RenderWindow* window)

{

    if (!s_play->checkCollision(window))
    {
        //std::cout << "no collision success" << std::endl;

        s_play ->setPosition(s_play->getX(), s_play->getY());
        b_play ->setPosition(b_play->getX(), b_play->getY());
        play   ->setPosition(play->getX(), play->getY());
        sound1=true;
    }
    else
    {
        while (sound1)
        {
            UI.play();
            sound1=false;
        }
        s_play ->setPosition(s_play->getX()+20, s_play->getY());
        b_play ->setPosition(b_play->getX()+20, b_play->getY());
        play   ->setPosition(play->getX()+20, play->getY());

    }

    if (!s_quit->checkCollision(window))
    {
        //std::cout << "no collision success" << std::endl;
        s_quit ->setPosition(s_quit->getX(), s_quit->getY());
        b_quit ->setPosition(b_quit->getX(), b_quit->getY());
        quit   ->setPosition(quit->getX(), quit->getY());
        sound2=true;
    }
    else
    {
        while (sound2)
        {
            UI.play();
            sound2=false;
        }
        s_quit ->setPosition(s_quit->getX()+20, s_quit->getY());
        b_quit ->setPosition(b_quit->getX()+20, b_quit->getY());
        quit   ->setPosition(quit->getX()+20, quit->getY());
        
    }


    while (window->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonReleased: {
                if (s_play->checkCollision(window)) {
                    UI.play();
                    mus.stop();
                    game->setState(new PickState(game, player));
                    break;
                }
                if (s_quit->checkCollision(window)) {
                    UI.play();
                    window->close();
                    break;
                }
            }
            default:
                break;
        }
        
    }
}


void MenuState::render(sf::RenderWindow* window)
{
    window     ->clear(c::White);

    splash     ->draw(window);
    s_play     ->draw(window);
    b_play     ->draw(window);
    play       ->draw(window);
    s_quit     ->draw(window);
    b_quit     ->draw(window);
    quit       ->draw(window);
    b_title    ->draw(window);
    title      ->draw(window);

    window     ->display();

    //std::cout << "draw successful" << std::endl;
}

