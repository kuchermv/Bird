#include <iostream>
#include <SFML/Graphics.hpp>

#include "background.h"
#include "spritesheet.h"
#include "player.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 480), "Bird");
	window.setFramerateLimit(30);

	sf::Clock clock;
	Spritesheet spritesheet;

	Background bg(spritesheet.GetSprite("background"));
	Background bg1(spritesheet.GetSprite("groundDirt", FlipStatus::FLIPED_XY));
	Background bg2(spritesheet.GetSprite("groundGrass"), 480-71);

	Player player(spritesheet.GetSprite("planeRed1"));
	SpriteAnimator& sa = player.GetSpriteAnimator();
	std::vector<std::string> frames{"planeRed1", "planeRed2", "planeRed3"};
	sa.SetFrames(spritesheet, frames);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
				window.close();
			}
		}

		float dt = clock.restart().asSeconds();
		bg.MoveLeft(50.0 * dt);
		bg1.MoveLeft(100.0 * dt);
		bg2.MoveLeft(100.0 * dt);
		player.Tick(dt);

		window.clear();
			window.draw(bg);
			window.draw(bg1);
			window.draw(bg2);
			window.draw(player);
		window.display();
	}
	return 0;
}