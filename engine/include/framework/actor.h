#pragma once
#include<quill/Logger.h>
#include "framework/object.h"
#include<SFML/Graphics.hpp>
#include"core.h"

namespace ly {
	/*
	class LySprite {
	public:
		LySprite();
		void setTexture(const sf::Texture& texture);
		sf::Sprite& getSprite();
	private:
		unique<sf::Sprite> mSprite;
	};
	*/
	class World;
	class Actor : public Object {
	public:
		Actor(World* ptrOwningWorld, const std::string& texturePath = "");
		void BeginPlayInternal();
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual ~Actor();
		void SetTexture(const std::string& texturePath);
		void Render(sf::RenderWindow& window);
	private:
		World *m_ptrOwningWorld;
		bool m_bBeginPlay;
		quill::Logger* mlogger;
		//ly::LySprite& actorSprite;
		sf::Sprite mSprite;
		sf::Texture m_Texture;
		
	};
}