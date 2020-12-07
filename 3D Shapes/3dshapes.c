#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
int choice;
float xRotated, yRotated, zRotated, s_cube, r_cone, h_cone, r_sphere;
static int spin = 0;
/*----------------------------------------------------CONE----------------------------------------------------*/

void init_cone()
{
    glutInitWindowPosition(500,100);
	glutInitWindowSize(1000,750);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;
    glutCreateWindow("3D SHAPES - CONE");
    glClearColor(0.717, 0.949, 0.329,0);

	float mat_specular[] = { 0, 0, 1, 1 };                        // RGBA value of light
    float mat_shininess[] = { 70.0 };
    float light_position[] = { 1.0, 1.0, 1.0, 0.0 };              // Position of light

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);            // Assigning value to material parameters
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);                                        // Telling gl to use lighting calculations
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display_cone()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();                                             // Clear the identity matrix
    glTranslatef(0.0,0.0,-5.0);
    glColor3f(0.9, 0.3, 0.2); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);
    glutSolidCone(r_cone, h_cone,25, 25);                         // Drawing the cone
    glFlush();        
}

void animation_cone()
{
	xRotated += 0.02;
	yRotated += 0.02;
    zRotated += 0.02; 
    display_cone();
}

void reshape_cone(int x, int y)
{
    glViewport(0, 0, x, y);                                // Setting the viewport, using the whole window for rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-1.5, 1.5, -1.5*(float)750/(float)1000, 1.5*(float)750/(float)1000, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);                            // Apply matrix operations to the modelview matrix stack.
    glLoadIdentity();                                      // Clear the identity matrix
}

/*----------------------------------------------------SPHERE----------------------------------------------------*/

void init_sphere() 
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(500,100);
    glutInitWindowSize(1000,750);
    glutCreateWindow("3D SHAPES - SPHERE");
    glClearColor(0.717, 0.949, 0.329, 0);
    glShadeModel(GL_SMOOTH);                                        // Specify shading technique
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display_sphere()
{
    float mat_shininess[] = { 50.0 };
  	float mat_specular[] = { 1, 0, 0, 1 };                          // RGBA value of light
    float position[] = { 0.0, 0.0, 1.5, 1.0 };                      // Position of light source
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix ();
        glTranslatef (0.0, 0.0, -5.0);
        glPushMatrix ();
            glRotated ((GLdouble) spin, 1.0, 0.0, 0.0);
            glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);      // Assigning value to material parameters
            glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
            glLightfv (GL_LIGHT0, GL_POSITION, position);
            glTranslated (0.0, 0.0, 1.5);
            glDisable (GL_LIGHTING);
            
            glColor3f (1.0, 0.0, 0.0);                              // Drawing the light source
            glutSolidSphere(0.05,100,100);
            
            glEnable (GL_LIGHTING);
        glPopMatrix ();
        glutSolidSphere(r_sphere,100,100);
    glPopMatrix ();
    glFlush ();
}

void reshape_sphere(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse_sphere(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && button==GLUT_DOWN)
    {
        spin = (spin + 15) % 360;
        glutPostRedisplay();
    }
}

/*----------------------------------------------------CUBE----------------------------------------------------*/

void init_cube()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(500,100);
	glutInitWindowSize(1000,750);
    glutCreateWindow("3D SHAPES - CUBE");
    glClearColor(0.717, 0.949, 0.329, 0);
}

