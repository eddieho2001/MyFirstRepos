#include <framework/application.h>
#include<framework/world.h>
#include<iostream>
#include<quill/Frontend.h>
#include<quill/LogMacros.h>
#include<quill/sinks/ConsoleSink.h>


ly::Application::Application(const game_config& config) :
	mWindow{ sf::RenderWindow{ sf::VideoMode({config.width, config.height}), config.title, config.windowStyle} },
	mTargetFrameRate{ config.defaultFrameRate },
	mTickClock{},
	currentWorld {nullptr}//default ctor
{
	
	mlogger = quill::Frontend::create_or_get_logger("app_log", quill::Frontend::create_or_get_sink<quill::ConsoleSink>("sink_id_1"));
	mlogger->set_immediate_flush(true);
}

void ly::Application::Run()
{
	mTickClock.restart();
	float accumulateTime{ 0.f };
	float targetDeltaTime{ 1.f / mTargetFrameRate };
	while (mWindow.isOpen()) {
		sf::Event windowEvent;
		while (mWindow.pollEvent(windowEvent)) {
			if (windowEvent.type == sf::Event::EventType::Closed) {
				mWindow.close();
			}
		}

		/*
		 * Code segment check if the computer host is in low frame rate, such as frame rate 30, it will
		 * trigger the condition and call render it.
		 */
		float frameDeltaTime = mTickClock.restart().asSeconds();
		accumulateTime += frameDeltaTime;
		//std::cout << "accumulateTime=" << accumulateTime <<", targetDeltaTime="<< targetDeltaTime << std::endl;
		//LOG_INFO(mlogger, "accumulateTime({}), targetDeltaTime({}) ", accumulateTime, targetDeltaTime);
		while (accumulateTime > targetDeltaTime) {
			
			//std::cout << "Frame rate too slow, update it double" << std::endl;
			accumulateTime -= targetDeltaTime;
			TickInternal(targetDeltaTime);
			RenderInternal();
		}

		LOG_INFO(mlogger, "Ticking at frame rate: {} - {}", frameDeltaTime, 1.f/frameDeltaTime);
		//renderWin.clear();

		//renderWin.draw();

	}
}

//virtual function
void ly::Application::Render()
{
	/*
	sf::CircleShape mCircle;
	mCircle.setRadius(mWindow.getSize().y / 8.f);
	//mCircle.setOrigin()
	mCircle.setPosition(sf::Vector2f(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f));
	mCircle.setFillColor(sf::Color::Cyan);
	mWindow.draw(mCircle);
	*/
	if (currentWorld) {
		currentWorld->Render(mWindow);
	}
}

//virtual function
void ly::Application::Tick(float deltaTime)
{
	//std::cout << "Ticking at frame rate: " << 1.f / deltaTime << std::endl;
}



void ly::Application::TickInternal(float deltaTime)
{
	
	Tick(deltaTime);
	if (currentWorld) {
		currentWorld->BeginPlayInternal();
		currentWorld->TickInternal(deltaTime);
	}
	
}

void ly::Application::RenderInternal()
{
	mWindow.clear();
	Render();//call vitual function that will be implement by child classes
	mWindow.display();

}


