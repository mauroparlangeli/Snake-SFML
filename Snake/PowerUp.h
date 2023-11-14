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
    PowerUp(){
    texturaPowerUp.loadFromFile("powerUp.png");
    spritePowerUp.setTexture(texturaPowerUp);
    spritePowerUp.setPosition(rand() % 600 + spritePowerUp.getGlobalBounds().width, rand() % 400 + spritePowerUp.getGlobalBounds().height);
    bool enPantalla = false;
    int tiempo = 60 * 3;
    }

    void reiniciar(){
    texturaPowerUp.loadFromFile("powerUp.png");
    spritePowerUp.setTexture(texturaPowerUp);
    spritePowerUp.setPosition(rand() % 600 + spritePowerUp.getGlobalBounds().width, rand() % 400 + spritePowerUp.getGlobalBounds().height);
    bool enPantalla = false;
    int tiempo = 60 * 3;
    }

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


    void respawn(){
    spritePowerUp.setPosition(rand()%650 + spritePowerUp.getGlobalBounds().width, rand()%400 + spritePowerUp.getGlobalBounds().height);
    }

    sf::FloatRect getBounds()const override{
    return spritePowerUp.getGlobalBounds();
    }

};


#endif // POWERUP_H_INCLUDED