void display_cube()
{
    glMatrixMode(GL_MODELVIEW);                     // Apply matrix operations to the modelview matrix stack.
    glClear(GL_COLOR_BUFFER_BIT);                   // Clear the drawing buffer.
    glLoadIdentity();                               // Reset the matrix back to its default state.
    glTranslatef(0.0,0.0,-10.5);                    
    glRotatef(xRotated,1.0,0.0,0.0);                // rotation about X axis
    glRotatef(yRotated,0.0,1.0,0.0);                // rotation about Y axis
    glRotatef(zRotated,0.0,0.0,1.0);                // rotation about Z axis

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0,1.0,0.0);                     // TOP : BLUE 
        glVertex3f( s_cube, s_cube,-s_cube);        // Top Right
        glVertex3f(-s_cube, s_cube,-s_cube);        // Top Left
        glVertex3f(-s_cube, s_cube, s_cube);        // Bottom Left
        glVertex3f( s_cube, s_cube, s_cube);        // Bottom Right
    glEnd(); 
    
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0,0.5f,0.0);                    // BOTTOM : Orange
        glVertex3f( s_cube,-s_cube, s_cube);        // Top Right
        glVertex3f(-s_cube,-s_cube, s_cube);        // Top Left
        glVertex3f(-s_cube,-s_cube,-s_cube);        // Bottom Left
        glVertex3f( s_cube,-s_cube,-s_cube);        // Bottom Right
    glEnd(); 
    
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0,0.0,0.0);                     // FRONT : RED
        glVertex3f( s_cube, s_cube, s_cube);        // Top Right
        glVertex3f(-s_cube, s_cube, s_cube);        // Top Left
        glVertex3f(-s_cube,-s_cube, s_cube);        // Bottom Left
        glVertex3f( s_cube,-s_cube, s_cube);        // Bottom Right
    glEnd(); 
    
    glBegin(GL_LINE_LOOP);
        glColor3f(0.960, 0, 0.647);                 // BACK : PINK
        glVertex3f( s_cube,-s_cube,-s_cube);        // Top Right
        glVertex3f(-s_cube,-s_cube,-s_cube);        // Top Left
        glVertex3f(-s_cube, s_cube,-s_cube);        // Bottom Left
        glVertex3f( s_cube, s_cube,-s_cube);        // Bottom Right
    glEnd(); 
    
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0,0.0,1.0);                     // LEFT : BLUE
        glVertex3f(-s_cube, s_cube, s_cube);        // Top Right
        glVertex3f(-s_cube, s_cube,-s_cube);        // Top Left
        glVertex3f(-s_cube,-s_cube,-s_cube);        // Bottom Left
        glVertex3f(-s_cube,-s_cube, s_cube);        // Bottom Right
    glEnd(); 

    glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);                         // RIGHT : YELLOW
        glVertex3f( s_cube, s_cube,-s_cube);        // Top Right
        glVertex3f( s_cube, s_cube, s_cube);        // Top Left
        glVertex3f( s_cube,-s_cube, s_cube);        // Bottom Left
        glVertex3f( s_cube,-s_cube,-s_cube);        // Bottom Right
    glEnd();            
    glFlush();
}

void animation_cube()
{
    xRotated += 0.04;
    yRotated += 0.04;
    zRotated += 0.04;
    display_cube();
}

void reshape_cube(int x, int y)
{
    glMatrixMode(GL_PROJECTION);                    // Apply matrix operations to the projection matrix stack.
    glLoadIdentity();                               // Reset the matrix back to its default state.
    
    // Defining a view frustum: Angle of view = 30 degrees; Near clipping plane distance =  0.5; Far clipping plane distance = 40.0
    gluPerspective(30.0, (GLdouble)x/(GLdouble)y, 0.5, 40.0);      
    glMatrixMode(GL_MODELVIEW);                     // Apply matrix operations to the modelview matrix stack.
    glViewport(0,0,x,y);                            // Setting the viewport, using the whole window for rendering
}

/*----------------------------------------------------MAIN----------------------------------------------------*/

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
    printf("\n\n--------------------------3D SHAPES--------------------------\n\n1. Cone\n2. Sphere\n3. Cube\n0. Exit\n\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            printf("Enter base-radius of cone: ");
            scanf("%f",&r_cone);
            printf("Enter height of cone: ");
            scanf("%f",&h_cone);
            init_cone();
            glutDisplayFunc(display_cone);
            glutReshapeFunc(reshape_cone);
            glutIdleFunc(animation_cone);
            glutMainLoop();
            return 0;
        }
        case 2: 
        {
            printf("Enter radius of sphere: ");
            scanf("%f",&r_sphere);
            init_sphere();
            glutDisplayFunc(display_sphere); 
            glutReshapeFunc(reshape_sphere);
            glutMouseFunc(mouse_sphere);
            glutMainLoop();
            return 0;
        }
        case 3:
        {
            printf("Enter side of cube: ");
            scanf("%f",&s_cube);
            init_cube();
            glutDisplayFunc(display_cube);
            glutReshapeFunc(reshape_cube);
            glutIdleFunc(animation_cube);                        // Perform continuous animation in background
            glutMainLoop();
            return 0;
        }
        case 0: return 0;
        default: printf("Wrong Choice\n"); return 0;
    }
}