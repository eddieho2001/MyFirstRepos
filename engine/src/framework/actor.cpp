#include "framework/actor.h"
#include<quill/Frontend.h>
#include<quill/LogMacros.h>
#include<quill/sinks/ConsoleSink.h>

ly::Actor::Actor(World* ptrOwningWorld, const std::string& texturePath)
	:m_ptrOwningWorld{ ptrOwningWorld }, m_Texture{}, mSprite{}
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
	LOG_INFO(mlogger, "Input image path = {}", texturePath);
	m_Texture.loadFromFile(texturePath);
	int textureWidth = m_Texture.getSize().x;
	int textureHeight = m_Texture.getSize().y;
	mSprite.setTexture(m_Texture);
	
	
	mSprite.setTextureRect(sf::IntRect{sf::Vector2i{} , sf::Vector2i{textureWidth,   textureHeight}});

}

void ly::Actor::Render(sf::RenderWindow& window)
{
	window.draw(mSprite);
}
/*
ly::LySprite::LySprite()
{
	
}

void ly::LySprite::setTexture(const sf::Texture& texture) {
	mSprite = std::make_unique<sf::Sprite>(texture);
}

sf::Sprite& ly::LySprite::getSprite() {
	return *mSprite;
}
*/