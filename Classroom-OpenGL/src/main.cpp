#include <GL/gl.h>
#include <GL/glut.h>

void drawDoor() {
    //Door frame - larger than the door by 2
    glColor3ub(101, 67, 33); //dark brown
    glBegin(GL_QUADS);
        glVertex2i(-6, -15); glVertex2i( 6, -15); 
        glVertex2i( 6,  12); glVertex2i(-6,  12); 
    glEnd();
    
    //Door - written over the frame to hide the frame's inside part
    glColor3ub(150, 75, 0); //brown
    glBegin(GL_QUADS);
        glVertex2i(-5, -15); glVertex2i( 5, -15); 
        glVertex2i( 5,  11); glVertex2i(-5,  11);
    glEnd();

    //Door handle - written like a rotated T
    glColor3ub(128, 128, 128); //gray
    glBegin(GL_QUADS);
        //Vertical part - T head
       glVertex2i(3, -3); glVertex2i(4, -3); 
       glVertex2i(4, -1); glVertex2i(3, -1);
    
       //Horizontal part - T base
       glVertex2i(1, -2); glVertex2i(3, -2); 
       glVertex2i(3, -1); glVertex2i(1, -1);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    //left door
    glPushMatrix(); 
    glTranslatef(-35, 0, 0);
    drawDoor();
    glPopMatrix();

    //right door
    glPushMatrix();
    glTranslatef(35, 0, 0);
    drawDoor();
    glPopMatrix();

    glFlush();  
}

void init() {
    glClearColor(172, 147, 98, 1); //beige
    gluOrtho2D(-50, 50, -25, 25);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500); 
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Door");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}