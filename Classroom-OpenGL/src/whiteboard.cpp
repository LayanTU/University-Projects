//white board
#include <GL/glut.h>
#include <stdlib.h>

// متغير عام للتحكم في حالة السبورة (تفاعلي)
bool isBoardWritten = false;

// دالة رسم السبورة البيضاء (جزئيتك الخاصة المعتمدة على المحاضرات)
void drawMyWhiteboard() {
    // 1. رسم سطح السبورة (Whiteboard Surface)
    glColor3ub(255, 255, 255); // اللون الأبيض باستخدام ub كما ورد في المحاضرة 2
    glBegin(GL_QUADS); 
        glVertex2i(-12, -4); 
        glVertex2i( 12, -4);
        glVertex2i( 12,  6);
        glVertex2i(-12,  6);
    glEnd();

    // 2. رسم الإطار الخارجي (The Frame)
    glLineWidth(4.0); // تحديد سماكة الخط
    glColor3f(0.4f, 0.4f, 0.4f); // لون رمادي للإطار
    glBegin(GL_LINE_LOOP); // حلقة مغلقة لتمثيل الإطار
        glVertex2i(-12, -4);
        glVertex2i( 12, -4);
        glVertex2i( 12,  6);
        glVertex2i(-12,  6);
    glEnd();

    // 3. إضافة تفاصيل إبداعية (سلك التحكم العلوي من الصورة المرفقة)
    glLineWidth(2.0);
    glBegin(GL_LINES); 
        glVertex2i(0, 6);
        glVertex2i(0, 12);
    glEnd();

    // 4. حامل الأقلام في الأسفل
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2i(-4, -5);
        glVertex2i( 4, -5);
        glVertex2i( 4, -4);
        glVertex2i(-4, -4);
    glEnd();

    // 5. النظام التفاعلي (Interactive System - المهمة 4)
    // رسم خربشة زرقاء على السبورة عند الضغط على مفتاح التفاعل
    if (isBoardWritten) {
        glColor3f(0.0f, 0.0f, 1.0f); // لون أزرق للكتابة
        glLineWidth(3.0);
        glBegin(GL_LINES); 
            glVertex2i(-8, 2);  glVertex2i(8, 2);
            glVertex2i(-8, -1); glVertex2i(2, -1);
        glEnd();
    }
}

// دالة العرض الأساسية
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // مسح الشاشة
    drawMyWhiteboard();
    glFlush(); // إرسال الرسم للشاشة
}

// دالة التفاعل مع لوحة المفاتيح
void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
    switch (theKey) {
        case 'b':
        case 'B':
            isBoardWritten = !isBoardWritten; // تبديل حالة الكتابة (تفاعل)
            glutPostRedisplay(); // إعادة الرسم لتحديث المشهد فوراً
            break;
        case 'e':
        case 'E':
            exit(0); // إنهاء البرنامج
            break;
    }
}

// دالة التهيئة الأولية (تطابق معايير المحاضرة 2 والمحاضرة 5)
void init() {
    glClearColor(0.9f, 0.9f, 0.9f, 0.0f); // لون خلفية النافذة (رمادي فاتح)
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0); // ضبط حدود الرؤية وعرض الشاشة ثنائية الأبعاد
}

//الدالة الرئيسية
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(600, 600); // حجم نافذة العرض
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Taif University Landmark - Whiteboard Module"); 
    
    init(); // استدعاء دالة التهيئة
    glutDisplayFunc(display); // تسجيل دالة الرسم
    glutKeyboardFunc(myKeyboard); // تسجيل دالة لوحة المفاتيح للتفاعل
    
    glutMainLoop(); // الدخول في حلقة الانتظار اللانهائية لتشغيل الواجهة
    return 0;
}