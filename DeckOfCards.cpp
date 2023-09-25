#include "DeckOfCards.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <time.h>

DeckOfCards::DeckOfCards() {
    vAllCards = new Card[vCardsQuantity];
    int iActualCard = 0;
    std::string vColors[4] = { "Yellow", "Red", "Green", "Blue" }; //Assing colors

    for (int i = 0; i < 4; i++) { //Normal cards
        for (int j = 1; j <= 9; j++) {
            vAllCards[iActualCard++].vAssign(vCardsName[i], j, 0);
            vAllCards[iActualCard++].vAssign(vCardsName[i], j, 0);
        }
    }
    for (int i = 0; i < 4; i++) { //Special cards
        for (int j = 0; j < 2; j++) {
            vAllCards[iActualCard++].vAssign(vCardsName[i], -1, 0);
            vAllCards[iActualCard++].vAssign(vCardsName[i], -2, 0);
            vAllCards[iActualCard++].vAssign(vCardsName[i], -3, 2);
        }
    }
    for (int i = 0; i < 4; i++) { //Black Joker cards
        vAllCards[iActualCard++].vAssign("Black", -3, 4);
        vAllCards[iActualCard++].vAssign("Black", -4, 0);
    }

    // Create window
    window.create(sf::VideoMode(1600, 800), "UNO GAME");
    
}

void DeckOfCards::PaintDeck() {
    // Load card textures
    sf::Texture cardTextures[108];
    sf::Sprite cardSprites[108];

    for (int i = 0; i < 108; i++) {
        std::string fileName = "cartas/carta" + std::to_string(i) + ".png";
        if (!cardTextures[i].loadFromFile(fileName)) {
            // Handle error if the image could not be loaded
        }
        cardSprites[i].setTexture(cardTextures[i]);
    }
      

    float scaleFactor = 0.150f;

    const int cardsPerRow = 20; // Cards per row
    const int numRows = 108 / cardsPerRow; // Total rows

    float cardWidth = cardTextures[0].getSize().x * scaleFactor;
    float cardHeight = cardTextures[0].getSize().y * scaleFactor;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear(sf::Color::White);

        for (int i = 0; i < 108; i++) {
            // Calculate the row and column of the current card
            int row = i / cardsPerRow;
            int col = i % cardsPerRow;

            // Ajust the position cards in row and colums
            float xPos = col * cardWidth;
            float yPos = row * cardHeight;

            cardSprites[i].setPosition(xPos, yPos);
            cardSprites[i].setScale(scaleFactor, scaleFactor);


            window.draw(cardSprites[i]);
        }

        // Display the content of the window
        window.display();
    }
}





