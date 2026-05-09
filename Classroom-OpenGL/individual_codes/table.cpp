//teacher's table
#include <GL/gl.h>
#include <GL/glut.h>

void DrawPodium() {
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
        glVertex2i(-1, -13); glVertex2i(-5, -10);
        glVertex2i(-5, 0); glVertex2i(-1, 0);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
        glVertex2i(4, -13); glVertex2i(-1, -13);
        glVertex2i(-1, 0); glVertex2i(4, 0);
    glEnd();

    glColor3ub(100, 50, 18); 
    glBegin(GL_QUADS);
        glVertex2i(-1, -13); glVertex2i(-5, -10);
        glVertex2i(-6, -11); glVertex2i(-2, -14);
    glEnd();

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2i(2, 0); glVertex2i(-6, 0);
        glVertex2i(-6, 5); glVertex2i(0, 7);
        glVertex2i(2, 7);
    glEnd();

    glColor3ub(190, 115, 75);
    glBegin(GL_POLYGON);
        glVertex2i(-2, -2); glVertex2i(-2, 4); 
        glVertex2i(3, 6); glVertex2i(5, 6); 
        glVertex2i(5, -2);
    glEnd();

    glColor3ub(255, 245, 238);
    glBegin(GL_QUADS);
        glVertex2i(1, -1); glVertex2i(1, 2);
        glVertex2i(4, 2); glVertex2i(4, -1);
    glEnd();

    glColor3ub(218, 165, 32);
    glLineWidth(5.0);
    glBegin(GL_LINES);
        glVertex2f(2.0, 0.3); glVertex2f(2.0, 1.3);
        glVertex2f(1.2, 1.4); glVertex2f(2.8, 1.4);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(2.5, 1.0); glVertex2f(2.5, 0.3);
        glVertex2f(3.6, 0.3); glVertex2f(3.6, 1.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    DrawPodium();
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
    glutCreateWindow("Table");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}