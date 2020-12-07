//y=mx+c

#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

int x2, y2, x3, y3, temp;
float m,c;

void swap(int *a, int *b)
{
	temp = *a; 
	*a = *b; 
	*b = temp;
}

void init()
{
	glClearColor(0.643, 0.976, 0.945, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void slope() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	glPointSize(4.0);	
	glBegin(GL_POINTS);

	int x,y; 
	if(x2==x3)		//Infinite Slope
	{
		if(y2>y3)
		{
			swap(&y2,&y3);
		}
		for( y=y2; y<=y3; y++)
		{
			glVertex2f((int)x2, (int)y);
   		} 
	}
	else			//m>1 or m<1 or m=1
	{
		m=(y3-y2)/(x3-x2);
		c = y2-(m*x2);
		if(x2>x3)
		{
			swap(&x2,&x3);
			swap(&y2,&y3);
		}
		for( x=x2; x<=x3; x++)
		{
			y=(m*x)+c;
			y=round(y);
			glVertex2f((int)x, (int)y);
		}
	}
	glEnd();
	glFlush(); 	
} 
  
int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
	printf("Enter coordinates of x0 and y0: ");
	scanf("%d %d",&x2,&y2); 
	printf("Enter coordinates of x1 and y1: ");
	scanf("%d %d",&x3,&y3); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("Slope y=mx+c");
	init();	
	glutDisplayFunc(slope);
	glutMainLoop();
	return 0; 
} 
