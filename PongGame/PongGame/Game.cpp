#include "Game.h"

// Static Functions


//Initializer functions
void Game::initWindow()
{
	this->initShape();
	// Create sfml window from window.ini file
	this->window= new sf::RenderWindow(sf::VideoMode(700, 400), "PingPong");// Pointer to window.// Creates a window.
	window->clear(sf::Color::Blue);
	window->draw(rect);
	window->draw(line);
}

void Game::initShape()
{
	ball.initCirc();
	rect.setSize(sf::Vector2f(512.f, 212.f));
	rect.setFillColor(sf::Color::Black);
	rect.setPosition(94.f, 93.f);
	line.setSize(sf::Vector2f(212, 5));
	line.rotate(90);
	line.setFillColor(sf::Color::White);
	line.setPosition(350.f, 93.f);
}
void Ball::initCirc()
{
	circle.setRadius(10);
	circle.setFillColor(sf::Color(150, 50, 250));
	circle.setPosition(350.f, 199.f);
	circle.setFillColor(sf::Color::Red);
}

//Constructors/Destrutors
Game::Game()
{
	// When game starts initialize window
	
	this->initWindow();
}


Game::~Game()
{
	// delete window when game ends
	delete this->window;
}

// Functions
void Game::updateSFMLEvents()
{
	// check all the window's events that were triggered since the last iteration of the loop
	while (this->window->pollEvent(this->sfEvent))
	{
		// "close requested" event: we close the window
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	// To check the state of event
	this->updateSFMLEvents();
	ball.move();
}

void Game::render()
{
	// Clear
	this->window->clear(sf::Color::Blue);
	this->window->draw(rect);
	this->window->draw(line);
	this->window->draw(ball.circle);
	// Render items
	this->window->display();
}

void Game::run()
{
	// While the game is running, update it and render it onto screen
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
void Ball::move()
{
	
	float moveX;
	float moveY;
	moveX=circle.getPosition().x;
	moveY=circle.getPosition().y;
	if (moveY >= 285|| moveY<=90)// Left off here.
		setY(-getY());
	if (moveX >= 590 || moveX<=94)// 
		setX(-getX());

	moveY+=getY();
	moveX+=getX();
	circle.setPosition(moveX, moveY);
}

void Ball::setX(float x)
{
	this->velocityX = x;
}

void Ball::setY(float y)
{
	this->velocityY = y;
}

float Ball::getX()
{
	return this->velocityX;
}

float Ball::getY()
{
	return this->velocityY;
}
