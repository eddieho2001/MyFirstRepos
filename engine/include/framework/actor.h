#pragma once
#include<quill/Logger.h>
#include "framework/object.h"
#include<SFML/Graphics.hpp>

namespace ly {
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
		sf::Sprite m_Sprite;
		sf::Texture m_Texture;
		
	};
}