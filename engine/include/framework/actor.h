#pragma once
#include<quill/Logger.h>

namespace ly {
	class World;
	class Actor {
	public:
		Actor(World *ptrOwningWorld);
		void BeginPlayInternal();
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
	private:
		World *m_ptrOwningWorld;
		bool m_bBeginPlay;
		quill::Logger* mlogger;
	};
}