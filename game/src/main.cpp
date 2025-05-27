#include<iostream>
#include<SFML/Graphics.hpp>

int main(){

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
	
	//std::cout<<"Testing...3"<<std::endl;
	
	return 0;
}