#include "framework/world.h"
#include "framework/actor.h"

#include<quill/Frontend.h>
#include<quill/LogMacros.h>
#include<quill/sinks/ConsoleSink.h>

ly::World::World(Application* ptrOwnedApp)
	: m_ptrOwningApp{ ptrOwnedApp }, 
	  m_beginPlay{false},
	  mActors{},
	  mPendingActors{}
{
	mlogger = quill::Frontend::create_or_get_logger("world", quill::Frontend::create_or_get_sink<quill::ConsoleSink>("sink_id_1"));
	mlogger->set_immediate_flush(true);
}

void ly::World::BeginPlayInternal()
{
	if (!m_beginPlay) {
		m_beginPlay = true;
		BeginPlay();
	}
}

void ly::World::TickInternal(float deltaTime)
{
	for (shared<Actor> actor : mPendingActors) {
		mActors.push_back(actor);
		actor->BeginPlayInternal();
	}

	mPendingActors.clear();
	for (shared<Actor> actor : mActors) {
		actor->Tick(deltaTime);
	}



	Tick(deltaTime);
}

ly::World::~World()
{
}

void ly::World::BeginPlay()
{
	LOG_INFO(mlogger, "Begin play!");
}

void ly::World::Tick(float deltaTime)
{
	LOG_INFO(mlogger, "Tick at frame rate({})", 1.f/deltaTime);
}
