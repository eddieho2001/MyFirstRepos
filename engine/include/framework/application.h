#pragma once
#include<SFML/Graphics.hpp>
#include<quill/Logger.h>
#include<framework/core.h>


namespace ly {

	struct game_config {
		unsigned width{600};
		unsigned height{ 980 };
		float defaultFrameRate = 60.f;//same as the target frame rate purpose
		std::string title{ "Light Years" };
		std::string version{ "1.0.0" };
		std::uint32_t windowStyle = sf::Style::Titlebar | sf::Style::Close;
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

		//std::string& GetResourcePath();

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();
	protected:
		virtual void Render();
		virtual void Tick(float deltaTime);
		quill::Logger* mlogger;
	private:
		sf::RenderWindow mWindow;
		//1. the frame rate to be achieved
		float mTargetFrameRate;
		//2. it keep chek the time of current frame
		sf::Clock mTickClock;
		shared<World> currentWorld;
	};
}
