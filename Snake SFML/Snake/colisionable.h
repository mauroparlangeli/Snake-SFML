#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED

class colisionable{

public:
    virtual sf::FloatRect getBounds() const = 0;
    ///el const es para que no modifique el objeto
    ///virtual para poder sobreescribir, no esta declarada ni nada

    ///VERIFICA SI UN ITEM COLISIONA CON OTRO
    bool esColision(colisionable &obj) const{
        return getBounds().intersects(obj.getBounds());
    }

};


#endif // COLISIONABLE_H_INCLUDED
