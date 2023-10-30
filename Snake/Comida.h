#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED
#include "colisionable.h"

class Comida: public sf::Drawable, public colisionable{
private:
    sf::Sprite spriteComida;
    sf::Texture texturaComida;

public:
    Comida(){
    texturaComida.loadFromFile("comida.png");
    spriteComida.setTexture(texturaComida);
    spriteComida.setPosition(rand()%700 + spriteComida.getGlobalBounds().width, rand()%500 + spriteComida.getGlobalBounds().height);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(spriteComida, states);
    }

    void respawn(){
    spriteComida.setPosition(rand()%700 + spriteComida.getGlobalBounds().width, rand()%500 + spriteComida.getGlobalBounds().height);
    }

    sf::FloatRect getBounds()const override{
    return spriteComida.getGlobalBounds();
    }

};

#endif // COMIDA_H_INCLUDED
