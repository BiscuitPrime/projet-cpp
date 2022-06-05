#pragma once
#include "Actor.h"
#include <Assets/Definitions.h>
#include <World/Tilemap.h>
#include <Actors/Strategy/MovementStrategy.h>
#include <Actors/Strategy/AttackStrategy.h>
#include <Actors/Strategy/ConcreteStrategies/MeleeAttackStrategy.h>
/*
* Enemy class
*/

enum EnemyStates {
	STATE_IDLE,
	STATE_MOVING,
	STATE_ATTACK,
	STATE_DEAD
};

class Enemy : public Actor {
private:
	int movementRange = 3;
	int fleeRange = 2;
	EnemyStates _state;
	MovementStrategy* movementStrategy;
	AttackStrategy* attackStrategy;
	bool isEnemyLoopFinished = true;
	Tilemap* tilemap;
public:
	explicit Enemy(int id,std::string texturePath, Tilemap* tilemap);
	void death() override;
	int getMovementRange() const { return movementRange; }
	EnemyStates getState() const { return _state; };
	void nextState();
	void setState(EnemyStates state) { _state = state; };
	void handleEnemy(Player* player);
	void moveEnemyCommand(sf::Vector2i movement);
	void attackEnemyCommand(int damage, Player* player);
	void setStrategies(sf::Vector2i playerPos);
	bool getEnemyLoopFinished() const { return isEnemyLoopFinished; };
	void startEnemyLoop() { isEnemyLoopFinished = false; }
	void spawn(sf::Vector2i spawnPoint); //method that will spawn the enemy at a given place on the tilemap
	void setUpEnemyOnTilemap(); //method that will tell the tilemap that an enemy is on one of her tiles
	void removeEnemyOnTilemap(); //method that will tell the tilemap that an enemy is not on one of her tiles
	int testNewPositionValidity(sf::Vector2i pos);//function that tests if the new position will be valid
};