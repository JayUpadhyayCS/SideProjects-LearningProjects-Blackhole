#pragma once
#include <ctime>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include <SFML\Window.hpp>
class Ball
{
public:
	float velocityX = 0.1;
	float velocityY = 0.1;
	void initCirc();
	sf::CircleShape circle;
	void move();
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();



};
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::RectangleShape rect;
	sf::RectangleShape line;
	Ball ball;
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




