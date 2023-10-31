#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include "colisionable.h"
#include "Serpiente.h"
#include "Comida.h"
#include "arana.h"



int main(){
    ///srand((unsigned)time(0));
    ///GENERANDO LA VENTANA QUE CORRE EL JUEGO
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    window.setFramerateLimit(60);

    ///FUENTE DEL TEXTO
    sf::Font font;
    font.loadFromFile("SuperSedan.ttf");
    ///TEXTO
    sf::Text texto;
    texto.setFont(font);


    sf::Font gameOverFont;
    gameOverFont.loadFromFile("SuperSedan.ttf");

    sf::Text gameOver;
    gameOver.setFont(gameOverFont);


    ///FONDO
    sf::Sprite fondo;
    sf::Texture texturafondo;
    texturafondo.loadFromFile("fondo.jpg");
    fondo.setTexture(texturafondo);
    fondo.setPosition(0, 40);

    ///FONDO SUPERIOR (PARTE DEL PUNTAJE)
    sf::Sprite fondoTexto;
    sf::Texture texturafondoTexto;
    texturafondoTexto.loadFromFile("fondo2.jpg");
    fondoTexto.setTexture(texturafondoTexto);
    fondoTexto.setPosition(0, 0);


    ///CLASES
    Serpiente serpiente;
    Comida fruta;
    Arana arana;

    int puntos = 0;


    ///COMIENZO DEL GAME LOOP
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        ///DIBUJA POR PANTALLA LOS OBJETOS Y ACTUALIZA LA PANTALLA
        window.draw(fondoTexto);
        window.draw(fondo);
        serpiente.actualizar();
        arana.actualizar();

        if(serpiente.esColision(fruta)){
            fruta.respawn();
            puntos+= 10;
        }
        texto.setString("PTS: "+std::to_string(puntos));

        if(serpiente.esColision(arana)){
            gameOver.setString("GAME OVER!");
            gameOver.setPosition(300, 265);
            window.draw(gameOver);
            system("pause");
        }
        if(serpiente.colisionBordes()){
            gameOver.setString("GAME OVER!");
            gameOver.setPosition(300, 265);
            window.draw(gameOver);
            system("pause");
        }


        window.draw(serpiente);
        window.draw(fruta);
        window.draw(arana);
        window.draw(texto);


        window.display();


    }

    return 0;
}


