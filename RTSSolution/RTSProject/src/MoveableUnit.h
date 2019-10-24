//
// Created by hendrik on 17.10.19.
//

#ifndef RTS_MOVEABLEUNIT_H
#define RTS_MOVEABLEUNIT_H


#include "TextureObject.h"

class MoveableUnit : public TextureObject{
protected:
    float currentHealth;
    bool isMoving;
};


#endif //RTS_MOVEABLEUNIT_H
