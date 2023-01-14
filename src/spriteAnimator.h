#pragma once

#include <SFML/Graphics.hpp>

class Spritesheet;

class SpriteAnimator {
public:
	SpriteAnimator(sf::Sprite& sprite, float showTime);
	void SetFrames(Spritesheet& spriteSheet, std::vector<std::string>& frameNames);
	void Tick(float dt);
	void ResetAnimation();

private:
	sf::Sprite& target;
	float t;
	float showTime;
	int frameIndex;
	std::vector<sf::IntRect> frames;
};