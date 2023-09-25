#pragma once
#include <string>
#include <SFML/Graphics.hpp>


class Card {
    public:
    std::string vName = "NOT ASSIGNED";
    int vValue;
    int vAction; // To steal the card

    Card(std::string vName, int vValue, int vAction) { //Constructor
        vAssign(vName, vValue, vAction);
    }
    Card() {} 

    void vAssign(std::string vName, int vValue, int vAction) {
        this->vName = vName;
        this->vValue = vValue;
        this->vAction = vAction;
    }

    ~Card() {} //Destructor
};

class DeckOfCards {

    int vCardsQuantity = 108;
    Card* vAllCards = nullptr;
    std::string vCardsName[5] = { "Yellow","Red","Green","Blue","Black" };
    sf::RenderWindow window; 

public:
    DeckOfCards(); //Constructor
    void PaintDeck();

    ~DeckOfCards() { //Destructor
        if (vAllCards != nullptr) {
            delete[] vAllCards;
        }
    }
};