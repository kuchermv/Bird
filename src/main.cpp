#include <iostream>
#include <SFML/Graphics.hpp>

#include "spritesheet.h"
#include "background.h"
#include "obstacle.h"
#include "player.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 480), "Bird");
	window.setFramerateLimit(30);

	sf::Clock clock;
	Spritesheet spritesheet;

	sf::Sprite bgSprite;
	spritesheet.InitSprite(bgSprite, "background");
	Background bg(bgSprite, 50);

	Obstacle o;
	spritesheet.InitSprite(o, "rockDown", FlipStatus::FLIPED_XY);
	o.AddPoint(sf::Vector2f(108, 0));
	o.AddPoint(sf::Vector2f(66, 239));
	o.move(300, 0);


	Player player;
	spritesheet.InitSprite(player, "planeRed1");
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
		bg.Tick(dt);
		player.Tick(dt);

		window.clear();
			bg.Draw(window);
			window.draw(player);
			window.draw(o);
			o.DebugDrawPoints(window);
		window.display();
	}
	return 0;
}