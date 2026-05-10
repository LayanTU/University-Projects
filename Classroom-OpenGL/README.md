# 📌 Taif University Classroom Recreation | OpenGL 

**A 2D/3D Computer Graphics project recreating a classroom landmark from Taif University using C++ and OpenGL.**

This project was developed to demonstrate solid OpenGL fundamentals, including drawing primitives, transformations, transparency blending and interactive user inputs. The scene integrates both realistic and creative stylized elements, featuring dynamic lighting, animated 2D character and 3D depth testing.

---

## 💡 Key Features & Technical Highlights

* **State Machine Management:** Seamlessly toggles `GL_TEXTURE_2D`, `GL_BLEND`, and `GL_DEPTH_TEST` to ensure 2D transparent character and 3D solid objects render correctly in the same scene without color bleeding.
* **Dynamic Lighting System:** Uses an alpha-blended `GL_QUADS` overlay (`glColor4f`) to simulate the classroom lights turning off and on.
* **Character Animation:** Implements `stb_image.h` to load RGBA `.png` textures, allowing a character to walk and change states across the screen.
* **2D/3D Integration:** Combines 2D orthographic projections (`gluOrtho2D`) for the room layout with 3D perspective projections (`gluPerspective`) for specific furniture elements.

---

## ✅ Interactive Controls

| Input | Action |
| :--- | :--- |
| **`Left Mouse Click`** | Toggle room lighting (Day/Night mode) |
| **`B/b`** | Toggle whiteboard scribble/notes |
| **`R/r`** | Toggle teacher character animation state |
| **`E/e`** | Exit the application |

---

## 🛠️ My Contributions

As part of the group, my specific responsibilities included:

**1. Object Development (The Doors):**
* Coded the classroom doors utilizing `GL_QUADS` for the framing and `GL_LINES` with `glLineWidth()` for the handle hardware.
* Applied precise RGB color mapping using `glColor3ub()`.
* Utilized matrix transformations (`glPushMatrix`, `glTranslatef`, `glPopMatrix`) to efficiently mirror and position the doors on opposite walls.

**2. Scene Assembly & Integration:**
* Acted as the lead integrator to combine 6+ individual `.cpp` modules into a single, cohesive `main.cpp` environment.
* Utilized AI-assisted debugging to calculate proportionate scaling (`glScalef`) for components coded at different original resolutions.
* Debugged complex OpenGL state leaks (ex., preventing the 3D chair's color matrix from tinting the 2D teacher Character).

---

## 📂 Repository Structure

This repository contains the complete development history, including the individual draft codes and the final assembled project.

```text
Classroom-OpenGL/
├── .vscode/                   # VS Code configuration (tasks.json, launch.json)
├── include/                   # Header files
│   ├── GL/                    # freeglut.h, glut.h
│   └── stb_image.h            # Header-only library for PNG texture loading
├── lib/                       # Static libraries
│   └── libfreeglut.a          # MinGW GCC compiled GLUT library
├── individual_codes/          # ⚠️ Raw individual contributions (Drafts)
│   ├── ceiling.cpp
│   ├── chairs-and-floors.cpp
│   ├── door.cpp               # My original door module
│   ├── table.cpp
│   ├── teacher-chair.cpp
│   └── whiteboard.cpp
├── src/                       # Final integrated source code
│   └── main.cpp               # The master scene and rendering loop
├── s1.png, s2.png, s3.png     # Character Character textures
├── freeglut.dll               # Required runtime DLL
└── README.md                  # Project documentation

---

## ⚙️ Build & Run Instructions

### Prerequisites
* **Windows OS**
* **MinGW/GCC Compiler** installed and added to your System PATH
* **Visual Studio Code** with the C/C++ extension

### Terminal Setup

**1. Clone the repository:**
```bash
git clone [https://github.com/YourUsername/Classroom-OpenGL.git](https://github.com/YourUsername/Classroom-OpenGL.git)
cd Classroom-OpenGL

**2. Build and Run (VS Code):**
* Open the folder in VS Code.
* Open `src/main.cpp`.
* Press `Ctrl` + `Shift` + `B` to trigger the build task (uses `tasks.json` to link the `lib` and `include` folders).
* Run the generated executable.

> ⚠️ **Note:** Ensure `freeglut.dll` and the `.png` image files remain in the root directory relative to the compiled executable, or the program will fail to launch or load textures.