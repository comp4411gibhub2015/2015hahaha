//
// LineBrush.h
//
// The header file for Scattered Line Brush. 
//

#ifndef SCATTERED_LINEBRUSH_H
#define SCATTERED_LINEBRUSH_H
//# define M_PI           3.14159265358979323846  /* pi */

#include "ImpBrush.h"
#include <math.h>  
class ScatteredLineBrush : public ImpBrush
{
private:
	Point prevTarget = Point(0, 0);
public:
	ScatteredLineBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	Point getPrevPoint();
	void setPrevPoint(Point prevTarget);
	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};

#endif