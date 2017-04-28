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
    //Wyzwalacz (trigger) wywo³ywany tu¿ przed zmian¹ w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zmodyfikowaæ wartoœæ,
    //któr¹ za chwilê przyjmie w³aœciwoœæ BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);


public:
    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    CRadiation();
    virtual ~CRadiation();
};

#endif // CRADIATION_H
