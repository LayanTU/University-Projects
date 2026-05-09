//chairs and floors

#include <GL/glut.h>

void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void drawChair2D(float x, float y, float scale)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glColor3f(0.05f, 0.05f, 0.05f);
    quad(-0.34f, -0.28f, 0.34f, -0.28f, 0.34f, -0.20f, -0.34f, -0.20f);

    glColor3f(0.45f, 0.45f, 0.45f);
    quad(-0.23f, -0.58f, -0.17f, -0.58f, -0.14f, -0.28f, -0.20f, -0.28f);
    quad(0.17f, -0.58f, 0.23f, -0.58f, 0.20f, -0.28f, 0.14f, -0.28f);

    glColor3f(0.02f, 0.02f, 0.02f);
    quad(-0.38f, -0.10f, -0.30f, -0.10f, -0.30f, 0.42f, -0.38f, 0.42f);
    quad(0.30f, -0.10f, 0.38f, -0.10f, 0.38f, 0.42f, 0.30f, 0.42f);

    glColor3f(0.00f, 0.50f, 0.46f);
    quad(-0.34f, 0.02f, 0.34f, 0.02f, 0.28f, 0.50f, -0.28f, 0.50f);

    glColor3f(0.00f, 0.36f, 0.34f);
    quad(-0.32f, -0.18f, 0.32f, -0.18f, 0.25f, 0.04f, -0.25f, 0.04f);

    glColor3f(0.00f, 0.28f, 0.27f);
    quad(-0.32f, -0.02f, 0.32f, -0.02f, 0.32f, 0.07f, -0.32f, 0.07f);

    glColor3f(0.02f, 0.02f, 0.02f);
    quad(0.37f, -0.08f, 0.46f, -0.08f, 0.46f, 0.22f, 0.37f, 0.22f);
    quad(0.42f, 0.10f, 0.75f, 0.10f, 0.70f, 0.25f, 0.42f, 0.25f);

    glColor3f(0.12f, 0.12f, 0.12f);
    quad(0.47f, -0.22f, 0.52f, -0.22f, 0.52f, 0.10f, 0.47f, 0.10f);

    glPopMatrix();
}
void drawChairs()
{
    drawChair2D(-3.0f, -2.8f, 1.25f);
    drawChair2D(-1.5f, -2.8f, 1.25f);
    drawChair2D(0.0f, -2.8f, 1.25f);
    drawChair2D(1.5f, -2.8f, 1.25f);
    drawChair2D(3.0f, -2.8f, 1.25f);

    drawChair2D(-2.2f, -1.4f, 0.95f);
    drawChair2D(-0.7f, -1.4f, 0.95f);
    drawChair2D(0.8f, -1.4f, 0.95f);
    drawChair2D(2.3f, -1.4f, 0.95f);

    drawChair2D(-1.5f, -0.2f, 0.70f);
    drawChair2D(0.0f, -0.2f, 0.70f);
    drawChair2D(1.5f, -0.2f, 0.70f);
}

