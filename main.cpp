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

    sf::Text gameOverText;
    gameOverText.setFont(font);

    sf::Text scoreText;
    scoreText.setFont(font);

    sf::Text puntajeMaximoText;
    puntajeMaximoText.setFont(font);

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
    texturafondo.loadFromFile("fondoJuego.jpg");
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
    texturaFondo.loadFromFile("fondoJuego.jpg");
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
    int mayorPuntaje=0;
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
                            serpiente.reiniciar();
                            powerUp.reiniciar();
                            arana.reiniciar();
                            puntos=0;

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
                                    puntos+= 20;
                            }


                            if (serpiente.colisionBordes() || serpiente.esColision(arana) || serpiente.colisionCuerpo()) {

                                ataque.play();

                                gameOverText.setCharacterSize(48);
                                gameOverText.setFillColor(sf::Color::Red);
                                gameOverText.setString("GAME OVER");
                                gameOverText.setPosition(250, 200);

                                scoreText.setCharacterSize(24);
                                scoreText.setFillColor(sf::Color::White);
                                scoreText.setString("Puntos: " + std::to_string(puntos));
                                scoreText.setPosition(300, 300);


                                window.draw(gameOverText);
                                window.draw(scoreText);
                                if(puntos>mayorPuntaje){mayorPuntaje=puntos;}
                                // Luego, llama a window.display() para mostrar los cambios en la ventana.
                                window.display();
                                sf::sleep(sf::seconds(3)); // Pausa durante 2 segundos

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
                            window.clear();
                            puntajeMaximoText.setCharacterSize(24);
                            puntajeMaximoText.setFillColor(sf::Color::White);
                            puntajeMaximoText.setString("Mayor puntaje: " + std::to_string(mayorPuntaje));
                            puntajeMaximoText.setPosition(290, 200);
                            window.draw(puntajeMaximoText);
                            window.display();
                            sf::sleep(sf::seconds(2));
                        break;

                        case 2:
                            window.close();
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

