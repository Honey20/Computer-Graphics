#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h> 
#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180)
int xc[10], yc[10], i, choice, choice1, line_x[2], c;
float slope;
int vertices, x[10],y[10];

void init()
{
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500,500,-500,500);
}

void display() 
{
   	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,100);
	glutInitWindowSize(1000,750);
	glutCreateWindow("2D Transformations");
	init();

    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.956, 0.509, 0.101);
    glRasterPos2f(-400,450);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "BEFORE TRANSFORMATION");
	
    glColor3f(0.262, 0.898, 0.043);
	glRasterPos2f(150,450);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "AFTER TRANSFORMATION");

    if(choice==4)                                                             // Drawing x and y axis
    {
        glBegin(GL_LINES);
            glColor3f(0.529, 0.490, 0.490);
            glVertex2f(0,500);
            glVertex2f(0,-500);	
            glVertex2f(-500,0);
            glVertex2f(500,0);		
        glEnd();	
    }
    if(choice1==3||choice1==4)                                                // Drawing lines y = x and y = -x
    {
        glBegin(GL_LINES);
            glColor3f(0.529, 0.490, 0.490);
            glVertex2f(500,500);
            glVertex2f(-500,-500);	
            glVertex2f(-500,500);
            glVertex2f(500,-500);		
        glEnd();	
    }
    if(choice1==6)                                                            // Drawing line with equation y = mx + c
    {
        glBegin(GL_LINES);
        glColor3f(0.529, 0.490, 0.490);
            glVertex2f(line_x[0],((slope*line_x[0]) + c));
            glVertex2f(line_x[1],((slope*line_x[1]) + c));	
        glEnd();	
    }

    glLineWidth(2.0);							                              // Drawing initial polygon     
	glBegin(GL_LINE_LOOP);
        glColor3f(0.956, 0.509, 0.101);
        for(i=0; i<vertices; i++)
        {
            glVertex2f(x[i],y[i]);
        }
	glEnd();	
    
    glBegin(GL_LINE_LOOP);                                                    // Drawing polygon after transformation
        glColor3f(0.262, 0.898, 0.043);
        for(i=0; i<vertices; i++)
        {
            glVertex2f(xc[i],yc[i]);
        }
	glEnd();
    glFlush();
    glutMainLoop();
}

void translation()
{
    printf("\n\n----------------------------TRANSLATION----------------------------\n");
    int T[2];
    printf("Enter translation factor (dx dy): ");
    scanf("%d%d",&T[0],&T[1]);
    for(i=0; i<vertices; i++)
    {
        xc[i] = xc[i] + T[0];                                          // Increasing each vertex by adding the respective translation factor
        yc[i] = yc[i] + T[1];
    }
    display();
}

void rotation()
{
    printf("\n\n----------------------------ROTATION----------------------------\n");
    int x_pivot, y_pivot, angle, x_shifted, y_shifted;
    printf("Enter pivot point: ");
    scanf("%d%d",&x_pivot,&y_pivot);
    printf("Enter angle of rotation (in degree): ");
    scanf("%d",&angle);

    for(i=0; i<vertices; i++)
    {
        x_shifted = xc[i] - x_pivot;                             // Shifting the pivot point to the origin and the given points accordingly 
        y_shifted = yc[i] - y_pivot; 
        xc[i] = x_pivot + (x_shifted*COS(angle) - y_shifted*SIN(angle)); // Calculating the rotated point co-ordinates and shifting it back 
        yc[i] = y_pivot + (x_shifted*SIN(angle) + y_shifted*COS(angle)); 
    }
    display();
}

void scaling()
{
    printf("\n\n----------------------------SCALING----------------------------\n");
    int x_scale, y_scale;   
    printf("Enter the scaling factor: ");
    scanf("%d%d",&x_scale,&y_scale);                   

    for (i = 0; i < vertices; i++)                                          
    {
        xc[i] = xc[i] * x_scale;                                              // Increasing each vertex by respective scale factor
        yc[i] = yc[i] * y_scale;
    }
    display();
}

