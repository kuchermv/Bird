#include <SFML/Graphics.hpp>

enum class FlipStatus {
	NORMAL, FLIPED_X, FLIPED_Y, FLIPED_XY
};

class Spritesheet {
private:
	sf::Texture tex;
	std::map<std::string, sf::IntRect> items;
public:
	Spritesheet();

	sf::IntRect GetRect(const std::string& name, FlipStatus flipStatus = FlipStatus::NORMAL);
	void InitSprite(sf::Sprite& sprite, const std::string& name, FlipStatus flipStatus = FlipStatus::NORMAL);
};