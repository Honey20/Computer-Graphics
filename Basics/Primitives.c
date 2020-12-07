#include<GL/glut.h>
#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,1,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.9,0.1);
	glVertex2f(-0.9,0.6);
	glVertex2f(-0.6,0.4);
	glEnd();
	glColor3f(0,0,0);
	glRasterPos2f(-0.90,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "GL_TRIANGLES");
	
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(-0.5,0.1);
	glVertex2f(-0.2,0.1);
	glVertex2f(-0.5,0.5);
	glVertex2f(-0.2,0.5);
	glEnd();	
	glColor3f(0,0,0);
	glRasterPos2f(-0.50,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "GL_POLYGON");

	glPointSize(10.0);	
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(0,0.1);
	glVertex2f(0,0.2);
	glVertex2f(0.2,0.5);	
	glEnd();	
	glColor3f(0,0,0);
	glRasterPos2f(0,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "GL_POINTS");

	glLineWidth(10.0);	
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(0.4,0.1);
	glVertex2f(0.4,0.4);
	glVertex2f(0.5,0.1);
	glVertex2f(0.6,0.5);		
	glEnd();	
	glColor3f(0,0,0);
	glRasterPos2f(0.4,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "GL_LINES");

	glLineWidth(10.0);	
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
	glVertex2f(-0.9,-0.2);
	glVertex2f(-0.6,-0.2);
	glVertex2f(-0.9,-0.5);
	glVertex2f(-0.6,-0.5);	
	glEnd();	
	glColor3f(0,0,0);
	glRasterPos2f(-0.9,-0.8);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "GL_LINE_STRIP");

	glLineWidth(10.0);	
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(-0.4,-0.2);
	glVertex2f(0,-0.3);
	glVertex2f(-0.1,-0.5);
	glVertex2f(-0.3,-0.6);	
	glEnd();	
	glColor3f(0,0,0);
	glRasterPos2f(-0.4,-0.8);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "GL_LINE_LOOP");

	glBegin(GL_QUADS);
	glColor3f(1,1,0);
	glVertex2f(0.2,-0.4);
	glVertex2f(0.3,-0.3);
	glVertex2f(0.4,-0.3);
	glVertex2f(0.6,-0.4);
	glVertex2f(0.6,-0.5);
	glVertex2f(0.5,-0.7);
	glVertex2f(0.3,-0.6);
	glVertex2f(0.3,-0.5);	
	glEnd();	
	glColor3f(0,0,0);
	glRasterPos2f(0.3,-0.8);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "GL_QUADS");
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1200,750);
	glutInitWindowPosition(500,300);
	glutCreateWindow("All primitives");
	glClearColor(1,0,1,1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
