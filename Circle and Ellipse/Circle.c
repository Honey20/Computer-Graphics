#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

int x, y, r, pk, xk, yk, xc, yc;

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
	
    y=r;
    pk=1-r;
	for(x=0; x<=y; x++)
    {
		glVertex2f(x+xc,y+yc);
        glVertex2f(y+xc,x+yc);
        glVertex2f(-x+xc,y+yc);
        glVertex2f(-y+xc,x+yc);
        glVertex2f(-x+xc,-y+yc);
        glVertex2f(-y+xc,-x+yc);
        glVertex2f(x+xc,-y+yc);
        glVertex2f(y+xc,-x+yc);
        if(pk>=0)
        {
            pk = pk + (2*x) - (2*y) + 1;
            y=y-1;
        }
        else
        {
            pk = pk + (2*x) + 1;    
        } 
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
	glutCreateWindow("Mid Point Circle Algorithm");
	glClearColor(0.643, 0.976, 0.945, 1);
	init();	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}