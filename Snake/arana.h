#ifndef ARANA_H_INCLUDED
#define ARANA_H_INCLUDED
#include "colisionable.h"

class Arana: public sf::Drawable, public colisionable{
private:
    sf::Sprite spriteArana;
    sf::Texture texturaArana;

public:
    ///INICIALIZA LA ARANA (CAMBIAR SKIN Y HACER QUE SE MUEVA O RESPAWNEE DESPUES DE CIERTO TIEMPO)
    Arana(){
    texturaArana.loadFromFile("serpiente.png");
    spriteArana.setTexture(texturaArana);
    spriteArana.setPosition(rand()%650 + spriteArana.getGlobalBounds().width, rand()%400 + spriteArana.getGlobalBounds().height);
    }

    ///DIBUJA LA ARANA
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(spriteArana, states);
    }

    ///RESPAWNEA LA ARANA
    void respawn(){
    spriteArana.setPosition(rand()%650 + spriteArana.getGlobalBounds().width, rand()%400 + spriteArana.getGlobalBounds().height);
    }

    ///DEVUELVE LOS BORDES DE LA "SKIN" DE LA ARANA
    sf::FloatRect getBounds()const override{
    return spriteArana.getGlobalBounds();
    }

};

#endif // ARANA_H_INCLUDED
