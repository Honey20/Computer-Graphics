#include<stdio.h>
#include<stdbool.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
int x_min, x_max, y_min, y_max, x_0, y_0, x_1, y_1;
#define TOP 8     // TBRL - 1000
#define BOTTOM 4  // TBRL - 0100
#define RIGHT 2   // TBRL - 0010
#define LEFT 1    // TBRL - 0001

void init()
{
	glClearColor(0.568, 0.968, 0.874, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(9.0);							//drawing the window	
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(x_min, y_min);
	glVertex2f(x_max, y_min);
	glVertex2f(x_max, y_max);
	glVertex2f(x_min, y_max);
	glEnd();	

	glLineWidth(9.0);							//drawing the given line
	glBegin(GL_LINES);
	glColor3f(0.949, 0.250, 0.250);
	glVertex2f(x_0, y_0);
	glVertex2f(x_1, y_1);
	glEnd();	
	glFlush();
}

int TBRL(int a, int b)
{
	int code = 0;  
	if(b > y_max)  			
    	code = code | TOP;
  	if(b < y_min)  
  		code = code | BOTTOM;
  	if(a > x_max)  
    	code = code | RIGHT;
  	if(a < x_min)  
    	code = code | LEFT;
  	return code;
}

void cohen()
{
	int code_1, code_2, x, y, code_int;					
	code_1 = TBRL(x_0, y_0);						//computing TBRL codes of both the lines
	code_2 = TBRL(x_1, y_1);						
	bool valid = false;

	while(valid==false)
	{
		if((code_1==0) && (code_2==0))				//line is completely inside
		{
			valid = true; 							//drawing the given line and window as it is
			break;
		}
		else if((code_1 & code_2)!=0)				//if AND of both codes is not 0, line is completely outside
		{
			break;
		}
		else if((code_1 & code_2)==0)				//if AND of both codes is 0, line is partially inside
		{
			if(code_1!= 0) 							//chosing an end point outside the window
    	    {
				code_int = code_1;
			} 
    	    else if(code_1==0) 	
			{
    	       code_int = code_2; 
			}
			if(code_int & TOP)						//point is above window
			{ 
   	            x = x_0 + (((x_1 - x_0) * (y_max - y_0)) / (y_1 - y_0)); 
   	            y = y_max; 
    	    } 
        	else if(code_int & BOTTOM) 				//point is below window
			{ 
            	x = x_0 + (((x_1 - x_0) * (y_min - y_0)) / (y_1 - y_0)); 
	            y = y_min; 
    	    } 
        	else if(code_int & RIGHT) 				//point is on the right of window
			{ 
	           	y = y_0 + (((y_1 - y_0) * (x_max - x_0)) / (x_1 - x_0)); 
	            x = x_max; 
    	    } 
        	else if(code_int & LEFT) 				//point is on the left of window
			{ 
              	y = y_0 + (((y_1 - y_0) * (x_min - x_0)) / (x_1 - x_0)); 
	            x = x_min; 
	        } 
			if(code_int == code_1) 					//replacing point outside the window with intersection 	point
			{ 	
	            x_0 = x; 
				y_0 = y; 
    	        code_1 = TBRL(x_0, y_0); 
        	} 
            else 
			{ 
    	        x_1 = x; 
				y_1 = y; 
        	    code_2 = TBRL(x_1, y_1); 
            } 
		}
	}

	if(valid==true) 					
    {
		glLineWidth(9.0);							//drawing the window	
		glBegin(GL_LINE_LOOP);
		glColor3f(0.949, 0.250, 0.250);
		glVertex2f(x_min, y_min);
		glVertex2f(x_max, y_min);
		glVertex2f(x_max, y_max);
		glVertex2f(x_min, y_max);
		glEnd();	

		glLineWidth(9.0);							//drawing the given line
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2f(x_0, y_0);	
		glVertex2f(x_1, y_1);
		glEnd();
		glFlush();	
	}

    else 
    {
		glLineWidth(9.0);							//drawing the window	
		glBegin(GL_LINE_LOOP);
		glColor3f(0.843, 0.078, 0.223);
		glVertex2f(x_min, y_min);
		glVertex2f(x_max, y_min);
		glVertex2f(x_max, y_max);
		glVertex2f(x_min, y_max);
		glEnd();	
		glFlush();
    }
}

void key(int key, int x, int y)
{
	if(key == GLUT_KEY_RIGHT)
	{
		glClearColor(0.568, 0.968, 0.874, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		cohen();
	}
}

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
	printf("Enter the value of x_min: ");
	scanf("%d",&x_min); 
	printf("Enter the value of x_max: ");
	scanf("%d",&x_max); 
	printf("Enter the value of y_min: ");
	scanf("%d",&y_min); 
	printf("Enter the value of y_max: ");
	scanf("%d",&y_max); 
	printf("Enter the coordinates of line\nx_0 and y_0: ");
	scanf("%d%d",&x_0,&y_0); 
	printf("x_1 and y_1: ");
	scanf("%d%d",&x_1,&y_1); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("Cohen-Sutherland Line Clipping Algorithm");
	init();	
	glutDisplayFunc(display);
 	glutSpecialFunc(key);
	glutMainLoop();
	return 0; 
}