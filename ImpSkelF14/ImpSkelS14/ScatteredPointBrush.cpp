//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredPointBrush.h"

extern float frand();

ScatteredPointBrush::ScatteredPointBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredPointBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	//glPointSize((float)size);
	glPointSize(1.0f);

	BrushMove(source, target);
}

void ScatteredPointBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("PointBrush::BrushMove  document is NULL\n");
		return;
	}

	int size = dlg->getSize();
	double radius = size / 2.0;
	for (int i = (target.x - radius); i < target.x + radius; i++){
		for (int j = (target.y - radius); j < target.y + radius; j++){

			int random = rand() % 5;
			if (random == 0){
				glBegin(GL_POINTS);
				SetColor(Point(i,j));
				glVertex2d(i, j);
				glEnd();
				//ImpBrush::c_pBrushes[BRUSH_POINTS]->BrushMove(source, Point(i, j));
			}

		}

	}
	//DrawPoint(source);
	//printf("source = ( %d, %d )  target = ( %d, %d ) \n", source.x, source.y, target.x, target.y);
	//glBegin(GL_POINTS);
	//glColor3f(1.0f, 0.0f, 0.0f);

	//glVertex2d(source.x, source.y);
	//SetColor(source);

	//glVertex2d(target.x, target.y);

	//glEnd();
}

void ScatteredPointBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

