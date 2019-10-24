//
// Created by hendrik on 18.10.19.
//

#ifndef RTS_TEXTUREOBJECT_H
#define RTS_TEXTUREOBJECT_H


#include "RenderObject.h"
#include "Texture.h"

class TextureObject : public RenderObject{
protected:
    Texture *texture;
};


#endif //RTS_TEXTUREOBJECT_H
