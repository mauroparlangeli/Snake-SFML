#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include "colisionable.h"
#include "Serpiente.h"
#include "Comida.h"
#include "arana.h"
#include "MainMenu.h"
#include "PowerUp.h"

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

    sf::SoundBuffer comerBuffer;
    comerBuffer.loadFromFile("comer.wav");
    sf:: Sound comer;
    comer.setBuffer(comerBuffer);

    sf::SoundBuffer ataqueBuffer;
    ataqueBuffer.loadFromFile("ataque.wav");
    sf:: Sound ataque;
    ataque.setBuffer(ataqueBuffer);



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

    ///FONDO MENU
    sf::Sprite fondoMenu;
    sf::Texture texturaFondo;
    texturaFondo.loadFromFile("fondoMenu.jpeg");
    fondoMenu.setTexture(texturaFondo);
    fondoMenu.setPosition(0, 0);

    ///CLASES
    Serpiente serpiente;
    Comida fruta;
    Arana arana;
    PowerUp powerUp;

    Menu menu(window);
    bool GameStarted=true;
    int puntos = 0;
    int opc;

    ///COMIENZO DEL GAME LOOP

    while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
            GameStarted=true;
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::W) {
                    menu.MoveUp();
                }
                if (event.key.code == sf::Keyboard::S) {
                    menu.MoveDown();
                }
                int selectedIndex = menu.getSelectedItemIndex();
                if (event.key.code == sf::Keyboard::Return) {
                    switch (selectedIndex) {
                        case 0:
                            ///std::cout << "Juego nuevo seleccionado." << std::endl;
                            while(GameStarted){
                            window.draw(fondoTexto);
                            fondo.setPosition(0, 40);
                            window.draw(fondo);
                            serpiente.actualizar();
                            arana.actualizar();
                            powerUp.actualizar();

                            if(serpiente.esColision(fruta)){
                                fruta.respawn();
                                serpiente.aumentarLongitud();
                                comer.setPitch(0.5 + (rand()%10 / 10.f));
                                comer.play();
                                puntos+= 10;
                            }
                            texto.setString("PTS: "+std::to_string(puntos));

                            if(serpiente.esColision(powerUp)){
                                    serpiente.achicarCola();
                                    powerUp.respawn();
                                    comer.setPitch(0.5 + (rand()%10 / 10.f));
                                    comer.play();
                            }


                            if (serpiente.colisionBordes() || serpiente.esColision(arana) || serpiente.colisionCuerpo()) {
                                // Configura un objeto sf::Text para mostrar "GAME OVER" CORREGIR EL GAMEOVER TEXT POR EL GAMEOVER
                                ataque.play();
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
                                GameStarted=false;
                            }


                                window.draw(serpiente);
                                window.draw(fruta);
                                window.draw(arana);
                                window.draw(powerUp);
                                window.draw(texto);
                                window.display();
                            }
                            break;
                        case 1:
                            ///std::cout << "Puntaje mas alto seleccionado." << std::endl;
                            // Aquí puedes mostrar los puntajes más altos
                            break;
                        case 2:
                            window.close(); // Salir del juego
                            break;
                    }
                }
                break;

        }
    }
    window.draw(fondoMenu);
    menu.draw();
}

    return 0;
}


