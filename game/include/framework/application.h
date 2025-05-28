#pragma once
#include<SFML/Graphics.hpp>

namespace ly {

	struct game_config {
		unsigned width{1024};
		unsigned height{ 780 };
		float defaultFrameRate = 60.f;
		std::string title{ "Light Years" };
		std::string version{ "1.0.0" };
	};

	class Application {
	public:
		Application(const game_config& config);
		void Run();
	private:
		void Tick(float deltaTime);
		void Render();
	private:
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
		sf::CircleShape mCircle;
	};
}
