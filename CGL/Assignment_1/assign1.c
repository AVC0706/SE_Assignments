#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void DDA_LINE(int ,int ,int ,int );
void plot(int , int);
void pattern(int ,int ,int ,int );

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2, 0.5, 0.7);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0.0,1000.0,0.0,1000.0);
    pattern(100,100,900,900);
    glEnd();
    glFlush();
}


void DDA_LINE(int x1,int y1,int x2,int y2)
{
	float dx,dy,x_inc,y_inc,steps,x,y,i;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
		
	x_inc=dx/steps;
	y_inc=dy/steps;
	
	x=x1;
	y=y1;
	
	plot(round(x),round(y));
	
	for(i=0;i<=steps;i++)
	{
		x=x+x_inc;
		y=y+y_inc;
		
		plot(round(x),round(y));
	}
	glFlush();
}

void plot(int x, int y)
{
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
    glFlush();
}



void pattern(int x1,int y1,int x2,int y2)
{
	DDA_LINE(x1,y1,x2,y1);
    DDA_LINE(x2,y1,x2,y2);
    DDA_LINE(x2,y2,x1,y2);
    DDA_LINE(x1,y2,x1,y1);
   // DDA_LINE((x1+x2)/2,y1,x2,(y1+y2)/2);
   // DDA_LINE(x2,(y1+y2)/2,(x1+x2)/2,y2);
   // DDA_LINE((x1+x2)/2,y2,x1,(y1+y2)/2);
   // DDA_LINE(x1,(y1+y2)/2,(x1+x2)/2,y1);
    DDA_LINE((3*x1+x2)/4,(3*y2+y1)/4,(3*x1+x2)/4,(3*y1+y2)/4);
  //  DDA_LINE((3*x1+x2)/4,(3*y1+y2)/4,(3*x2+x1)/4,(3*y1+y2)/4);
   // DDA_LINE((3*x2+x1)/4,(3*y1+y2)/4,(3*x2+x1)/4,(3*y2+y1)/4);
   // DDA_LINE((3*x2+x1)/4,(3*y2+y1)/4,(3*x1+x2)/4,(3*y2+y1)/4);
}




int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Assignment - 1");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
