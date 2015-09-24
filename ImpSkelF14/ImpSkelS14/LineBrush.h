//
// LineBrush.h
//
// The header file for Point Brush. 
//

#ifndef LINEBRUSH_H
#define LINEBRUSH_H
# define M_PI           3.14159265358979323846  /* pi */

#include "ImpBrush.h"
#include <math.h>  
class LineBrush : public ImpBrush
{
private:
	Point prevTarget =  Point(0,0);
	/*
	int sobelX[3][3] = { 
		{-1, 0, 1},
		{-2, 0, 2},
		{-1, 0, 1}
	};
	int sobelY[3][3] = {
		{ 1, 2, 1 },
		{ 0, 0, 0 },
		{-1, -2,-1}
	};
	*/
public:
	LineBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	Point getPrevPoint();
	void setPrevPoint(Point prevTarget);
	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};

#endif