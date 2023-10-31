#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED

class colisionable{

public:
    virtual sf::FloatRect getBounds() const = 0;

    ///VERIFICA SI UN ITEM COLISIONA CON OTRO
    bool esColision(colisionable &obj) const{
        return getBounds().intersects(obj.getBounds());
    }

};


#endif // COLISIONABLE_H_INCLUDED
