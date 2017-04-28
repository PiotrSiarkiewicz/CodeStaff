#include "CEquilaStar.h"



CEquilaStar::CEquilaStar()
{
    mTopTriangle.setDirection(dtUp);
    mRightTriangle.setDirection(dtRight);
    mBottomTriangle.setDirection(dtDown);
    mLeftTriangle.setDirection(dtLeft);
}

CEquilaStar::~CEquilaStar()
{
    //dtor
}

void CEquilaStar :: beforeBoundingRectChange(RECT* newBoundingRect)
{
    RECT tmpRect[4];
    int center;



    for(int i=0; i<4;i++)
    {
        tmpRect[i] = *newBoundingRect;
    }

    int width,height;
    width = tmpRect[0].right - tmpRect[0].left;
    height = tmpRect[0].bottom - tmpRect[0].top;



    tmpRect[0].top += height/3;
    tmpRect[0].bottom -= height/3;
    tmpRect[0].left = tmpRect[0].right-width/3;
    mRightTriangle.setBoundingRect(tmpRect[0]);


    tmpRect[1].bottom = tmpRect[1].top + height/3;
    tmpRect[1].left += width/3;
    tmpRect[1].right -= width/3;
    mTopTriangle.setBoundingRect(tmpRect[1]);


    tmpRect[2].top += height*2/3;
    tmpRect[2].left += width/3;
    tmpRect[2].right -= width/3;
    mBottomTriangle.setBoundingRect(tmpRect[2]);


    tmpRect[3].top += height/3;
    tmpRect[3].bottom -= height/3;
    tmpRect[3].right = tmpRect[3].left + width/3;
    mLeftTriangle.setBoundingRect(tmpRect[3]);

}
void CEquilaStar::Paint(HDC hdc)
{
    mTopTriangle.Paint(hdc);
    mRightTriangle.Paint(hdc);
    mBottomTriangle.Paint(hdc);
    mLeftTriangle.Paint(hdc);
}
