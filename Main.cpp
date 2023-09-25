#include <SFML/Graphics.hpp>
#include "DeckOfCards.h"
#include <iostream>


int main(int narg, char* arg) {
	int option;
	bool validOption;

	DeckOfCards deckofcards; //Instance of an object

	do {
		system("cls"); //clear the console

		std::cout << "\n      Modo de Juego" << '\n';
		std::cout << "1. Jugador VS Jugador " << '\n';
		std::cout << "2. Jugador VS Computadora " << '\n';


		std::cout << "Ingrese la opcion (1 o 2): ";
		std::cin >> option;
		validOption = true;

		switch (option) {

		case 1:
			std::cout << "MODO Jugador VS Jugador ";
			deckofcards.PaintDeck();
			break;
		case 2:
			std::cout << "MODO Jugador VS Computadora ";
			deckofcards.PaintDeck();
			break;
		default:
			std::cout << "Por favor, digite una opcion valida ";
			validOption = false;
		}

		if(!validOption)
		{
			std::cout << "\nPresione Enter para volver al menu...";
			std::cin.ignore(); 
			std::cin.get();
		}

	} while (!validOption);

	return 0;
}