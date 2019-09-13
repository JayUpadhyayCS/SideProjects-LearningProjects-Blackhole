#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include <SFML\Window.hpp>

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::RectangleShape rect;
	sf::RectangleShape line;
	void initWindow();
	void initShape();
public:
	Game();
	virtual ~Game();
	// Functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

