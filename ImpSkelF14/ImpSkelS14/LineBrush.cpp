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
	angle = (dlg->getLineAngle()*M_PI) / 180;
	
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
		
		int sobelX[3][3] = {
			{ -1, 0, 1 },
			{ -2, 0, 2 },
			{ -1, 0, 1 }
		};
		int sobelY[3][3] = {
			{ 1, 2, 1 },
			{ 0, 0, 0 },
			{ -1, -2, -1 }
		};
		int gradX=0 , gradY=0 ;
		int gradMatrix[3][3];
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				GLubyte color[3];
				Point point = Point(target.x - 1 + row, target.y + 1 - col);
				memcpy(color, pDoc->GetOriginalPixel(point), 3);
				gradMatrix[row][col] = 0.3*color[0] + 0.59*color[1] + 0.11*color[2];
				
			}
		}
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				gradX += gradMatrix[row][col] * sobelX[row][col];
				gradY += gradMatrix[row][col] * sobelY[row][col];
				printf("%d, ",gradMatrix[row][col]);
			}
			printf("\n");
		}
		printf("gradX = %d, gradY = %d ", gradX, gradY);
		//printf("is it true : %d \n", gradX == 0);
		//angle = 26 * 180 / M_PI;
		
		if (gradX == 0){
			//angle = 90;
			//printf("gradX == 0        !!!!!!!!!!!!!!!!!!!!!1/n");
			glVertex2d(target.x, target.y + radius);
			glVertex2d(target.x, target.y - radius);
			
			
		}
		else{
			angle =int (atan(gradY / (double)gradX) * 180 / M_PI);
			//printf("angle is cal by formula!!!!!!!!\n");
			changeOfX = radius *cos(angle);
			changeOfY = radius *sin(angle);
			glVertex2d(target.x + changeOfX, target.y + changeOfY);
			glVertex2d(target.x - changeOfX, target.y - changeOfY);
		}
		printf("  angle = %f \n", angle);
		/*
		printf("angle ==90? %d \n", angle==90);
		changeOfX = radius *cos(angle);
		changeOfY = radius *sin(angle);
		glVertex2d(target.x + changeOfX, target.y + changeOfY);
		glVertex2d(target.x - changeOfX, target.y - changeOfY);
		*/
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


