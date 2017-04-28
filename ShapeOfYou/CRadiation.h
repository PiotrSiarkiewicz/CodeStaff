#ifndef CRADIATION_H
#define CRADIATION_H

#include "CShape.h"
#include "CCircle.h"
#include "CTriangle.h"

class CRadiation : public CShape
{
private:
    CCircle mOuterCircle;
    CCircle mBlackCircle;
    CCircle mInnerCircle;
    CTriangle mTriangles[3];

protected:
    //Wyzwalacz (trigger) wywo�ywany tu� przed zmian� w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zmodyfikowa� warto��,
    //kt�r� za chwil� przyjmie w�a�ciwo�� BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);


public:
    //Metoda obs�uguj�ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    CRadiation();
    virtual ~CRadiation();
};

#endif // CRADIATION_H
