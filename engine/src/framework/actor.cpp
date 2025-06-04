#include "framework/actor.h"
#include<quill/Frontend.h>
#include<quill/LogMacros.h>
#include<quill/sinks/ConsoleSink.h>

ly::Actor::Actor(World* ptrOwningWorld)
	:m_ptrOwningWorld{ ptrOwningWorld }
{
	mlogger = quill::Frontend::create_or_get_logger("actor", quill::Frontend::create_or_get_sink<quill::ConsoleSink>("sink_id_1"));
	mlogger->set_immediate_flush(true);
}

void ly::Actor::BeginPlayInternal()
{
	if (!m_bBeginPlay) {
		m_bBeginPlay = true;
		BeginPlay(); 
	}
}

void ly::Actor::BeginPlay()
{
	LOG_INFO(mlogger, "Begin play!");
}

void ly::Actor::Tick(float deltaTime)
{
	LOG_INFO(mlogger, "Tick at frame rate({})", 1.f / deltaTime);
}

ly::Actor::~Actor()
{
}
