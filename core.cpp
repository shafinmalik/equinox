// OpenGL Imports
//#include <GLFW/glfw3.h>

// Engine Imports
#include "graphics/window.h"

// Utility Imports
#include "utilities/init_ui.h"

// Other Imports
#include <iostream>
#include "math/linmath.h"

// See references for "linmath.h" source
// Need to refactor directory structure
// current g++ command:
// g++ core.cpp graphics/window.cpp utilities/init_ui.cpp -lGLEW -lglfw -lGLU -lGL example

using namespace equinox;
using namespace graphics;

int main() {
    int make_width, make_height;
    SetNewWindowHeight(make_width, make_height);
    Window window("Test!", make_width, make_height);
    //Window window("Test!", 960, 540);
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

    std::cout << glGetString(GL_VERSION) << std::endl;

    while (!window.Closed())
    {
        // std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
        window.Clear();

        {
            // Use this space to test basic renders
            glBegin(GL_TRIANGLES);
            glVertex2d(-0.5f, -0.5f);
            glVertex2d(0.0f, 0.5f);
            glVertex2d(0.5f, -0.5f);
            glEnd();
        }

        window.Update();
    }
    

    // Can replace with system("PAUSE") on Windows
    // Remove this line before final build
    system("read -p 'Press Enter to continue...' var");
    return 0;
}
