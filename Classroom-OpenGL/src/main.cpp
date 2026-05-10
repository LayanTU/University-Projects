#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // تأكدي أن هذا الملف موجود في مجلد المشروع

// معرفات التكستشر للصور الثلاث
GLuint texStand, texWalk, texBook;
float x_pos = -0.5f;    // نقطة البداية (يسار الشاشة)
int state = 0;          // 0: واقفة (s1)، 1: تمشي (s2)، 2: وقفت بالوسط (s1)، 3: ماسكة كتاب (s3)

// متغير حالة للنظام التفاعلي يحدد ما إذا كانت السبورة تحتوي على كتابة أم لا
bool showScribble = false;

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
    glLineWidth(6);
    
    glBegin(GL_LINES);
    //Vertical part - T head
    glVertex2i(3, 0); glVertex2i(3, -2);
    
    //Horizontal part - T base 
    glVertex2i(1, -1); glVertex2i(3, -1);
    glEnd();
}
 
// دالة رسم السبورة
void drawWhiteboard() {
   glColor3f(1.0f, 1.0f, 1.0f);
   glBegin(GL_QUADS);
       glVertex2i(-12, -4);
       glVertex2i( 12, -4);
       glVertex2i( 12,  8);
       glVertex2i(-12,  8);
   glEnd();
 
   // 2. رسم الإطار (The Frame)
   glLineWidth(5.0); // سماكة الخط للإطار
   glColor3f(0.3f, 0.3f, 0.3f); // رمادي غامق للإطار
   glBegin(GL_LINE_LOOP);
       glVertex2i(-12, -4);
       glVertex2i( 12, -4);
       glVertex2i( 12,  8);
       glVertex2i(-12,  8);
   glEnd();
 
   // 3. رسم حامل الأقلام في الأسفل (Creative Detail)
   glColor3f(0.5f, 0.5f, 0.5f);
   glBegin(GL_QUADS);
       glVertex2i(-5, -5);
       glVertex2i( 5, -5);
       glVertex2i( 5, -4);
       glVertex2i(-5, -4);
   glEnd();
 
   // 4. تنفيذ التفاعل (Interaction Logic)
   if (showScribble) {
       glColor3f(0.0f, 0.2f, 0.8f); // لون حبر أزرق
       glLineWidth(3.0);
       glBegin(GL_LINES);
           // رسم خطوط بسيطة تمثل كتابة أو رسماً توضيحياً
           glVertex2i(-8, 4);  glVertex2i(8, 4);
           glVertex2i(-8, 1);  glVertex2i(4, 1);
           glVertex2i(-8, -2); glVertex2i(0, -2);
       glEnd();
   }
}

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

void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1); glVertex2f(x2, y2);
    glVertex2f(x3, y3); glVertex2f(x4, y4);
    glEnd();
}

