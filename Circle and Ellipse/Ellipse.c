#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

int x, y, major, minor, xc, yc;
float a, b, pk1, pk2;

void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-400,400,-400,400);
}

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0.023, 0);
	glPointSize(2.0);	
	glBegin(GL_POINTS);
	a=major/2;
    b=minor/2;
    y=b;

    pk1 = (b*b) + (0.25*a*a) - (a*a*b);                                 //region where slope of tangent is <1
	for(x=0; (2*b*b*x)<(2*a*a*y); x++) 
    {
		glVertex2f(x+xc,y+yc);
        glVertex2f(-x+xc,y+yc);
        glVertex2f(-x+xc,-y+yc);
        glVertex2f(x+xc,-y+yc);
        
        if(pk1<0)
        {
            pk1 = pk1 + (2*b*b*x) + (b*b);
        }
        else
        {
            pk1 = pk1 + (2*b*b*x) + (b*b) - (2*a*a*y); 
            y=y-1; 
        } 
    }

    pk2 =(b*b*(x+0.5)*(x+0.5)) + (a*a*(y-1)*(y-1)) - (a*a*b*b);         //region where slope of tangent is >1
	for(y=y; y>0; y--)
    {
		glVertex2f(x+xc,y+yc);
        glVertex2f(-x+xc,y+yc);
        glVertex2f(-x+xc,-y+yc);
        glVertex2f(x+xc,-y+yc);
        
        if(pk2>0)
        {
            pk2 = pk2 - (2*a*a*y) + (a*a); 
        }
        else
        {
            pk2 = pk2 - (2*a*a*y) + (2*b*b*x) + (a*a); 
            x = x + 1;
        } 
    }
	glEnd();
	glFlush();
}

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
	printf("Enter the length of major axis: ");
	scanf("%d",&major);
    printf("Enter the length of minor axis: ");
	scanf("%d",&minor); 
    printf("Enter the coordinates of center of ellipse: ");
	scanf("%d %d",&xc, &yc); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("Mid Point Ellipse Algorithm");
	glClearColor(0.643, 0.976, 0.945, 1);
	init();	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}
