#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

class MainMenu : public sf::Drawable {
private:

    sf::Text tituloJuego;
    sf::Text juegoNuevo;
    sf::Text puntajeAlto;
    sf::Text salirJuego;

public:

    MainMenu(sf::Font& font); // Constructor
    int MouseEvent(const sf::Event& event);
    bool getGame();
    bool getMaxScore();
    bool getExit();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(tituloJuego, states);
        target.draw(juegoNuevo, states);
        target.draw(puntajeAlto, states);
        target.draw(salirJuego, states);
    }
};

MainMenu::MainMenu(sf::Font& font) {

    tituloJuego.setFont(font);
    tituloJuego.setCharacterSize(50);
    tituloJuego.setString("BIENVENIDO A SNAKE !");
    tituloJuego.setPosition(130, 100);

    juegoNuevo.setFont(font);
    juegoNuevo.setCharacterSize(30);
    juegoNuevo.setString("Juego Nuevo");
    juegoNuevo.setPosition(280, 200);

    puntajeAlto.setFont(font);
    puntajeAlto.setCharacterSize(30);
    puntajeAlto.setString("Puntaje Más Alto");
    puntajeAlto.setPosition(280, 250);

    salirJuego.setFont(font);
    salirJuego.setCharacterSize(30);
    salirJuego.setString("Salir del Juego");
    salirJuego.setPosition(280, 300);
}



int MainMenu::MouseEvent(const sf::Event& event) {

    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition();
        if (juegoNuevo.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        return 1;
        }
        else if (puntajeAlto.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        return 2;
        }
        else if (salirJuego.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        return 3;
        }
    }
}


#endif // MAINMENU_H_INCLUDED
