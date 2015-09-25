//
// ImpBrush.cpp
//
// The implementation of virtual brush. All the other brushes inherit from it.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ImpBrush.h"
#include <IOStream>
// Static class member initializations
int			ImpBrush::c_nBrushCount	= 0;
ImpBrush**	ImpBrush::c_pBrushes	= NULL;

ImpBrush::ImpBrush(ImpressionistDoc*	pDoc, 
				   char*				name) :
					m_pDoc(pDoc), 
					m_pBrushName(name)
{
}

//---------------------------------------------------
// Return m_pDoc, which connects the UI and brushes
//---------------------------------------------------
ImpressionistDoc* ImpBrush::GetDocument(void)
{
	return m_pDoc;
}

//---------------------------------------------------
// Return the name of the current brush
//---------------------------------------------------
char* ImpBrush::BrushName(void)
{
	return m_pBrushName;
}

//----------------------------------------------------
// Set the color to paint with to the color at source,
// which is the coord at the original window to sample 
// the color from
//----------------------------------------------------
void ImpBrush::SetColor (const Point source)
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	ImpressionistDoc* pDoc = GetDocument();

	
	GLubyte color[3];

	memcpy ( color, pDoc->GetOriginalPixel( source ), 3 );
	
	//GLubyte colorWithAlpha[4];
	for (int i = 0; i < 3; i++){
		colorWithAlpha[i] = color[i];
	}
	//printf("Alpha =  %f,  R = %f,  G= %f,  B= %f ", pDoc->m_pUI->getAlpha(), color[0], color[1], color[2]);
	//int alpha = (pDoc->m_pUI->getAlpha()) * 255;
	//colorWithAlpha[3] = (GLubyte)((pDoc->m_pUI->getAlpha())*255);
	colorWithAlpha[3] = GLubyte(pDoc->m_pUI->getAlpha() * 255);
	//printf(" R = %d,  G= %d,  B= %d ,Alpha =  %d  ", colorWithAlpha[0], colorWithAlpha[1], colorWithAlpha[2], colorWithAlpha[3]);
	glColor4ubv(colorWithAlpha);

}


/*
void ImpBrush::DrawPoint(const Point source){
	
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex2d(source.x, source.y);

	glEnd();
}
*/