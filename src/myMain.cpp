#include <iostream>
#include <SFML/Graphics.hpp>
#include <World/Tilemap.h>
#include "myMain.h"
#include <SFML/Graphics.hpp>
#include <Actors/Player.h>
#include <Actors/PlayerCommands/InputHandler.h>
#include <Assets/Definitions.h>
#include <Actors/Enemy.h>
#include <Assets/GameAssets.h>

int myMain()
{
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");

    //---------------------------------
    //Creating the player :
    std::string playerTexturePath = "../../../../resources/Sprites/Player.png";
    auto player = Player(playerTexturePath); //the player is created as a unique pointer
    player.setPosition(sf::Vector2f(0, 0));

    //Creating the input handler associated to the player :
    auto inputHandler = InputHandler();

    //Creating the basic enemy :
    std::string enemyTexturePath = "../../../../resources/Sprites/EnemyPLACEHOLDER.png";
    auto enemy = Enemy(enemyTexturePath);
    enemy.setPosition(sf::Vector2f(200, 200));
    //---------------------------------

    Tilemap tilemap;
    auto* fileName = (char*)"Tilemap.xml";
    auto ga = GameAssets();
    tilemap.buildTilemap(fileName, ga); // mettre dans le test
    //tilemap.draw(window);
    //window.display();
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //-------------------
        window.clear(sf::Color::Black);

        tilemap.draw(window); //drawing the tilemap -> optimisation possible ?
        inputHandler.handleInput(&player, &window); //each frame we call the inputhandler's handle input that will analyse the inputted data and perform the appropriate player's action
        window.draw(enemy.getSprite());
        window.draw(player.getSprite());

        window.display();
        //--------------------
        
        tilemap.selectTile(window, ga);
    }

    return 0;
}