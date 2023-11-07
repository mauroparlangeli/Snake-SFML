#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include "colisionable.h"
#include "Serpiente.h"
#include "Comida.h"
#include "arana.h"
#include "MainMenu.h"

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
    fondo.setPosition(0, 0);

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
    MainMenu MenuJuego(font);
    int puntos = 0;
    int opc;

    ///COMIENZO DEL GAME LOOP
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }
/*
        opc=MenuJuego.MouseEvent(event);
        window.draw(fondo);
        window.draw(MenuJuego);
        window.display();*/


/*
        if(MenuJuego.getGame()){
        window.clear();
        window.draw(fondoTexto);
        fondo.setPosition(0, 40);
        window.draw(fondo);
        serpiente.actualizar();
        arana.actualizar();

        if(serpiente.esColision(fruta)){
            fruta.respawn();
            ///serpiente.agregarCola();
            puntos+= 10;
        }
        texto.setString("PTS: "+std::to_string(puntos));


        if (serpiente.colisionBordes() || serpiente.esColision(arana)) {
            // Configura un objeto sf::Text para mostrar "GAME OVER" CORREGIR EL GAMEOVER TEXT POR EL GAMEOVER
            sf::Text gameOverText;
            gameOverText.setFont(font); // Asigna una fuente (debes cargar una fuente previamente)
            gameOverText.setCharacterSize(48); // Tamaño del texto
            gameOverText.setFillColor(sf::Color::Red); // Color del texto
            gameOverText.setString("GAME OVER");
            gameOverText.setPosition(250, 200); // Ajusta la posición del texto

            // Configura otro objeto sf::Text para mostrar la puntuación
            sf::Text scoreText;
            scoreText.setFont(font); // Asigna la misma fuente
            scoreText.setCharacterSize(24); // Tamaño del texto
            scoreText.setFillColor(sf::Color::White); // Color del texto
            scoreText.setString("Puntos: " + std::to_string(puntos));
            scoreText.setPosition(300, 300); // Ajusta la posición del texto de puntuación

            // Dibuja el mensaje de "GAME OVER" y la puntuación en la ventana
            window.draw(gameOverText);
            window.draw(scoreText);

            // Luego, llama a window.display() para mostrar los cambios en la ventana.
            window.display();
            sf::sleep(sf::seconds(2)); // Pausa durante 2 segundos

            window.clear();
        }


            window.draw(serpiente);
            window.draw(fruta);
            window.draw(arana);
            window.draw(texto);
            window.display();
        }*/

       switch(opc){
    case 1:
        ///DIBUJA POR PANTALLA LOS OBJETOS Y ACTUALIZA LA PANTALLA
        window.draw(fondoTexto);
        fondo.setPosition(0, 40);
        window.draw(fondo);
        serpiente.actualizar();
        arana.actualizar();

        if(serpiente.esColision(fruta)){
            fruta.respawn();
            serpiente.agregarCola();
            puntos+= 10;
        }
        texto.setString("PTS: "+std::to_string(puntos));


        if (serpiente.colisionBordes() || serpiente.esColision(arana)) {
            // Configura un objeto sf::Text para mostrar "GAME OVER" CORREGIR EL GAMEOVER TEXT POR EL GAMEOVER
            sf::Text gameOverText;
            gameOverText.setFont(font); // Asigna una fuente (debes cargar una fuente previamente)
            gameOverText.setCharacterSize(48); // Tamaño del texto
            gameOverText.setFillColor(sf::Color::Red); // Color del texto
            gameOverText.setString("GAME OVER");
            gameOverText.setPosition(250, 200); // Ajusta la posición del texto

            // Configura otro objeto sf::Text para mostrar la puntuación
            sf::Text scoreText;
            scoreText.setFont(font); // Asigna la misma fuente
            scoreText.setCharacterSize(24); // Tamaño del texto
            scoreText.setFillColor(sf::Color::White); // Color del texto
            scoreText.setString("Puntos: " + std::to_string(puntos));
            scoreText.setPosition(300, 300); // Ajusta la posición del texto de puntuación

            // Dibuja el mensaje de "GAME OVER" y la puntuación en la ventana
            window.draw(gameOverText);
            window.draw(scoreText);

            // Luego, llama a window.display() para mostrar los cambios en la ventana.
            window.display();
            sf::sleep(sf::seconds(2)); // Pausa durante 2 segundos

            window.clear();
        }


            window.draw(serpiente);
            window.draw(fruta);
            window.draw(arana);
            window.draw(texto);
            window.display();///DIBUJA POR PANTALLA LOS OBJETOS Y ACTUALIZA LA PANTALLA

        break;
    case 2:
        break;
    case 3:
        window.close();
        break;
    default:
        break;
        }




    }

    return 0;
}


