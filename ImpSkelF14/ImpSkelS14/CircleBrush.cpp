//
// CircleBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "CircleBrush.h"
#include <math.h>

extern float frand();

CircleBrush::CircleBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void CircleBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void CircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	double PI = 3.1415;

	if (pDoc == NULL) {
		printf("PointBrush::BrushMove  document is NULL\n");
		return;
	}

	glBegin(GL_LINE_LOOP);
	SetColor(source);
	for (int j = 0; j < size; ++j){
		for (int i = 0; i < 300; ++i)
			glVertex2d(target.x + j * cos(2 * PI / 300 * i), target.y + j * sin(2 * PI / 300 * i));
	}

	glEnd();
}

void CircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

