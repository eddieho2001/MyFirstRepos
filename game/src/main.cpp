#include<iostream>
#include<SFML/Graphics.hpp>
#include <framework/application.h>
#include<memory>

int main(){
	ly::game_config config;
	std::unique_ptr<ly::Application> gameApp = std::make_unique<ly::Application>(config);
	gameApp->Run();
	
	/*
	sf::RenderWindow renderWin{ sf::VideoMode({500, 700}), "Test Win"};
	while (renderWin.isOpen()) {
		while (const std::optional evt = renderWin.pollEvent()) {
			if (evt->is<sf::Event::Closed>()) {
				renderWin.close();
			}
		}

		//renderWin.clear();

		//renderWin.draw();
		
	}
	*/
	//std::cout<<"Testing...3"<<std::endl;
	
	return 0;
}