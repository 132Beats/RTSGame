//
// Created by hendrik on 18.10.19.
//

#ifndef RTS_RENDEROBJECT_H
#define RTS_RENDEROBJECT_H


class RenderObject {
protected:
    bool toRender;
    float xpos, ypos;
    float renderLayer; // =zpos
public:
    void render();
};


#endif //RTS_RENDEROBJECT_H
