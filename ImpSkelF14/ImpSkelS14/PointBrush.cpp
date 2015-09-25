//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "pointbrush.h"

extern float frand();

PointBrush::PointBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void PointBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;
	
	int size = pDoc->getSize();



	glPointSize( (float)size );
	BrushMove( source, target );
}

void PointBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;
	int paintwidth = pDoc->m_nPaintWidth;
	int paintheight = pDoc->m_nPaintHeight;

	if (pDoc == NULL) {
		printf("PointBrush::BrushMove  document is NULL\n");
		return;
	}

	//DrawPoint(source);
	//printf("source = ( %d, %d )  target = ( %d, %d ) \n", source.x, source.y,target.x,target.y);
	glBegin( GL_POINTS );
		//glColor3f(1.0f, 0.0f, 0.0f);
	
		//glVertex2d(source.x, source.y);
		SetColor( source );
		
		glVertex2d( target.x, target.y );
		

	if (target.x > 0 && target.x < paintwidth && target.y > 0 && target.y < paintheight){
	glBegin(GL_POINTS);
	SetColor(source);

	glVertex2d(target.x, target.y);

	glEnd();
	}
}

void PointBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

