#pragma once
#include<quill/Logger.h>
#include<SFML/Graphics.hpp>
#include "framework/core.h"

namespace ly {
	class Application;
	//represent level
	class Actor;
	class World {
	public:
		World(Application* ptrOwnedApp);
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		virtual ~World();
		void Render(sf::RenderWindow& window);
		template<typename actorType>
		weak<actorType> SpawnActor() {
			shared<actorType> newActor{ new actorType{this} };
			mPendingActors.push_back(newActor);
			return newActor;
		}
	private:
		void BeginPlay();
		void Tick(float deltaTime);
	private:
		Application* m_ptrOwningApp;
		bool m_beginPlay;
		quill::Logger* mlogger;
		List<shared<Actor>> mActors;
		List<shared<Actor>> mPendingActors;
	};
}