// OpenGL Imports
//#include <GLFW/glfw3.h>

// Engine Imports
#include "graphics/window.h"

// Math imports
// (Todo)

// Utility Imports
#include "utilities/init_ui.h"

// Other Imports
#include <iostream>
#include "external/linmath.h"

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

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    while (!window.Closed())
    {
        double x, y;
        window.getMousePosition(x, y);
        std::cout << x << ", " << y << std::endl;
#if 1
        // Test inputs here
        {
            window.Clear();
            //window.printButtons();
            if (window.isKeyDown(GLFW_KEY_A))
            {
                std::cout << "Button A" << std::endl;
            }

            if (window.isKeyDown(GLFW_KEY_D))
            {
                std::cout << "Button D" << std::endl;
            }

            if (window.isMButtonDown(GLFW_MOUSE_BUTTON_LEFT))
            {
                std::cout << "Mouse Click L" << std::endl;
            }

            if (window.isMButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
            {
                std::cout << "Mouse Click R" << std::endl;
            }
        }
#endif

        {
#if 1
            // Use this space to test basic renders
            glBegin(GL_TRIANGLES);
            glVertex2d(-0.5f, -0.5f);
            glVertex2d(0.0f, 0.5f);
            glVertex2d(0.5f, -0.5f);
            glEnd();
#else
            glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
        }

        window.Update();
    }
    

    // Can replace with system("PAUSE") on Windows
    // Remove this line before final build
    system("read -p 'Press Enter to continue...' var");
    return 0;
}
