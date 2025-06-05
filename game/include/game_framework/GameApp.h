#pragma once
#include<framework/application.h>

namespace ly {
	class Actor;
	class GameApp : public Application {
	public:
		GameApp(game_config& config );
		virtual void Tick(float deltaTime) override;
	private:
		float counter;
		weak<Actor> actorToDestory;
	};
}