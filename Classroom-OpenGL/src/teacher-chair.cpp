//teacher chair
#include <GL/glut.h>

void drawChair() {
    // Color settings (Dark grey as seen in image.png)
    glColor3f(0.2f, 0.2f, 0.2f);

    // 1. Seat Base
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.1f, 1.0f);
    glutSolidCube(1.0);
    glPopMatrix();

    // 2. Backrest
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, -0.45f);
    glScalef(1.0f, 1.2f, 0.15f);
    glutSolidCube(1.0);
    glPopMatrix();

    // 3. Central Support Cylinder/Stand
    glPushMatrix();
    glTranslatef(0.0f, -0.4f, 0.0f);
    glScalef(0.15f, 0.8f, 0.15f);
    glutSolidCube(1.0);
    glPopMatrix();

    // 4. Armrests
    // Right Armrest
    glPushMatrix();
    glTranslatef(0.55f, 0.3f, 0.0f);
    glScalef(0.1f, 0.5f, 0.1f); // Vertical support
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.55f, 0.55f, 0.0f);
    glScalef(0.2f, 0.05f, 0.5f); // Top handle
    glutSolidCube(1.0);
    glPopMatrix();

    // Left Armrest
    glPushMatrix();
    glTranslatef(-0.55f, 0.3f, 0.0f);
    glScalef(0.1f, 0.5f, 0.1f); // Vertical support
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.55f, 0.55f, 0.0f);
    glScalef(0.2f, 0.05f, 0.5f); // Top handle
    glutSolidCube(1.0);
    glPopMatrix();

    // 5. Base Legs (Star pattern)
    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glRotatef(i * 72, 0, 1, 0); // 5 legs for stability
        glTranslatef(0.35f, -0.8f, 0.0f);
        glScalef(0.7f, 0.1f, 0.1f);
        glutSolidCube(1.0);
        glPopMatrix();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Position camera to view the chair from an angle
    gluLookAt(3.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(25, 0, 1, 0); // Rotate for better perspective
    drawChair();

    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f); // Light grey background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Office Chair Model - OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}