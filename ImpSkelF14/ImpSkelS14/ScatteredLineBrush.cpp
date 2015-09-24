//
// ScatteredLineBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredLineBrush.h"

extern float frand();

ScatteredLineBrush::ScatteredLineBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredLineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void ScatteredLineBrush::BrushMove(const Point source, const Point target)
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

			int random = rand() % 200;
			if (random == 0){
				ImpBrush::c_pBrushes[BRUSH_LINES]->BrushMove(source, Point(i, j));
			}

		}

	}

	/*
	//setPrevPoint(target);
	int angleType = dlg->getSelectedAngleType();
	int size = dlg->getSize();
	double angle = (dlg->getLineAngle()*M_PI) / 180;
	double radius = size / 2.0;
	double changeOfX = radius *cos(angle);
	double changeOfY = radius *sin(angle);
	glLineWidth(dlg->getLineWidth());
	//glLineWidth(10);
	//printf("%d", dlg->getLineWidth());
	glBegin(GL_LINES);

	SetColor(source);
	//angle type == slider
	if (angleType == 0){

		glVertex2d(target.x + changeOfX, target.y + changeOfY);
		glVertex2d(target.x - changeOfX, target.y - changeOfY);
	}
	//angle type == gradient
	else if (angleType == 1){

	}
	//angle type == brush direction
	else if (angleType == 2){
		Point prevPoint = getPrevPoint();
		double diffX = target.x - prevPoint.x;
		double diffY = target.y - prevPoint.y;
		double angleOfPrev;
		if (diffX != 0){
			angleOfPrev = atan(diffY / diffX) * 180 / M_PI;
			changeOfX = radius *cos(angleOfPrev);
			changeOfY = radius *sin(angleOfPrev);
			glVertex2d(target.x + changeOfX, target.y + changeOfY);
			glVertex2d(target.x - changeOfX, target.y - changeOfY);
		}
		else{
			glVertex2d(target.x, target.y + radius);
			glVertex2d(target.x, target.y - radius);
		}

	}
	glEnd();
	setPrevPoint(target);

	*/
}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

void ScatteredLineBrush::setPrevPoint(Point	prevTarget)
{
	this->prevTarget = prevTarget;
}

Point ScatteredLineBrush::getPrevPoint(){
	return prevTarget;
}


