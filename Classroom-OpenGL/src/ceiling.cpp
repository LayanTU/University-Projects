//ceiling
#include <GL/freeglut.h> 

bool lightOn = true;

void drawCeiling() {
    
    glColor3ub(220, 220, 220);
    glBegin(GL_QUADS);
    glVertex2i(-45, 15); glVertex2i(45, 15);
    glVertex2i(35, 25); glVertex2i(-35, 25);
    glEnd();

    glColor3ub(150, 150, 150);
    glLineWidth(1);
    glBegin(GL_LINES);
    // Vertical lines
    for (int x = -45; x <= 45; x += 8) {
        glVertex2i(x, 15); glVertex2i(x + 10, 25); 
    }
     
    // Horizontal lines
    for (int y = 16; y <= 24; y += 2) {
        glVertex2i(-45, y); glVertex2i(45, y);
    }
    glEnd();

    // Lights
    if (lightOn)
        glColor3ub(255, 255, 180);
    else
        glColor3ub(100, 100, 100);

    glBegin(GL_QUADS);

    // Front left
    glVertex2i(-35, 18); glVertex2i(-20, 18);
    glVertex2i(-15, 22); glVertex2i(-30, 22);

    // Front middle
    glVertex2i(-5, 18); glVertex2i(10, 18);
    glVertex2i(15, 22); glVertex2i(0, 22);

    // Front right
    glVertex2i(25, 18); glVertex2i(40, 18);
    glVertex2i(45, 22); glVertex2i(30, 22);

    // Back left
    glVertex2i(-40, 23); glVertex2i(-28, 23);
    glVertex2i(-24, 25); glVertex2i(-36, 25);

    // Back middle
    glVertex2i(-10, 23); glVertex2i(2, 23); 
    glVertex2i(6, 25); glVertex2i(-6, 25);

    // Back right
    glVertex2i(20, 23); glVertex2i(32, 23);
    glVertex2i(36, 25); glVertex2i(24, 25);
    glEnd();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        lightOn = !lightOn;
        glutPostRedisplay();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawCeiling();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-50, 50, -25, 25);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ceiling");
    init();
    glutDisplayFunc(display);

    glutMouseFunc(mouse);
    
    glutMainLoop();
    return 0;
}