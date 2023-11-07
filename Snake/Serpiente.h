#ifndef SERPIENTE_H_INCLUDED
#define SERPIENTE_H_INCLUDED
#include "colisionable.h"
#include <deque>



class Serpiente : public sf::Drawable, public colisionable{
private:
    sf::Sprite spriteSerpiente;
    sf::Texture texturaSerpiente;
    sf::Vector2f velocidad;
    sf::Vector2f ultimaDireccion;
    ///sf::Sprite colaSerpiente;
    ///sf::Texture texturaColaSerpiente;
    std::deque<sf::Vector2f> segmentos;



public:
    ///INICIALIZA LA COMIDA
    Serpiente(){
    spriteSerpiente.setPosition(400, 300);
    texturaSerpiente.loadFromFile("serpiente.png");
    spriteSerpiente.setTexture(texturaSerpiente);
    spriteSerpiente.setOrigin(spriteSerpiente.getGlobalBounds().width/2, spriteSerpiente.getGlobalBounds().height);

    }

    void agregarCola() {
        // Obtén la posición de la cabeza de la serpiente
        sf::Vector2f posicionCabeza = spriteSerpiente.getPosition();

        // Agregar la posición de la cabeza al comienzo de la colección de segmentos
        segmentos.push_back(posicionCabeza);
    }

    aumentarLongitud(){
    for(int i = 0; i<7; i++){
        agregarCola();
    }
    }


    ///ACTUALIZA LOS ESTADOS DE LA SERPIENTE
    void actualizar() {

        velocidad = {0, 0};

        ///MOVIENDO LA SERPIENTE
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                velocidad.y = -3;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            velocidad.x = -3;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            velocidad.y = 3;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocidad.x = 3;
        }


        if ((velocidad.x == 0 || ultimaDireccion.x == 0) && (velocidad.y == 0 || ultimaDireccion.y == 0) && (velocidad !=  sf::Vector2f(0,0))){
            ultimaDireccion = velocidad;
        }

        if(ultimaDireccion.y <0){
            spriteSerpiente.setRotation(180);
        }
        else if(ultimaDireccion.x <0){
            spriteSerpiente.setRotation(90);
        }
                if(ultimaDireccion.y >0){
            spriteSerpiente.setRotation(0);
        }
        else if(ultimaDireccion.x >0){
            spriteSerpiente.setRotation(270);
        }

for (int i = segmentos.size() - 1; i > 0; --i) {
    segmentos[i] = segmentos[i - 1];
}
// Coloca el primer segmento en la posición anterior de la cabeza
segmentos[0] = spriteSerpiente.getPosition() - ultimaDireccion;

    sf::Vector2f posicionOriginal = spriteSerpiente.getPosition();
    spriteSerpiente.setOrigin(spriteSerpiente.getGlobalBounds().width / 2, spriteSerpiente.getGlobalBounds().height / 2);
    spriteSerpiente.setPosition(posicionOriginal);
    spriteSerpiente.move(ultimaDireccion);




    }

    ///DIBUJA LA SERPIENTE
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(spriteSerpiente, states);

         for (const sf::Vector2f& segmento : segmentos) {
        sf::Sprite segmentSprite = spriteSerpiente; // Copia el sprite de la cabeza
        segmentSprite.setPosition(segmento); // Establece la posición del segmento
        target.draw(segmentSprite, states); // Dibuja el segmento
    }
    }

    ///DEVUELVE LOS BORDES DE LA "SKIN" DE LA SERPIENTE
    sf::FloatRect getBounds()const override{
    return spriteSerpiente.getGlobalBounds();
    }

    ///CHEQUEA SI LA SERPIENTE CHOCA CON LOS BORDES DE LA PANTALLA
    bool colisionBordes(){
        bool colision = false;
            if (spriteSerpiente.getGlobalBounds().left < -10) {
            spriteSerpiente.setPosition(spriteSerpiente.getOrigin().x, spriteSerpiente.getPosition().y);
            colision = true;
        }
        if (spriteSerpiente.getGlobalBounds().top < 30) {
            spriteSerpiente.setPosition(spriteSerpiente.getPosition().x, spriteSerpiente.getOrigin().y);
            colision = true;
        }
        if (spriteSerpiente.getGlobalBounds().left + spriteSerpiente.getGlobalBounds().width > 810) {
            spriteSerpiente.setPosition(800 - spriteSerpiente.getOrigin().x, spriteSerpiente.getPosition().y);
            colision = true;
        }
        if (spriteSerpiente.getGlobalBounds().top + spriteSerpiente.getGlobalBounds().height > 610) {
            spriteSerpiente.setPosition(spriteSerpiente.getPosition().x, 600 - spriteSerpiente.getOrigin().y);
            colision = true;
        }
        return colision;
    }


};




#endif // SERPIENTE_H_INCLUDED
