#ifndef SERPIENTE_H_INCLUDED
#define SERPIENTE_H_INCLUDED
#include "colisionable.h"

class Serpiente : public sf::Drawable, public colisionable{
private:
    sf::Sprite spriteSerpiente;
    sf::Texture texturaSerpiente;
    sf::Vector2f velocidad;


public:

    Serpiente(){
    spriteSerpiente.setPosition(400, 300);
    texturaSerpiente.loadFromFile("serpiente.png");
    spriteSerpiente.setTexture(texturaSerpiente);
    spriteSerpiente.setOrigin(spriteSerpiente.getGlobalBounds().width/2, spriteSerpiente.getGlobalBounds().height);

    }

    void actualizar() {

        velocidad = {0, 0};


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                velocidad.y = -5;
                spriteSerpiente.setRotation(180);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            velocidad.x = -5;
            spriteSerpiente.setRotation(90);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            velocidad.y = 5;
            spriteSerpiente.setRotation(0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocidad.x = 5;
            spriteSerpiente.setRotation(270);

        }

            sf::Vector2f posicionOriginal = spriteSerpiente.getPosition();
            spriteSerpiente.setOrigin(spriteSerpiente.getGlobalBounds().width / 2, spriteSerpiente.getGlobalBounds().height / 2);
            spriteSerpiente.setPosition(posicionOriginal);
            spriteSerpiente.move(velocidad);



        if (spriteSerpiente.getGlobalBounds().left < 0) {
            spriteSerpiente.setPosition(spriteSerpiente.getOrigin().x, spriteSerpiente.getPosition().y);
        }
        if (spriteSerpiente.getGlobalBounds().top < 0) {
            spriteSerpiente.setPosition(spriteSerpiente.getPosition().x, spriteSerpiente.getOrigin().y);
        }

        if (spriteSerpiente.getGlobalBounds().left + spriteSerpiente.getGlobalBounds().width > 800) {
            spriteSerpiente.setPosition(800 - spriteSerpiente.getOrigin().x, spriteSerpiente.getPosition().y);
        }

        if (spriteSerpiente.getGlobalBounds().top + spriteSerpiente.getGlobalBounds().height > 600) {
            spriteSerpiente.setPosition(spriteSerpiente.getPosition().x, 600 - spriteSerpiente.getOrigin().y);
        }


    }


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(spriteSerpiente, states);
    }


    sf::FloatRect getBounds()const override{
    return spriteSerpiente.getGlobalBounds();
    }

    bool colisionBordes(){
        bool colision = false;
        if (spriteSerpiente.getGlobalBounds().left < 0 ||
        spriteSerpiente.getGlobalBounds().top < 0 ||
        spriteSerpiente.getGlobalBounds().left + spriteSerpiente.getGlobalBounds().width > 800 ||
        spriteSerpiente.getGlobalBounds().top + spriteSerpiente.getGlobalBounds().height > 600) {
            colision = true;
            return colision;
    }
    }


};




#endif // SERPIENTE_H_INCLUDED
