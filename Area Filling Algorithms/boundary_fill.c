#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#define SIZE 10
int a0, b0, x[SIZE], y[SIZE], i, vertices;
float fill_colour[3], border_colour[3];

void init()
{
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
	border_colour[0] = 1; border_colour[1] = 1; border_colour[2] = 1; 
	glLineWidth(9.0);							                       //drawing the rectangle	
	glBegin(GL_LINE_LOOP);
        glColor3f(1,1,1);
        for(i=0; i<vertices; i++)
        {
            glVertex2f(x[i],y[i]);
        }
	glEnd();	
    glFlush();
}

void boundfill_four(int x, int y) 
{
    float current[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, current); 
  
    if((current[0]!=border_colour[0]) && (current[1]!=border_colour[1]) && (current[2]!=border_colour[2]) && 
       (current[0]!=fill_colour[0]) && (current[1]!=fill_colour[1]) && (current[2]!=fill_colour[2]))
    {
        glBegin(GL_POINTS);                            		            //drawing point
            glColor3f(fill_colour[0], fill_colour[1], fill_colour[2]);
            glVertex2f(x,y);	
        glEnd();
        boundfill_four(x+1, y);  
        boundfill_four(x-1, y);  
        boundfill_four(x, y+1);  
        boundfill_four(x, y-1); 
    }
	glFlush();
}

void boundfill_eight(int x, int y) 
{
    float current[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, current); 
  
    if((current[0]!=border_colour[0]) && (current[1]!=border_colour[1]) && (current[2]!=border_colour[2]) && 
       (current[0]!=fill_colour[0]) && (current[1]!=fill_colour[1]) && (current[2]!=fill_colour[2]))
    {
        glBegin(GL_POINTS);                            		            //drawing point
            glColor3f(fill_colour[0], fill_colour[1], fill_colour[2]);
            glVertex2f(x,y);	
        glEnd();
        boundfill_eight(x+1, y); 
        boundfill_eight(x, y+1); 
        boundfill_eight(x-1, y); 
        boundfill_eight(x, y-1); 
        boundfill_eight(x-1, y-1); 
        boundfill_eight(x-1, y+1); 
        boundfill_eight(x+1, y-1); 
        boundfill_eight(x+1, y+1); 
    }
	glFlush();
}

void key(int key, int x, int y)
{
	if(key == GLUT_KEY_LEFT)
	{
        boundfill_four(a0, (500-b0));
	}
    if(key == GLUT_KEY_RIGHT)
	{
        boundfill_eight(a0, (500-b0));
	}
}

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
    printf("Enter the number of vertices of polygon: ");
    scanf("%d",&vertices);
    printf("Enter the coordinates in cyclic order\n");
    for(i=0; i<vertices; i++)
    {
        printf("Vertex %d: ",i+1);
        scanf("%d%d",&x[i],&y[i]);
    }
    printf("Enter coordinates of the seed point: ");
	scanf("%d%d",&a0,&b0); 
    printf("Enter RGB value of colour to be filled: ");
    for(i=0; i<3; i++)
    {
        scanf("%f",&fill_colour[i]);
    }
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("Boundary Fill Algorithm");
	init();	
	glutDisplayFunc(display);
 	glutSpecialFunc(key);
	glutMainLoop();
	return 0; 
}