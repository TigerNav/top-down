#include "MenuState.h"

MenuState::MenuState()
{
	switchMenu = false;
	splashscreen.init();
	splashClock.restart();

	if (!font.loadFromFile(Assets::menufont2))
	{
		std::cout << "cant load font" << std::endl;
	}

	mainMenu[0].setString("Start");
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Green);
	mainMenu[0].setCharacterSize(55);
	mainMenu[0].setPosition(650, 200);

	mainMenu[1].setString("Options");
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setCharacterSize(55);
	mainMenu[1].setPosition(600, 400);

	mainMenu[2].setString("Exit");
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setCharacterSize(55);
	mainMenu[2].setPosition(670, 600);


	menuSelections = 0;
}
void MenuState::PollEvents()
{

}
void MenuState::Update()
{
	splashscreen.update();

	splashTime = splashClock.getElapsedTime();


	switch(menuSelections) {
		case -1:
			menuSelections = 2;
			mainMenu[menuSelections].setFillColor(sf::Color::Green);
			break;
		case 3:
			menuSelections = 0;
			mainMenu[menuSelections].setFillColor(sf::Color::Green);
			break;
	}

}
void MenuState::MenuSwitch() {
	switch(menuSelections) {
		case 0:
			switchMenu = true;
			break;
		case 1:
			// options menu
			break;
		case 2:
			exit(0);
			break;
	}
}
void MenuState::render(sf::RenderWindow *window)
{
	if (splashTime.asSeconds() >= 0.4 && splashTime.asSeconds() <= 4.5)
	{
		splashscreen.render(window);
	}
	else if (splashTime.asSeconds() >= 4.5)
	{
		for (int i = 0; i < Max_menu_items; i++)
		{
			window->draw(mainMenu[i]);
		}
	}
}

void MenuState::MoveUp()
{

		mainMenu[menuSelections].setFillColor(sf::Color::White);

		menuSelections--;
		
		mainMenu[menuSelections].setFillColor(sf::Color::Green);
}

void MenuState::MoveDown()
{

		mainMenu[menuSelections].setFillColor(sf::Color::White);
		
		menuSelections++;

		mainMenu[menuSelections].setFillColor(sf::Color::Green);
}