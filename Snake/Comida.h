#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED
#include "colisionable.h"

class Comida: public sf::Drawable, public colisionable{
private:
    sf::Sprite spriteComida;
    sf::Texture texturaComida;

public:
    ///INICIALIZA LA COMIDA
    Comida(){
    texturaComida.loadFromFile("comida.png");
    spriteComida.setTexture(texturaComida);
    spriteComida.setPosition(rand()%650 + spriteComida.getGlobalBounds().width, rand()%400 + spriteComida.getGlobalBounds().height);
    }

    ///DIBUJA LA COMIDA
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(spriteComida, states);
    }

    ///RESPAWNEA LA COMIDA
    void respawn(){
    spriteComida.setPosition(rand()%650 + spriteComida.getGlobalBounds().width, rand()%400 + spriteComida.getGlobalBounds().height);
    }

    ///DEVUELVE LOS BORDES DE LA "SKIN" DE LA COMIDA
    sf::FloatRect getBounds()const override{
    return spriteComida.getGlobalBounds();
    }

};

#endif // COMIDA_H_INCLUDED
