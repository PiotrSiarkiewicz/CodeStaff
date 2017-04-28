#ifndef CISOSCELESTRIANGLE_H
#define CISOSCELESTRIANGLE_H

#include "CAbstractTriangle.h"

#define ZALICZENIE_PKT_1
enum DirectionType {dtUp, dtRight, dtDown, dtLeft};

class CIsoscelesTriangle : public CAbstractTriangle
{
private:

    DirectionType mDirection;
protected:
    //Metoda s�u��ca do przeliczenia wierzcho�k�w na podstawie aktualnego prostok�ta opisanego na figurze (w�a�ciwo�� BoundingRect).
    virtual void updateVertices();
    virtual void afterDirectionChange();
public:
    void setDirection(DirectionType aDirection);
    DirectionType getDirection();

};

#endif // CISOSCELESTRIANGLE_H
