#ifndef GLOBJECT_H
#define GLOBJECT_H
#include <GLTexture.h>
#include <common.h>


class GLObject
{
    public:
        GLObject();
        virtual ~GLObject();

        GLTexture *texture = new GLTexture();

        void initObject(int,int,char* fileName); // number of x, y frames
        void drawObject();


        vec3 objPosition;
        vec3 objScale;

        vec3 vert[4];
        float xMax,xMin,yMax,yMin;
        int framesX,framesY;

    protected:

    private:
};

#endif // GLOBJECT_H
