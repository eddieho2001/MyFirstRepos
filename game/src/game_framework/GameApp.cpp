#include "game_framework/GameApp.h"
#include "framework/world.h"
#include "framework/actor.h"
#include<filesystem>

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
		//std::string path = std::filesystem::current_path().string() + "\\" + "playerShip2_green.png";
		actorToDestory.lock()->SetTexture("D:\\MyDocs\\GameDev\\Udemy\\LearnC++AndMakeaGameFromScratch\\Section06\\LightYearsGameProj\\resource\\assets\\SpaceShooterRedux\\PNG\\playerShip1_blue.png");
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