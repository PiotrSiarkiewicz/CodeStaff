#include "CCenteredEllipses.h"


void CCenteredEllipses::beforeBoundingRectChange(RECT* newBoundingRect)
{
    mEllipses[0].setBoundingRect(*newBoundingRect);
    mEllipses[1].setCenter(mEllipses[0].getCenter());
    mEllipses[2].setCenter(mEllipses[0].getCenter());

    newBoundingRect->left = newBoundingRect->right = mEllipses[0].getBoundingRect().left;
    newBoundingRect->top = newBoundingRect->bottom = mEllipses[0].getBoundingRect().top;
    for(int i=0; i<3; i++)
    {
        if(newBoundingRect->left > mEllipses[i].getBoundingRect().left) newBoundingRect->left = mEllipses[i].getBoundingRect().left;
        if(newBoundingRect->right < mEllipses[i].getBoundingRect().right) newBoundingRect->right = mEllipses[i].getBoundingRect().right;
        if(newBoundingRect->top > mEllipses[i].getBoundingRect().top) newBoundingRect->top = mEllipses[i].getBoundingRect().top;
        if(newBoundingRect->bottom < mEllipses[i].getBoundingRect().bottom) newBoundingRect->bottom = mEllipses[i].getBoundingRect().bottom;//        if(minX > mEllipses[i].getBoundingRect().left) minX = mEllipses[i].getBoundingRect().left;
    }
}

void CCenteredEllipses::afterSizeChangeStep()
{
    for(int i=0; i<3; i++)
        mEllipses[i].setSizeChangeStep(getSizeChangeStep());
}

void CCenteredEllipses::Paint(HDC hdc)
{
    //DrawFocusRect(hdc, &getBoundingRect());

    for(int i=0; i<3; i++)
        mEllipses[i].Paint(hdc);
}

void CCenteredEllipses::Tick()
{
    for(int i=1; i<3; i++)
        mEllipses[i].Tick();

    //setBoundingRect(mEllipses[0].getBoundingRect());
    CShape::Tick();
}


CCenteredEllipses::CCenteredEllipses()
{

}

CCenteredEllipses::~CCenteredEllipses()
{

}