void drawChair2D(float x, float y, float scale) {
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

void drawChairs() {
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

void drawFloor() {
    glColor3f(0.9608f, 0.9294f, 0.8784f);
    glBegin(GL_POLYGON);
    glVertex2f(-2.96f, 1.47f); glVertex2f(2.91f, 1.47f);
    glVertex2f(4.96f, -0.99f); glVertex2f(4.96f, -3.66f);
    glVertex2f(-5.00f, -3.66f); glVertex2f(-5.00f, -0.99f);
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

    glColor3ub(115, 60, 35);
    glBegin(GL_QUADS);
    glVertex2i(5, -14); glVertex2i(4, -13);
    glVertex2i(-1, -13); glVertex2i(-2, -14);
    glEnd();

    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
    glVertex2i(-2, -14); glVertex2i(-6, -11);
    glVertex2i(-6, -12); glVertex2i(-2, -15);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2i(5, -14); glVertex2i(-2, -14);
    glVertex2i(-2, -15); glVertex2i(5, -15);
    glEnd();

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2i(2, 0); glVertex2i(-6, 0);
    glVertex2i(-6, 5); glVertex2i(0, 7);
    glVertex2i(2, 7);
    glEnd();

    glColor3ub(115, 60, 35);
    glBegin(GL_QUADS);
    glVertex2i(2, 7); glVertex2i(2, 5);
    glVertex2i(3, 6); glVertex2i(5, 6);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2i(-2, -2); glVertex2i(-6, 0);
    glVertex2i(-6, 2); glVertex2i(-2, 0);
    glEnd();

    glColor3ub(115, 60, 35);
    glBegin(GL_TRIANGLES);
    glVertex2i(-2, 0); glVertex2i(-6, 2);
    glVertex2i(-2, 3);
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
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(2.0, 0.3); glVertex2f(2.0, 1.3);
    glVertex2f(1.2, 1.4); glVertex2f(2.8, 1.4);
    glEnd();

    glColor3ub(218, 165, 32);
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.5, 1.0); glVertex2f(2.5, 0.3);
    glVertex2f(3.6, 0.3); glVertex2f(3.6, 1.0);
    glEnd();
}

// دالة موحدة لتحميل الصور (تدعم الشفافية)
GLuint loadTexture(const char* path) {
    GLuint id;
    int w, h, c;
    stbi_set_flip_vertically_on_load(true);
    // نطلب تحميل 4 قنوات (RGBA) لضمان تحميل قناة الشفافية
    unsigned char* data = stbi_load(path, &w, &h, &c, 4);
    if (data) {
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);

        // إعدادات التكستشر لضمان ظهور البكسلات حادة (Pixel Art style)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // تحميل البيانات بصيغة GL_RGBA للشفافية
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
        return id;
    }
    std::cout << "FAILED to load texture at: " << path << std::endl;
    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
    //floor and students' chairs - change coordinates and disable depth test 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.5, 5.5, -3.0, 4.0); 
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST); 
    
    glTranslatef(0.0f, -0.8f, 0.0f);
    drawFloor();
    drawChairs();

    //ceiling -change position and coordinates
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -25.0, 25.0); 
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(0.0f, 2.0f, 0.0f); 
    drawCeiling();
    glPopMatrix();

    //smaller doors 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-75.0, 75.0, -37.5, 37.5);    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //left door
    glPushMatrix(); 
    glTranslatef(-35, 15, 0);
    drawDoor();
    glPopMatrix();

    //right door
    glPushMatrix();
    glTranslatef(35, 15, 0);
    drawDoor();
    glPopMatrix();

    //whiteboard - change coordinates again
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-60.0, 60.0, -30.0, 30.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 9.0, 0.0);
    drawWhiteboard();

    //podium - change coordinates again
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-60.0, 60.0, -30.0, 30.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(18, 3, 0);
    glScalef(0.6, 0.6, 0.6);
    DrawPodium();

    //3D chair - change coordinates and enable depth test
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 2.0, 1.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    // Position camera to view the chair rom an angle
    gluLookAt(0.0, 3.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glTranslatef(1.2, -1.4, -3.0); 
    glRotatef(15, 0, 1, 0); 
    glScalef(0.6, 0.6, 0.6);
    drawChair();

    //teacher - change coordinates and disable depth test
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST); 
    
    // تفعيل التكستشر
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3f(1.0f, 1.0f, 1.0f); //change color so it's not affected by the chair's color

    // اختيار الصورة بناءً على الحالة
    if (state == 0 || state == 2) glBindTexture(GL_TEXTURE_2D, texStand);
    else if (state == 1)          glBindTexture(GL_TEXTURE_2D, texWalk);
    else if (state == 3)          glBindTexture(GL_TEXTURE_2D, texBook);

    glPushMatrix();
    glTranslatef(x_pos, 0.02f, 0.0f); // موقع الشخصية عمودياً
    glScalef(0.75f, 0.75f, 1.0f);

    // رسم المربع بالأبعاد الأصلية لصورك (160x230)
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.2f, -0.35f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.2f, -0.35f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.2f, 0.35f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.2f, 0.35f);
    glEnd();
    glPopMatrix();
    
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_DEPTH_TEST);
   
    // Dark transparent layer
    if (!lightOn) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);

    glBegin(GL_QUADS);
        glVertex2f(-1, -1);
        glVertex2f( 1, -1);
        glVertex2f( 1,  1);
        glVertex2f(-1,  1);
    glEnd();

    glDisable(GL_BLEND);
    }

    glutSwapBuffers(); //instead of glFlush();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.96f, 0.93f, 0.88f, 1.0f); //beige

    // تفعيل الشفافية (البلندنج)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // --- هنا التعديل: تحميل الصور بأسماء الملفات مباشرة ---
    texStand = loadTexture("s1.png");
    texWalk = loadTexture("s2.png");
    texBook = loadTexture("s3.png");
}

//projection is in display(); 
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

// دالة التفاعل عبر لوحة المفاتيح
void keyboard(unsigned char key, int x, int y) {
   // عند الضغط على مفتاحb' ' أو ' B 'يتم تبديل حالة السبورة
   if (key == 'b' || key == 'B') {
       showScribble = !showScribble;
       glutPostRedisplay(); // إعادة الرسم لتحديث المشهد
   }
    // تبديل الحالات عند ضغط زر R
    if (key == 'r' || key == 'R') {
        if (state == 0) state = 1;      // واقفة -> تمشي
        else if (state == 2) state = 3; // وقفت بالوسط -> تمسك الكتاب
    }
   // مفتاح  'e' للخروج من البرنامج
   if (key == 'e' || key == 'E') {
       exit(0);
   }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        lightOn = !lightOn;
        glutPostRedisplay();
    }
}

void update(int value) {
    if (state == 1) { // حالة المشي للوسط
        x_pos += 0.005f; // سرعة الحركة
        if (x_pos >= 0.0f) { // الوصول للوسط
            x_pos = 0.0f;
            state = 2; // قف واظهر s1 مرة أخرى
        }
    }
    glutPostRedisplay(); // إعادة الرسم
    glutTimerFunc(16, update, 0); // تكرار الاستدعاء
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);    
    glutInitWindowSize(1000, 500); 
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Classroom");
    
    init();
    glutDisplayFunc(display);

    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard); // تسجيل دالة لوحة المفاتيح للتفاعل
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}