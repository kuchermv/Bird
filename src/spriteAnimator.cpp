#include "spriteAnimator.h"

#include "spritesheet.h"

SpriteAnimator::SpriteAnimator(sf::Sprite& sprite, float _showTime) : target(sprite) {
	frameIndex = 0;
	showTime = _showTime;
	frames.push_back(target.getTextureRect());
}

void SpriteAnimator::SetFrames(Spritesheet& spriteSheet, std::vector<std::string>& frameNames) {
	if (frameNames.size() <= 0) {
		return;
	}
	frames.clear();
	for(std::string& s : frameNames) {
		sf::IntRect frame = spriteSheet.GetRect(s);
		frames.push_back(frame);
	}
	ResetAnimation();
}

void SpriteAnimator::Tick(float dt) {
	t += dt;
	if (t >= showTime) {
		t -= showTime;
		frameIndex = (frameIndex + 1) % frames.size();
		target.setTextureRect(frames[frameIndex]);
	}
}

void SpriteAnimator::ResetAnimation() {
	frameIndex = 0;
	t = 0.0;
	target.setTextureRect(frames[0]);
}