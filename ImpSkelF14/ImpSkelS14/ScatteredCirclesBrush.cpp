//
// CircleBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredCirclesBrush.h"
#include <math.h>

extern float frand();

ScatteredCirclesBrush::ScatteredCirclesBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredCirclesBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize(1);

	BrushMove(source, target);
}

void ScatteredCirclesBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	double PI = 3.1415;

	if (pDoc == NULL) {
		printf("PointBrush::BrushMove  document is NULL\n");
		return;
	}

	glBegin(GL_POINTS);
		

		for (int k = 0; k < 3; ++k){
			double randx = (double)(rand() % size/2);
			double randy = (double)(rand() % size/2);
			Point randpt = Point((int)(target.x + pow((-1.0), randx)* randx), (int)(target.y + pow((-1.0), randy)* randy));
			SetColor(randpt);
			for (int j = 0; j < size; ++j){
				for (int i = 0; i < 300; ++i)
					glVertex2d(randpt.x + j / 2 * cos(2 * PI / 300 * i), randpt.y + j / 2 * sin(2 * PI / 300 * i));
			}
		}

	glEnd();
}

void ScatteredCirclesBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

