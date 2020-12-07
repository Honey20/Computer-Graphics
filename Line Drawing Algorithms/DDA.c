#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

float x_0, y_0, x_1, y_1, temp, m,c;

void swap(float *a, float *b)
{
	temp = *a; 
	*a = *b; 
	*b = temp;
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void slope() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0.023, 0);
	glPointSize(4.0);	
	glBegin(GL_POINTS);
	int x,y; 
	if(x_0!=x_1)
	{
		m=(y_1-y_0)/(x_1-x_0);
	}
	
	if(x_0==x_1)			//Infinite Slope, Vertical Line
	{
		if(y_0>y_1)
		{
			swap(&y_0,&y_1);
		}
		for(y=y_0; y<=y_1; y++)
		{
			glVertex2f((int)x_0, (int)y);
   		}
	}
	else if (m<1)		//Slope less than 1
	{
		y=y_0;
		if(x_0>x_1)
		{
			y=y_1;
			swap(&x_0,&x_1);
			swap(&y_0,&y_1);
		}		

		for(x=x_0; x<=x_1; x++)
		{
			glVertex2f((int)x, (int)y);
			y+=m;
			y=round(y);
		}
	}
	else if (m>=1)		//Slope greater than or equal to 1
	{
		x=x_0;
		if(y_0>y_1)
		{
			x=x_1;
			swap(&y_0,&y_1);
			swap(&x_0,&x_1);
		}
		for(y=y_0; y<=y_1; y++)
		{
			glVertex2f((int)x, (int)y);
			x=+1/m;
			x=round(x);

		}
	}
	else				//m = 0, Horizontal Line	
	{
		y=y_0;
		if(x_0>x_1)
		{
			y=y_1;
			swap(&x_0,&x_1);
			swap(&y_0,&y_1);
		}
		for(x=x_0; x<=x_1; x++)
		{
			glVertex2f((int)x, (int)y);
			y+=1;
		}
	}
	glEnd();
	glFlush(); 	
} 

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
	printf("Enter coordinates of x0 and y0: ");
	scanf("%f %f",&x_0,&y_0); 
	printf("Enter coordinates of x1 and y1: ");
	scanf("%f %f",&x_1,&y_1); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("DDA Algorithm");
	glClearColor(0.643, 0.976, 0.945, 1);
	init();	
	glutDisplayFunc(slope);
	glutMainLoop();
	return 0; 
}

