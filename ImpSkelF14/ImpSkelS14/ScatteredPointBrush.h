//
// ScatteredPointBrush.h
//
// The header file for Point Brush. 
//

#ifndef SCATTERED_POINTBRUSH_H
#define SCATTERED_POINTBRUSH_H

#include "ImpBrush.h"

class ScatteredPointBrush : public ImpBrush
{
public:
	ScatteredPointBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};

#endif