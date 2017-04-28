#include "CRadiation.h"
#include <math.h>

void CRadiation::beforeBoundingRectChange(RECT* newBoundingRect)
{
    int centerX, centerY, blackCircleRadius, lineWidth, triangleSide;
    RECT tmpRect;
    POINT vertices[3];

    mOuterCircle.setBoundingRect(*newBoundingRect);
    *newBoundingRect = mOuterCircle.getBoundingRect();
    tmpRect = *newBoundingRect;
    centerX = (tmpRect.left + tmpRect.right) / 2;
    centerY = (tmpRect.top + tmpRect.bottom) / 2;

    blackCircleRadius = ((tmpRect.bottom - tmpRect.top)/2.0 - 1) / (4/sqrt(3.0) - 1);

    lineWidth = blackCircleRadius * (2.0 / sqrt(3.0) - 1) - 1;
    mOuterCircle.setLineWidth(lineWidth);
    mInnerCircle.setLineWidth(lineWidth);

    triangleSide = blackCircleRadius * 2.0 / sqrt(3.0) + 1;

    tmpRect.left = centerX - blackCircleRadius;
    tmpRect.right = centerX + blackCircleRadius;
    mBlackCircle.setBoundingRect(tmpRect);

    tmpRect.left = centerX - blackCircleRadius/3;
    tmpRect.right = centerX + blackCircleRadius/3;
    mInnerCircle.setBoundingRect(tmpRect);

    vertices[0].x = centerX;
    vertices[0].y = centerY;

    vertices[1].x = centerX - triangleSide/2;
    vertices[1].y = centerY - blackCircleRadius;
    vertices[2].x = centerX + triangleSide/2;
    vertices[2].y = centerY - blackCircleRadius;
    mTriangles[0].setVertices(vertices);

    vertices[1].x = centerX + triangleSide;
    vertices[1].y = centerY;
    vertices[2].x = centerX + triangleSide/2;
    vertices[2].y = centerY + triangleSide * sqrt(3.0) / 2.0;
    mTriangles[1].setVertices(vertices);

    vertices[1].x = centerX - triangleSide;
    vertices[1].y = centerY;
    vertices[2].x = centerX - triangleSide/2;
    vertices[2].y = centerY + triangleSide * sqrt(3.0) / 2.0;
    mTriangles[2].setVertices(vertices);
}

void CRadiation::Paint(HDC hdc)
{
    mOuterCircle.Paint(hdc);
    mBlackCircle.Paint(hdc);
    for(int i=0; i<3; i++)
        mTriangles[i].Paint(hdc);
    mInnerCircle.Paint(hdc);
}

CRadiation::CRadiation()
{
    mOuterCircle.setFillColor(RGB(255,255,0));
    mOuterCircle.setLineColor(RGB(0,0,0));
    mBlackCircle.setLineColor(RGB(0,0,0));
    mBlackCircle.setFillColor(RGB(0,0,0));
    mBlackCircle.setLineWidth(0);
    mInnerCircle.setFillColor(RGB(0,0,0));
    mInnerCircle.setLineColor(RGB(255,255,0));

    for(int i=0; i<3; i++)
    {
        mTriangles[i].setFillColor(RGB(255,255,0));
        mTriangles[i].setLineColor(RGB(255,255,0));
        mTriangles[i].setLineWidth(0);
    }
}

CRadiation::~CRadiation()
{
}
