#ifndef ARANA_H_INCLUDED
#define ARANA_H_INCLUDED
#include "colisionable.h"

class Arana: public sf::Drawable, public colisionable{
private:
    sf::Sprite spriteArana;
    sf::Texture texturaArana;
    float velocidad;
    int tiempo;
    sf::Vector2f posicion;

public:
    ///INICIALIZA LA ARANA (CAMBIAR SKIN Y HACER QUE SE MUEVA O RESPAWNEE DESPUES DE CIERTO TIEMPO)
    Arana(){
    texturaArana.loadFromFile("arana.png");
    spriteArana.setTexture(texturaArana);
    spriteArana.setPosition(rand()%700 + spriteArana.getGlobalBounds().width, rand()%350 + spriteArana.getGlobalBounds().height);
    velocidad = 1;
    }

    ///ACTUALIZA LOS ESTADOS DE LA ARANA
    void actualizar(){
        tiempo--;
        if(tiempo<0){
            tiempo = 60 * 5;
            posicion = {rand()%700 + spriteArana.getGlobalBounds().width, rand()%350 + spriteArana.getGlobalBounds().height};
        }
        if(posicion.x > spriteArana.getPosition().x){
            spriteArana.move(velocidad, 0);
        }
        if(posicion.x < spriteArana.getPosition().x){
            spriteArana.move(-velocidad, 0);
        }
        if(posicion.y > spriteArana.getPosition().y){
            spriteArana.move(0, velocidad);
        }
        if(posicion.y < spriteArana.getPosition().y){
            spriteArana.move(0, -velocidad);
        }

    }

    ///DIBUJA LA ARANA
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    target.draw(spriteArana, states);
    }

    ///RESPAWNEA LA ARANA
    void respawn(){
    spriteArana.setPosition(rand()%700 + spriteArana.getGlobalBounds().width, rand()%350 + spriteArana.getGlobalBounds().height);
    tiempo = 60 * 5;
    }

    ///DEVUELVE LOS BORDES DE LA "SKIN" DE LA ARANA
    sf::FloatRect getBounds()const override{
    return spriteArana.getGlobalBounds();
    }

};

#endif // ARANA_H_INCLUDED
