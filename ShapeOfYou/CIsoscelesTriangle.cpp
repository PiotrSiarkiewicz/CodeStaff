#include "CIsoscelesTriangle.h"

void CIsoscelesTriangle::updateVertices()
{
	const RECT& boundingRect = getBoundingRect();
	//setDirection(dtLeft);
    switch(mDirection)
    {
        case dtUp:
        mVertices[0].x = boundingRect.left;
        mVertices[0].y = boundingRect.bottom;
        mVertices[1].x = (boundingRect.left + boundingRect.right) / 2;
        mVertices[1].y = boundingRect.top;
        mVertices[2].x = boundingRect.right;
        mVertices[2].y = boundingRect.bottom;
        break;

        case dtRight:
        mVertices[0].x = boundingRect.left;
        mVertices[0].y = boundingRect.bottom;
        mVertices[1].x = boundingRect.left;
        mVertices[1].y = boundingRect.top;
        mVertices[2].x = boundingRect.right;
        mVertices[2].y = (boundingRect.bottom + boundingRect.top)/2;
        break;

        case dtDown:
        mVertices[0].x = (boundingRect.left + boundingRect.right)/2;
        mVertices[0].y = boundingRect.bottom;
        mVertices[1].x = boundingRect.left;
        mVertices[1].y = boundingRect.top;
        mVertices[2].x = boundingRect.right;
        mVertices[2].y = boundingRect.top;


        break;

        case dtLeft:
        mVertices[0].x = boundingRect.right;
        mVertices[0].y = boundingRect.bottom;
        mVertices[1].x = boundingRect.right;
        mVertices[1].y = boundingRect.top;
        mVertices[2].x = boundingRect.left;
        mVertices[2].y = (boundingRect.top + boundingRect.bottom)/2;

        break;
    }

}
void CIsoscelesTriangle::afterDirectionChange()
{
    updateVertices();
}
void CIsoscelesTriangle::setDirection(DirectionType aDirection)
{


    mDirection = aDirection;
    afterDirectionChange();


}
DirectionType CIsoscelesTriangle::getDirection()
{
    return mDirection;
}

