#include <GL/glut.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // تأكدي أن هذا الملف موجود في مجلد المشروع

// معرفات التكستشر للصور الثلاث
GLuint texStand, texWalk, texBook;
float x_pos = -0.8f;    // نقطة البداية (يسار الشاشة)
int state = 0;          // 0: واقفة (s1)، 1: تمشي (s2)، 2: وقفت بالوسط (s1)، 3: ماسكة كتاب (s3)

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

void init() {
    // لون الخلفية
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // تفعيل التكستشر
    glEnable(GL_TEXTURE_2D);

    // تفعيل الشفافية (البلندنج)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // --- هنا التعديل: تحميل الصور بأسماء الملفات مباشرة ---
    texStand = loadTexture("s1.png");
    texWalk = loadTexture("s2.png");
    texBook = loadTexture("s3.png");
    // --------------------------------------------------
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // اختيار الصورة بناءً على الحالة
    if (state == 0 || state == 2) glBindTexture(GL_TEXTURE_2D, texStand);
    else if (state == 1)          glBindTexture(GL_TEXTURE_2D, texWalk);
    else if (state == 3)          glBindTexture(GL_TEXTURE_2D, texBook);

    glPushMatrix();
    glTranslatef(x_pos, -0.1f, 0.0f); // موقع الشخصية عمودياً
    glBegin(GL_QUADS);
    // رسم المربع بالأبعاد الأصلية لصورك (160x230)
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.2f, -0.35f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.2f, -0.35f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.2f, 0.35f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.2f, 0.35f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    // تبديل الحالات عند ضغط زر R
    if (key == 'r' || key == 'R') {
        if (state == 0) state = 1;      // واقفة -> تمشي
        else if (state == 2) state = 3; // وقفت بالوسط -> تمسك الكتاب
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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //RGBA مهمة للشفافية
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Computer Graphics Project - Reem");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}