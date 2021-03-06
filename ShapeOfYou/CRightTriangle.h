#ifndef CRIGHTTRIANGLE_H
#define CRIGHTTRIANGLE_H

#include "CAbstractTriangle.h"

class CRightTriangle : public CAbstractTriangle
{
protected:
    //Metoda służąca do przeliczenia wierzchołków na podstawie aktualnego prostokąta opisanego na figurze (właściwość BoundingRect).
    virtual void updateVertices();
};

#endif // CRIGHTTRIANGLE_H