void drawFloor()
{
    glColor3f(0.9608f, 0.9294f, 0.8784f);
    glBegin(GL_POLYGON);
    glVertex2f(-2.96f, 1.47f);
    glVertex2f(2.91f, 1.47f);
    glVertex2f(4.96f, -0.99f);
    glVertex2f(4.96f, -3.66f);
    glVertex2f(-5.00f, -3.66f);
    glVertex2f(-5.00f, -0.99f);
    glEnd();

    glColor3f(0.7608f, 0.6902f, 0.6118f);
    glLineWidth(1.0f);

    glBegin(GL_LINES);

    glVertex2f(-2.96f, 1.47f); glVertex2f(2.91f, 1.47f);
    glVertex2f(-2.96f, 1.47f); glVertex2f(-5.00f, -0.99f);
    glVertex2f(2.91f, 1.47f); glVertex2f(4.96f, -0.99f);

    glVertex2f(-3.15f, 1.25f); glVertex2f(3.11f, 1.25f);

    glVertex2f(-2.37f, 1.47f); glVertex2f(-2.53f, 1.25f);
    glVertex2f(-1.79f, 1.47f); glVertex2f(-1.98f, 1.25f);
    glVertex2f(-1.20f, 1.47f); glVertex2f(-1.27f, 1.25f);
    glVertex2f(-0.62f, 1.47f); glVertex2f(-0.65f, 1.25f);
    glVertex2f(-0.02f, 1.47f); glVertex2f(-0.02f, 1.25f);
    glVertex2f(0.57f, 1.47f); glVertex2f(0.62f, 1.25f);
    glVertex2f(1.16f, 1.47f); glVertex2f(1.23f, 1.25f);
    glVertex2f(1.75f, 1.47f); glVertex2f(1.93f, 1.25f);
    glVertex2f(2.33f, 1.47f); glVertex2f(2.49f, 1.25f);

    glVertex2f(-3.37f, 1.00f); glVertex2f(-2.10f, 1.00f);
    glVertex2f(2.05f, 1.00f); glVertex2f(3.32f, 1.00f);

    glVertex2f(-3.60f, 0.73f); glVertex2f(-2.25f, 0.73f);
    glVertex2f(2.20f, 0.73f); glVertex2f(3.55f, 0.73f);

    glVertex2f(-3.90f, 0.40f); glVertex2f(-2.42f, 0.40f);
    glVertex2f(-3.90f, 0.39f); glVertex2f(-2.42f, 0.39f);

    glVertex2f(2.37f, 0.40f); glVertex2f(3.85f, 0.40f);
    glVertex2f(2.37f, 0.39f); glVertex2f(3.85f, 0.39f);

    glVertex2f(-2.37f, 1.47f); glVertex2f(-5.00f, -2.30f);
    glVertex2f(-1.79f, 1.47f); glVertex2f(-2.48f, 0.34f);

    glVertex2f(2.32f, 1.47f); glVertex2f(4.96f, -2.32f);
    glVertex2f(1.75f, 1.47f); glVertex2f(2.43f, 0.34f);

    glVertex2f(-2.48f, 0.34f); glVertex2f(2.43f, 0.34f);
    glVertex2f(-2.48f, 0.33f); glVertex2f(2.43f, 0.33f);
    glVertex2f(-2.48f, 0.34f); glVertex2f(-2.44f, 0.20f);
    glVertex2f(2.43f, 0.34f); glVertex2f(2.39f, 0.20f);


    glVertex2f(-4.23f, 0.01f); glVertex2f(4.18f, 0.01f);
    glVertex2f(-4.63f, -0.44f); glVertex2f(4.58f, -0.44f);
    glVertex2f(-5.00f, -0.99f); glVertex2f(4.96f, -0.99f);
    glVertex2f(-5.00f, -1.67f); glVertex2f(4.96f, -1.67f);
    glVertex2f(-5.00f, -2.53f); glVertex2f(4.96f, -2.53f);

    glVertex2f(-5.00f, -3.65f); glVertex2f(4.96f, -3.65f);
    glVertex2f(-5.00f, -3.66f); glVertex2f(4.96f, -3.66f);

    glVertex2f(-2.44f, 0.20f); glVertex2f(-4.45f, -3.66f);
    glVertex2f(-1.64f, 0.20f); glVertex2f(-2.98f, -3.66f);
    glVertex2f(-0.83f, 0.20f); glVertex2f(-1.50f, -3.66f);
    glVertex2f(-0.02f, 0.20f); glVertex2f(-0.02f, -3.66f);
    glVertex2f(0.78f, 0.20f); glVertex2f(1.46f, -3.66f);
    glVertex2f(1.59f, 0.20f); glVertex2f(2.93f, -3.66f);
    glVertex2f(2.39f, 0.20f); glVertex2f(4.40f, -3.66f);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawFloor();
    drawChairs();

    glFlush();
}

void init()
{
    glClearColor(0.98f, 0.96f, 0.94f, 1.0f);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Taif University - Matching Platform");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}