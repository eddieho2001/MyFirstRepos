#include "framework/actor.h"
#include<quill/Frontend.h>
#include<quill/LogMacros.h>
#include<quill/sinks/ConsoleSink.h>

ly::Actor::Actor(World* ptrOwningWorld, const std::string& texturePath)
	:m_ptrOwningWorld{ ptrOwningWorld }, m_Texture{}, m_Sprite{}
{
	mlogger = quill::Frontend::create_or_get_logger("actor", quill::Frontend::create_or_get_sink<quill::ConsoleSink>("sink_id_1"));
	mlogger->set_immediate_flush(true);
	SetTexture(texturePath);
	
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
	LOG_INFO(mlogger, "Actor Destory!");
}

void ly::Actor::SetTexture(const std::string& texturePath)
{
	m_Texture.loadFromFile(texturePath);
	int x = m_Texture.getSize().x;
	int y = m_Texture.getSize().y;
	m_Sprite.setTextureRect(sf::IntRect{ sf::Vector2i{} , sf::Vector2i{ x,   y} });

}

void ly::Actor::Render(sf::RenderWindow& window)
{
	window.draw(m_Sprite);
}
