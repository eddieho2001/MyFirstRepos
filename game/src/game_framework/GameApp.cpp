#include "game_framework/GameApp.h"
#include "framework/world.h"
#include "framework/actor.h"

ly::Application* GetApplication() {
	//static ly::Application app;
	
	ly::game_config config;
	return new ly::GameApp{ config };
}

namespace ly {
	GameApp::GameApp(game_config& config) :
		ly::Application{ config }
	{
		weak<World> newWorld = RoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		actorToDestory = newWorld.lock()->SpawnActor<Actor>();
		actorToDestory.lock()->SetTexture("D:/MyDocs/GameDev/Udemy/LearnC++AndMakeaGameFromScratch/Section06/LightYearsGameProj/game/assets/SpaceShooterRedux/PNG/playerShip2_green.png");
		counter = 0;
	}
	void GameApp::Tick(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 2.f) {
			if (actorToDestory.expired()) {
				actorToDestory.lock()->Destory();
			}
		}
	}
};