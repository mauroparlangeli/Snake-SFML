#ifndef POWERUP_H_INCLUDED
#define POWERUP_H_INCLUDED
#include "colisionable.h"

class PowerUp: public sf::Drawable, public colisionable{
private:
    sf::Sprite spritePowerUp;
    sf::Texture texturaPowerUp;
    int tiempo;
    bool enPantalla;

public:
    ///INICIALIZA LA COMIDA
    PowerUp(){
    texturaPowerUp.loadFromFile("powerUp.png");
    spritePowerUp.setTexture(texturaPowerUp);
    spritePowerUp.setPosition(-1000, -1000);
    bool enPantalla = true;
    int tiempo = 0;
    }

    ///DIBUJA LA COMIDA
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(spritePowerUp, states);
    }

 void actualizar() {
            tiempo++;

            if (enPantalla == false && tiempo >= 60 * 10) {
                spritePowerUp.setPosition(rand() % 600 + spritePowerUp.getGlobalBounds().width, rand() % 400 + spritePowerUp.getGlobalBounds().height);
                enPantalla = true;
                tiempo = 0;
            } else if (enPantalla == true && tiempo >= 60 * 3) {
                enPantalla = false;
                tiempo = 0;
                spritePowerUp.setPosition(-1000, -1000);
            }
        }

    ///RESPAWNEA LA COMIDA
    void respawn(){
    spritePowerUp.setPosition(rand()%650 + spritePowerUp.getGlobalBounds().width, rand()%400 + spritePowerUp.getGlobalBounds().height);
    }

    ///DEVUELVE LOS BORDES DE LA "SKIN" DE LA COMIDA
    sf::FloatRect getBounds()const override{
    return spritePowerUp.getGlobalBounds();
    }

};


#endif // POWERUP_H_INCLUDED
