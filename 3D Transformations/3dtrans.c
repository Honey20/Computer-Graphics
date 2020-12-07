#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h> 
#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180)
int choice, choice1, choice2, choice3, x_c[8], y_c[8], z_c[8], i; 
int x[8] = {20, 120, 120, 20, 0, 100, 100, 0};
int y[8] = {70, 70, 20, 20, 50, 50, 0, 0};
int z[8] = {0, 0, 0, 0, 150, 150, 150, 150};

void init()
{
	glClearColor(0,0,0,1);
  	glMatrixMode(GL_PROJECTION);
	glOrtho(-500,500,-500,500,-500,500);
}

void display() 
{

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
	glutInitWindowPosition(500,100);
	glutInitWindowSize(1000,750);
	glutCreateWindow("3D Transformations");
	init();
    
    glColor3f(0.956, 0.509, 0.101);
    glRasterPos3f(-400,450,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "BEFORE TRANSFORMATION");
	
    glColor3f(0.262, 0.898, 0.043);
	glRasterPos3f(150,450,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, "AFTER TRANSFORMATION");

    glColor3f(0.956, 0.509, 0.101);                             // Drawing initial polygon 
    glLineWidth(2.0);	
    // TOP BAEF
    glBegin(GL_LINE_LOOP);     						                                 
        glVertex3f(x[1], y[1], z[1]);
        glVertex3f(x[0], y[0], z[0]);  
        glVertex3f(x[4], y[4], z[4]);
        glVertex3f(x[5], y[5], z[5]);  
    glEnd();

    // BOTTOM GHDC
    glBegin(GL_LINE_LOOP);
        glVertex3f(x[6], y[6], z[6]);
        glVertex3f(x[7], y[7], z[7]);  
        glVertex3f(x[3], y[3], z[3]);
        glVertex3f(x[2], y[2], z[2]);
    glEnd();

    // FRONT FEHG
    glBegin(GL_LINE_LOOP);
        glVertex3f(x[5], y[5], z[5]);  
        glVertex3f(x[4], y[4], z[4]);
        glVertex3f(x[7], y[7], z[7]);  
        glVertex3f(x[6], y[6], z[6]);
    glEnd();

    // BACK CDAB
    glBegin(GL_LINE_LOOP);
        glVertex3f(x[2], y[2], z[2]);
        glVertex3f(x[3], y[3], z[3]);
        glVertex3f(x[0], y[0], z[0]);  
        glVertex3f(x[1], y[1], z[1]);
    glEnd();

    // LEFT EADH
    glBegin(GL_LINE_LOOP);
        glVertex3f(x[4], y[4], z[4]);
        glVertex3f(x[0], y[0], z[0]);  
        glVertex3f(x[3], y[3], z[3]);
        glVertex3f(x[7], y[7], z[7]);  
    glEnd();

    // RIGHT BFGC
    glBegin(GL_LINE_LOOP);
        glVertex3f(x[1], y[1], z[1]);
        glVertex3f(x[5], y[5], z[5]);  
        glVertex3f(x[6], y[6], z[6]);
        glVertex3f(x[2], y[2], z[2]);
    glEnd();
                                        
    glColor3f(0.262, 0.898, 0.043);                 // Drawing polygon after transformation 
    glLineWidth(2.0);							                                 
    // TOP BAEF
    glBegin(GL_LINE_LOOP);     						                                 
        glVertex3f(x_c[1], y_c[1], z_c[1]);
        glVertex3f(x_c[0], y_c[0], z_c[0]);  
        glVertex3f(x_c[4], y_c[4], z_c[4]);
        glVertex3f(x_c[5], y_c[5], z_c[5]);  
    glEnd();

    // BOTTOM GHDC
    glBegin(GL_LINE_LOOP);
        glVertex3f(x_c[6], y_c[6], z_c[6]);
        glVertex3f(x_c[7], y_c[7], z_c[7]);  
        glVertex3f(x_c[3], y_c[3], z_c[3]);
        glVertex3f(x_c[2], y_c[2], z_c[2]);
    glEnd();

    // FRONT FEHG
    glBegin(GL_LINE_LOOP);
        glVertex3f(x_c[5], y_c[5], z_c[5]);  
        glVertex3f(x_c[4], y_c[4], z_c[4]);
        glVertex3f(x_c[7], y_c[7], z_c[7]);  
        glVertex3f(x_c[6], y_c[6], z_c[6]);
    glEnd();

    // BACK CDAB
    glBegin(GL_LINE_LOOP);
        glVertex3f(x_c[2], y_c[2], z_c[2]);
        glVertex3f(x_c[3], y_c[3], z_c[3]);
        glVertex3f(x_c[0], y_c[0], z_c[0]);  
        glVertex3f(x_c[1], y_c[1], z_c[1]);
    glEnd();

    // LEFT EADH
    glBegin(GL_LINE_LOOP);
        glVertex3f(x_c[4], y_c[4], z_c[4]);
        glVertex3f(x_c[0], y_c[0], z_c[0]);  
        glVertex3f(x_c[3], y_c[3], z_c[3]);
        glVertex3f(x_c[7], y_c[7], z_c[7]);  
    glEnd();

    // RIGHT BFGC
    glBegin(GL_LINE_LOOP);
        glVertex3f(x_c[1], y_c[1], z_c[1]);
        glVertex3f(x_c[5], y_c[5], z_c[5]);  
        glVertex3f(x_c[6], y_c[6], z_c[6]);
        glVertex3f(x_c[2], y_c[2], z_c[2]);
    glEnd();

    glFlush();
    glutMainLoop();
}

