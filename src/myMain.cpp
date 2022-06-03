#include "myMain.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <World/Tilemap.h>
#include <SFML/Graphics.hpp>
#include <Actors/Player.h>
#include <Assets/Definitions.h>
#include <GameManager.h>


int myMain()
{
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");

    //---------------------------------
    //Creating the game elements :
    
    //Creating the game assets :
    auto ga = GameAssets();

    //Creating the player :
    std::string playerTexturePath = "../../../../resources/Sprites/Player.png";
    auto player = Player(playerTexturePath); //the player is created as a unique pointer

    //Creating the input handler associated to the player :
    auto inputHandler = InputHandler(ga);


    //Creating the basic enemy :
    std::string enemyTexturePath = "../../../../resources/Sprites/EldritchSquidRight.png";
    auto enemy = Enemy(enemyTexturePath);

    //Creating the tilemap :
    Tilemap tilemap;
    auto* fileName = (char*)"Tilemap.xml";
    tilemap.buildTilemap(fileName, ga); // mettre dans le test

    //setting up the player :
    inputHandler.setUpPlayer(&player, &tilemap);

    //Creating the game manager :
    auto gameManager = GameManager(&player, enemy, &inputHandler, &tilemap, &window, &ga);
    //---------------------------------

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // we call the game loop :
        gameManager.gameLoop();
        /*
        //-------------------
        window.clear(sf::Color::Black);
        //drawing the tilemap :
        tilemap.selectTile(window, ga);
        tilemap.draw(window);
        //sf::Vector2i selectedTileCoords = tilemap.getSelectedTileCoords(); //we obtain the currently selected tile

        inputHandler.handleInput(&player, &window, &tilemap); //each frame we call the inputhandler's handle input that will analyse the inputted data and perform the appropriate player's action
        window.draw(enemy.getSprite());
        window.draw(player.getSprite());

        window.display();
        //--------------------
        */
    }

    return 0;
}