void x_axis()
{
    printf("\n\n----------------------------REFLECTION ABOUT X-AXIS----------------------------\n");
    for (i = 0; i < vertices; i++)                                          
        yc[i] = -yc[i];
    display();
}

void y_axis()
{
    printf("\n\n----------------------------REFLECTION ABOUT Y-AXIS----------------------------\n");
    for (i = 0; i < vertices; i++)                                          
        xc[i] = -xc[i];
    display();
}

void y_equal_xp()           
{
    printf("\n\n----------------------------REFLECTION ALONG LINE y = x----------------------------\n");
    for(i=0; i<vertices; i++)
    {
        xc[i] = y[i];
        yc[i] = x[i];
    }                                          
    display();
}

void y_equal_xn()       
{
    printf("\n\n----------------------------REFLECTION ALONG LINE y = -x----------------------------\n");
    for(i=0; i<vertices; i++)
    {
        xc[i] = -y[i];
        yc[i] = -x[i];
    }                                          
    display();
}

void origin()
{
    printf("\n\n----------------------------REFLECTION ABOUT ORIGIN----------------------------\n");
    for (i = 0; i < vertices; i++) 
    {                                         
        xc[i] = -xc[i];
        yc[i] = -yc[i];
    }
    display();
}

void straight_line()
{
    printf("\n\n----------------------------REFLECTION ALONG A STRAIGHT LINE----------------------------\n");
    printf("Enter starting x-coordinate of line: ");
    scanf("%d",&line_x[0]);
    printf("Enter ending x-coordinate of line: ");
    scanf("%d",&line_x[1]);
    printf("Enter slope of line: ");
    scanf("%f",&slope);
    printf("Enter intercept of line: ");
    scanf("%d",&c);
    printf("\nEquation of given line is: y = %0.2fx + %d\n",slope,c);

    float m = slope*slope;
    for (i=0; i < vertices; i++)
    {
        xc[i] = (((1 - m) * x[i]) + (2 * slope * (y[i] - c))) / (1 + m);
        yc[i] = (((m - 1) * y[i]) + (2 * slope * x[i]) + 2*c) / (1 + m);
    }
    display();
}

void reflection()
{
    printf("\n\n----------------------------OPERATIONS FOR REFLECTION----------------------------\n\n1. About x-axis\n2. About y-axis\n3. y = x\n4. y = -x\n5. About origin\n6. y = mx +c\n9. Exit\n\nEnter your choice: ");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1: x_axis();
        case 2: y_axis();
        case 3: y_equal_xp();
        case 4: y_equal_xn();
        case 5: origin();
        case 6: straight_line();
        case 9: break;
        default: printf("Wrong Choice\n"); break;
    }
}

void shearing()
{
    printf("\n\n----------------------------SHEARING----------------------------\n");
    int shear, choice2;
    printf("Enter the shearing factor: ");
    scanf("%d",&shear);
    printf("Enter 1 for shearing along x-axis and 2 for shearing along y-axis: ");
    scanf("%d",&choice2);
    switch(choice2)
    {
        case 1:
        {
            for (i = 0; i < vertices; i++) 
            {                                         
                xc[i] = x[i] + shear * y[i];
                yc[i] = y[i];
            }
            display();
        }
        case 2: 
        {
            for (i = 0; i < vertices; i++) 
            {                                         
                xc[i] = x[i];
                yc[i] = y[i] + shear * x[i];
            }
            display();
        }
        default: printf("Wrong Choice\n"); break;
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
        xc[i] = x[i]; yc[i] = y[i];
    }
    
    printf("\n\n----------------------------2D TRANSFORMATION----------------------------\n\n1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5. Shearing\n0. Exit\n\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: translation(); break;
        case 2: rotation(); break;
        case 3: scaling(); break;
        case 4: reflection(); break;
        case 5: shearing(); break;
        case 0: break;
        default: printf("Wrong Choice\n"); break;
    }
    return 0; 
}
