#include <iostream>
#include <string>
#include <vector>

/*  This program is distributed under the 
		
		DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
					Version 2, December 2004
							
	Created by Cian Martin Bohan (@cianmarbo) while being quite board at work on 20/02/2019.
	I don't know what it is or why it exists or why I put it on GitHub. 
*/

enum class GameStates {
	MAIN_MENU,
	NEW_GAME,
	CONTINUE,
	SETTINGS,
	ABOUT,
	QUIT
};

class Game {
private:
	int _select;
	char _optionSelect;
	//bool _quit;
	std::string _menuItem;

public:
	Game();
	void mainMenu();
	void mainMenuSelect(GameStates* gameState, int* _selected);
	std::string printState(GameStates* gameState);
	void quitGame();
	void runGame();
};

Game::Game() {
	mainMenu();
}

void Game::mainMenu() {

	GameStates gameState = GameStates::MAIN_MENU;

	std::cout << "Generic Menu" << std::endl;

	for (int i = 1; i <= 5; i++) {
		switch (i) {
		case 1:
			_menuItem = "New Game";
			break;
		case 2:
			_menuItem = "Continue";
			break;
		case 3:
			_menuItem = "Settings";
			break;
		case 4:
			_menuItem = "About";
			break;
		case 5:
			_menuItem = "Quit";
			break;
		default:
			break;
		}

		std::cout << i << ". " << _menuItem << std::endl;

	}

	std::cout << "---------------------------" << std::endl;
	std::cout << "Please select an option...." << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::cin >> _select;

	std::cout << "---------------------------" << std::endl;

	mainMenuSelect(&gameState, &_select);
	//pass by pointer, no point in copying previously initialised data

}

void Game::mainMenuSelect(GameStates* gameState, int* selected) {
	switch (_select) {
	case 1:
		*gameState = GameStates::NEW_GAME;

		std::cout << printState(gameState) << std::endl;

		runGame();

		break;
	case 2:
		*gameState = GameStates::CONTINUE;

		std::cout << printState(gameState) << std::endl;

		break;
	case 3:
		*gameState = GameStates::SETTINGS;

		std::cout << printState(gameState) << std::endl;

		break;
	case 4:
		*gameState = GameStates::ABOUT;

		std::cout << printState(gameState) << std::endl;

		break;
	case 5:
		*gameState = GameStates::QUIT;

		std::cout << printState(gameState) << std::endl;

		quitGame();

		break;
	default:
		std::cout << "That is an invalid selection. Try again." << std::endl;
		break;
	}
}

std::string Game::printState(GameStates* gameState) {
	std::string state;

	if (*gameState == GameStates::MAIN_MENU) {
		state = "MAIN_MENU";
	}
	else if (*gameState == GameStates::NEW_GAME) {
		state = "NEW_GAME";
	}
	else if (*gameState == GameStates::CONTINUE) {
		state = "CONTINUE";
	}
	else if (*gameState == GameStates::SETTINGS) {
		state = "SETTINGS";
	}
	else if (*gameState == GameStates::ABOUT) {
		state = "ABOUT";
	}
	else if (*gameState == GameStates::QUIT) {
		state = "QUIT";
	}

	return state;
}

void Game::runGame() {

	std::cout << "Yeah bitch so welcome to my game" << std::endl;
	std::cout << "THE RULES:" << std::endl;

}

void Game::quitGame() {
	std::cout << "Are you sure you want to quit?" << std::endl;

	std::cin >> _optionSelect;

	switch (_optionSelect) {
	case 0x59:
		std::cout << "Qutting..." << std::endl;
		break;
	case 0x4E:
		mainMenu();
		break;
	default:
		break;
	}
}

int main() {

	std::cout << "Welcome" << std::endl;

	Game run;

	return 0;
}
