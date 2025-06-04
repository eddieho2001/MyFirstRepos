#pragma once
#include<SFML/Graphics.hpp>
#include<quill/Logger.h>
#include<framework/core.h>

namespace ly {

	struct game_config {
		unsigned width{1024};
		unsigned height{ 780 };
		float defaultFrameRate = 60.f;
		std::string title{ "Light Years" };
		std::string version{ "1.0.0" };
	};

	class World;
	class Application {
	public:
		Application(const game_config& config);
		void Run();

		template<typename worldType>
		weak< worldType> RoadWorld() {
			shared<worldType> newWorld{ new worldType{this} };
			currentWorld = newWorld;
			return newWorld;
		}

	private:
		void _Tick(float deltaTime);
		void _Render();
	protected:
		virtual void Render();
		virtual void Tick(float deltaTime);
		quill::Logger* mlogger;
	private:
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
		shared<World> currentWorld;
	};
}
