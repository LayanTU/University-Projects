//whiteboard
#include <GL/glut.h>
#include <stdlib.h>
 
// متغير حالة للنظام التفاعلي يحدد ما إذا كانت السبورة تحتوي على كتابة أم لا
bool showScribble = false;
 
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
 
// دالة العرض الأساسية
void display() {
   // مسح الشاشة بلون خلفية القاعة (رمادي فاتح جداً)
   glClearColor(0.95f, 0.95f, 0.95f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);
 
   drawWhiteboard();
 
   glFlush(); // التأكد من عرض الرسومات
}
 
// دالة التفاعل عبر لوحة المفاتيح
void keyboard(unsigned char key, int x, int y) {
   // عند الضغط على مفتاحb' ' أو ' B 'يتم تبديل حالة السبورة
   if (key == 'b' || key == 'B') {
       showScribble = !showScribble;
       glutPostRedisplay(); // إعادة الرسم لتحديث المشهد
   }
   // مفتاح  'e' للخروج من البرنامج
   if (key == 'e' || key == 'E') {
       exit(0);
   }
}
 
// دالة التهيئة
void init() {
   // ضبط حدود الرؤية في نظام الإحداثيات العالمي
   gluOrtho2D(-20, 20, -20, 20);
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(600, 600);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Taif University Project - Whiteboard Module");
 
   init();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard); // تسجيل دالة التفاعل
 
   glutMainLoop();
   return 0;
}