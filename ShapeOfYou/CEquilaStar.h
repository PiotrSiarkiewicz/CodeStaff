#ifndef CEQUILASTAR_H
#define CEQUILASTAR_H



#include "CShape.h"
#include "CEquilateralTriangle.h"
class CEquilaStar : public CShape
{
    public:
        CEquilaStar();
        virtual ~CEquilaStar();
        virtual void beforeBoundingRectChange(RECT* newBoundingRect);
        virtual void Paint(HDC hdc);
    protected:
    private:
    CEquilateralTriangle mTopTriangle;
    CEquilateralTriangle mRightTriangle;
    CEquilateralTriangle mBottomTriangle;
    CEquilateralTriangle mLeftTriangle;


};



#endif // CEQUILASTAR_H