void translation()
{
    printf("\n\n----------------------------TRANSLATION----------------------------\n");
    int T[3];
    printf("Enter translation factor (dx dy dz): ");
    scanf("%d%d%d",&T[0],&T[1],&T[2]);
    for(i=0; i<8; i++)
    {
        x_c[i] = x[i] + T[0];                // Increasing each vertex by adding the respective translation factor
        y_c[i] = y[i] + T[1];
        z_c[i] = z[i] + T[2];
    }
    display();
}

void rotation()
{
    int angle;
    printf("\n\n----------------------------OPERATIONS FOR ROTATION----------------------------\n\n1. About X-AXIS\n2. About Y-AXIS\n3. About Z-AXIS\n\nEnter your choice: ");
    scanf("%d",&choice1);
    printf("Enter angle of rotation (in degree): ");
    scanf("%d",&angle);
    switch(choice1)
    {
        case 1:
        {
            printf("\n\n----------------------------ROTATION ABOUT X-AXIS----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = x[i];
                y_c[i] = (y[i] * COS(angle)) - (z[i] * SIN(angle));
                z_c[i] = (y[i] * SIN(angle)) + (z[i] * COS(angle));
            }
            display();
        }
        case 2: 
        {
            printf("\n\n----------------------------ROTATION ABOUT Y-AXIS----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = (z[i] * SIN(angle)) + (x[i] * COS(angle));
                y_c[i] = y[i];
                z_c[i] = (y[i] * COS(angle)) - (x[i] * SIN(angle));
            }
            display();
        }
        case 3:
        {
            printf("\n\n----------------------------ROTATION ABOUT Z-AXIS----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = (x[i] * COS(angle)) - (y[i] * SIN(angle));
                y_c[i] = (x[i] * SIN(angle)) + (y[i] * COS(angle));
                z_c[i] = z[i];
            }
            display();
        }
        default: printf("Wrong Choice\n"); break;
    }
}

void scaling()
{
    printf("\n\n----------------------------SCALING----------------------------\n");
    int SCALE[3];   
    printf("Enter the scaling factor (dx dy dz): ");
    scanf("%d%d%d",&SCALE[0],&SCALE[1],&SCALE[2]);                   
    for(i=0; i<8; i++)
    {
        x_c[i] = x[i] * SCALE[0];                         // Increasing each vertex by respective scale factor
        y_c[i] = y[i] * SCALE[1];
        z_c[i] = z[i] * SCALE[2];
    }
    display();
}

void reflection()
{
    printf("\n\n----------------------------OPERATIONS FOR REFLECTION----------------------------\n\n1. About XY-Plane\n2. About YZ-Plane\n3. About ZX-Plane\n\nEnter your choice: ");
    scanf("%d",&choice2);
    switch(choice2)
    {
        case 1:
        {
            printf("\n\n----------------------------REFLECTION ABOUT XY-PLANE----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = x[i];
                y_c[i] = y[i];
                z_c[i] = -z[i];
            }
            display();
        }
        case 2: 
        {
            printf("\n\n----------------------------REFLECTION ABOUT YZ-PLANE----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = -x[i];
                y_c[i] = y[i];
                z_c[i] = z[i];
            }
            display();
        }
        case 3:
        {
            printf("\n\n----------------------------REFLECTION ABOUT ZX-PLANE----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = x[i];
                y_c[i] = -y[i];
                z_c[i] = z[i];
            }
            display();
        }
        default: printf("Wrong Choice\n"); break;
    }
}

void shearing()
{
    int SHEAR[3];
    printf("\n\n----------------------------OPERATIONS FOR SHEARING----------------------------\n\n1. About X-Axis\n2. About Y-Axis\n3. About Z-Axis\n\nEnter your choice: ");   
    scanf("%d",&choice3); 
    printf("Enter the shearing factor (sx sy sz): ");
    scanf("%d%d%d",&SHEAR[0],&SHEAR[1],&SHEAR[2]);
    
    switch(choice3)
    {
        case 1:
        {
            printf("\n\n----------------------------SHEARING ABOUT X-AXIS----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = x[i];
                y_c[i] = y[i]  + SHEAR[1] * x[i];
                z_c[i] = z[i]  + SHEAR[2] * x[i];
            }
            display();
        }
        case 2: 
        {
            printf("\n\n----------------------------SHEARING ABOUT Y-AXIS----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = x[i]  + SHEAR[0] * y[i];
                y_c[i] = y[i];
                z_c[i] = z[i]  + SHEAR[2] * y[i];
            }
            display();
        }
        case 3:
        {
            printf("\n\n----------------------------SHEARING ABOUT Z-AXIS----------------------------\n");
            for(i=0; i<8; i++)
            {
                x_c[i] = x[i]  + SHEAR[0] * z[i];
                y_c[i] = y[i]  + SHEAR[1] * z[i];
                z_c[i] = z[i];
            }
            display();
        }
        default: printf("Wrong Choice\n"); break;
    }
}

int main(int argc,char** argv) 
{
	glutInit(&argc,argv);

    // printf("Enter coordinates of cuboid in cyclic order:\n");
    // for(i=0; i<8; i++)
    // {
    //     printf("Vertex %d: ",i+1);
    //     scanf("%d%d%d",&x[i],&y[i],&z[i]);
    // }
   
    printf("\n\n----------------------------3D TRANSFORMATION----------------------------\n\n1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5. Shearing\n0. Exit\n\nEnter your choice: ");
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