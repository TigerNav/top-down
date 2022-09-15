#include "MenuState.h"

MenuState::MenuState()
{
	switchMenu = false;
	splashscreen.init();
	splashClock.restart();

	if (!font.loadFromFile(Assets::menufont2))
	{
		std::cout << "shit" << std::endl;
	}

	Start.setString("Start");
	Start.setFont(font);
	Start.setCharacterSize(55);
	Start.setPosition(650, 200);

	

	Options.setString("Options");
	Options.setFont(font);
	Options.setCharacterSize(55);
	Options.setPosition(600, 400);

	Exit.setString("Exit");
	Exit.setFont(font);
	Exit.setCharacterSize(55);
	Exit.setPosition(670, 600);
}
void MenuState::PollEvents()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		menuSelections--;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		menuSelections++;
}
void MenuState::Update()
{
	splashscreen.update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		switchMenu = true;

	splashTime = splashClock.getElapsedTime();

	

	switch (menuSelections)
	{
	case -1:
		menuSelections = 2;
		break;
	case 0:
		Start.setFillColor(sf::Color(0,255,0));
		Options.setFillColor(sf::Color(255,255,255));
		Exit.setFillColor(sf::Color(255,255,255));
		break;
	case 1:
		Start.setFillColor(sf::Color(255,255,255));
		Options.setFillColor(sf::Color(0,255,0));
		Exit.setFillColor(sf::Color(255,255,255));
		break;
	case 2:
		Start.setFillColor(sf::Color(255,255,255));
		Options.setFillColor(sf::Color(255,255,255));
		Exit.setFillColor(sf::Color(0,255,0));
	case 3:
		menuSelections = 0;
		break;
	default:
		break;
	}

	std::cout << menuSelections << std::endl;
}
void MenuState::render(sf::RenderWindow *window)
{
	if (splashTime.asSeconds() >= 0.4 && splashTime.asSeconds() <= 4.5)
	{
		splashscreen.render(window);
	}
	else if (splashTime.asSeconds() >= 4.5)
	{
		window->draw(Start);
		window->draw(Options);
		window->draw(Exit);
	}
	
}