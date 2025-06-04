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
	}
};