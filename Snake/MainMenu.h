#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

class Menu {
private:

    sf::RenderWindow& window;
    sf::Font font;
    sf::Text title;
    std::vector<std::string> options;
    std::vector<sf::Text> menuOptions;
    int selectedItemIndex;



public:
    Menu(sf::RenderWindow& window) : window(window), selectedItemIndex(0) {
        font.loadFromFile("SuperSedan.ttf"); // Carga la fuente que deseas utilizar

        // Configura el título del juego
        title.setFont(font);
        title.setCharacterSize(48);
        title.setString("SNAKE");
        title.setPosition(200, 100);

        // Configura las opciones del menú
        options.push_back("Juego nuevo");
        options.push_back("Puntaje mas alto");
        options.push_back("Salir");

        for (int i = 0; i < options.size(); i++) {
            sf::Text option;
            option.setFont(font);
            option.setCharacterSize(32);
            option.setString(options[i]);
            option.setPosition(250, 250 + i * 50);
            menuOptions.push_back(option);
        }

        menuOptions[selectedItemIndex].setFillColor(sf::Color::Red);
    }

    int getSelectedItemIndex() const {
        return selectedItemIndex;
    }

    void draw() {
        window.clear();

        // Dibuja el título
        window.draw(title);

        // Dibuja las opciones del menú
        for (const sf::Text& option : menuOptions) {
            window.draw(option);
        }

        window.display();
    }

    void MoveUp() {
        if (selectedItemIndex - 1 >= 0) {
            menuOptions[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex--;
            menuOptions[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }

    void MoveDown() {
        if (selectedItemIndex + 1 < options.size()) {
            menuOptions[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex++;
            menuOptions[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }


};



#endif // MAINMENU_H_INCLUDED
