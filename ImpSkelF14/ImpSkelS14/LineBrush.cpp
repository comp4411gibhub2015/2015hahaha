//
// LineBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "LineBrush.h"

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("PointBrush::BrushMove  document is NULL\n");
		return;
	}
	//setPrevPoint(target);
	int angleType = dlg->getSelectedAngleType();
	int size = dlg->getSize();
	double angle = (dlg->getLineAngle()*M_PI)/180;
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
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

void LineBrush::setPrevPoint(Point	prevTarget)
{
	this->prevTarget = prevTarget;
}

Point LineBrush::getPrevPoint(){
	return prevTarget;
}


