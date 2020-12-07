#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

int r, i, xc, yc;
float x, y;

void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500,500,-500,500);
}

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0.023, 0);
	glPointSize(2.0);	
	glBegin(GL_POINTS);
	x=xc; y=yc;
	for(i=0;i<=360;i++)
    {
        glVertex2f(x,y);
        x = ( x + (r*cos(i)));
        y = ( y - (r*sin(i)));
    }
	glEnd();
	glFlush();
}

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
	printf("Enter the radius of circle: ");
	scanf("%d",&r); 
	printf("Enter the coordinates of center of circle: ");
	scanf("%d %d",&xc, &yc); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("Circle using Polar Equation");
	glClearColor(0.643, 0.976, 0.945, 1);
	init();	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}