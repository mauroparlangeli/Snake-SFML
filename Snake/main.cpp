#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "colisionable.h"
#include "Serpiente.h"
#include "Comida.h"


int main(){
    ///srand((unsigned)time(0));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    window.setFramerateLimit(60);

    ///FUENTE DEL TEXTO
    sf::Font font;
    font.loadFromFile("SuperSedan.ttf");
    ///TEXTO
    sf::Text texto;
    texto.setFont(font);




    ///FONDO
    sf::Sprite fondo;
    sf::Texture texturafondo;
    texturafondo.loadFromFile("fondo.jpg");
    fondo.setTexture(texturafondo);

    ///CLASES
    Serpiente serpiente;
    Comida fruta;

    int puntos = 0;


    ///GAME LOOP
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fondo);
        serpiente.actualizar();

        if(serpiente.esColision(fruta)){
            fruta.respawn();
            puntos+= 10;
        }
        texto.setString("PUNTOS: "+std::to_string(puntos));

        window.draw(serpiente);
        window.draw(fruta);
        window.draw(texto);


        window.display();


    }

    return 0;
}


