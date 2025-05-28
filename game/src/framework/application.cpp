#include <framework/application.h>
#include<iostream>

ly::Application::Application(const game_config& config):
	mWindow{sf::RenderWindow{ sf::VideoMode({config.width, config.height}), config.title}},
	mTargetFrameRate{ config .defaultFrameRate},
	mTickClock{}, //default ctor
	mCircle{}
{
	mCircle.setRadius(config.height / 8.f);
	mCircle.setPosition(sf::Vector2f(config.width/8, config.height/8));
	mCircle.setFillColor(sf::Color::Cyan);
}

void ly::Application::Run()
{
	mTickClock.restart();
	float accumulateTime{ 0.f };
	float targetDeltaTime{ 1.f / mTargetFrameRate };
	while (mWindow.isOpen()) {
		while (const std::optional evt = mWindow.pollEvent()) {
			if (evt->is<sf::Event::Closed>()) {
				mWindow.close();
			}
		}

		/*
		 * Code segment check if the computer host is in low frame rate, such as frame rate 30, it will
		 * trigger the condition and call render it.
		 */
		accumulateTime += mTickClock.restart().asSeconds();
		std::cout << "accumulateTime=" << accumulateTime <<", targetDeltaTime="<< targetDeltaTime << std::endl;
		while (accumulateTime > targetDeltaTime) {
			std::cout << "Frame rate too slow, update it double" << std::endl;
			accumulateTime -= targetDeltaTime;
			Tick(targetDeltaTime);
			Render();
		}
		//renderWin.clear();

		//renderWin.draw();

	}
}

void ly::Application::Tick(float deltaTime)
{
	std::cout << "Ticking at frame rate: " << 1.f / deltaTime << std::endl;
}

void ly::Application::Render()
{
	mWindow.clear();
	mWindow.draw(mCircle);
	mWindow.display();

}


