#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
float shift=0;

void init()
{
	glClearColor(0.078, 0.101, 0.098, 0.098);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,600,0,400);
}

void scenery()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int i,j;
	for(i=-100;i<600;i+=40)
	{	
		for(j=600;j>=0;j-=60)
		{
			glBegin(GL_POINTS);
			glPointSize(10.0);	
			glColor3f(1,1,1);
			glVertex2f(i,j);
			glVertex2f(i+60,j+30);
			glEnd();
		}
	}

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(0,0);
	glVertex2i(600,0);
	glVertex2i(600,150);
	glVertex2i(0,150);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.819, 0.019, 0.062);
	glVertex2i(200+shift,150);
	glVertex2i(400+shift,150);
	glVertex2i(450+shift,200);
	glVertex2i(150+shift,200);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.992, 0.972, 0.090);
	glVertex2i(250+shift,200);
	glVertex2i(362+shift,200);
	glVertex2i(306+shift,270);
	glEnd();

	for(i=20;i<600;i+=40)
	{	
		for(j=130;j>0;j-=60)
		{
			glBegin(GL_LINES);
			glColor3f(0,0,1.0);
			glVertex2i(i,j);
			glVertex2i(i+20,j);
			glEnd();
		}
	}

	for(i=0;i<580;i+=40)
	{	
		for(j=100;j>0;j-=60)
		{
			glBegin(GL_LINES);
			glColor3f(0,0,1.0);
			glVertex2i(i,j);
			glVertex2i(i+20,j);
			glEnd();
		}
	}
	glFlush();
}

//Mouse Event
void mouse(int button, int state, int x, int y)
{
	int temp,temp_int;
	if(button==GLUT_LEFT_BUTTON && button==GLUT_DOWN)
	{
		x = 40;
		y = 340;
		glColor3f(1,1,1);
		glBegin(GL_POLYGON);
		glVertex2d(x,y);
		while(x < 120)
		{
			x = x + 1;
			temp = sqrt(pow(40,2)-pow(x-80,2));
			temp_int = temp+0.5;
			glVertex2d(x,y+temp_int); 
			glVertex2d(x,y-temp_int);
		}
		glEnd();
	}
	glFlush();
}

//Keyboard Event
void key(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_RIGHT:
		{
			shift++;
			glutPostRedisplay();
			break;
		}
		case GLUT_KEY_LEFT:
		{
			shift--;
			glutPostRedisplay();
			break;
		}
	}
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(1200,750);
	glutCreateWindow("Scenery");
	init();
	glutDisplayFunc(scenery);
	glutSpecialFunc(key);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}









