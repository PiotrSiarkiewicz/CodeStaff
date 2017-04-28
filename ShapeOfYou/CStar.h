#ifndef CSTAR_H
#define CSTAR_H
#include "CShape.h"
#include "CIsoscelesTriangle.h"
class CStar : public CShape
{
    public:
        CStar();
        virtual ~CStar();
        virtual void beforeBoundingRectChange(RECT* newBoundingRect);
        virtual void Paint(HDC hdc);
    protected:
    private:
    CIsoscelesTriangle mTopTriangle;
    CIsoscelesTriangle mRightTriangle;
    CIsoscelesTriangle mBottomTriangle;
    CIsoscelesTriangle mLeftTriangle;


};

#endif // CSTAR_H
