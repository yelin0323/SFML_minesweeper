#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>

#include <iostream>

using namespace std;
using namespace sf;

//sf::Vector2f v1(16.5f, 24.f);

int main()
{
	RenderWindow window(VideoMode(500, 500), "Hello SFML");
	RectangleShape shape(Vector2f(50, 50));
	//shape.setSize(sf::Vector2f(100, 100));
	//CircleShape shape(100.0f);
	shape.setFillColor(Color::Green);

	sf::Texture texture;
	shape.setTexture(&texture);
	texture.loadFromFile("bomb.png", IntRect(0, 0, 100, 100));
	shape.setTexture(NULL);

	while (window.isOpen())
	{

		window.clear();
		window.draw(shape);
		window.display();
	}

	//sf::Image image;
	/*
		sf::Texture texture;
	if (!texture.loadFromFile("bomb.png", sf::IntRect(10, 10, 32, 32)))
	{
		sf::Uint8* pixels = new sf::Uint8[100 *	100 * 4];
		texture.update(pixels);
		texture.update(image);
		sf::RenderWindow window;
		texture.update(window);

		//while (window.isOpen())
		//{
		//	sf::Event event;
		//	while (window.pollEvent(event))
		//	{
		//		if (event.type == sf::Event::Closed)
		//			window.close();
		//	}

		//	window.clear();
		//	window.draw(shape);
		//	window.display();
		//}
	}
	*/

	return 0;
}