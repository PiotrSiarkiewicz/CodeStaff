#ifndef CCENTEREDELLIPSES_H
#define CCENTEREDELLIPSES_H

#include "CShape.h"
#include "CEllipse.h"

class CCenteredEllipses : public CShape
{
private:
    CEllipse mEllipses[3];

protected:
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);
    virtual void afterSizeChangeStep();

public:
    virtual void Paint(HDC hdc);
    virtual void Tick();

    CCenteredEllipses();
    virtual ~CCenteredEllipses();
};

#endif // CCENTEREDELLIPSES_H
