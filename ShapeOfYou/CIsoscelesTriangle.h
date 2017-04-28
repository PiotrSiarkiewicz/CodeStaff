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
    //Metoda s³u¿¹ca do przeliczenia wierzcho³ków na podstawie aktualnego prostok¹ta opisanego na figurze (w³aœciwoœæ BoundingRect).
    virtual void updateVertices();
    virtual void afterDirectionChange();
public:
    void setDirection(DirectionType aDirection);
    DirectionType getDirection();

};

#endif // CISOSCELESTRIANGLE_H
