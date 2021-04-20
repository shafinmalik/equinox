#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace equinox 
{
    namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

        class Window
        {
        friend struct GLFWwindow;
        private:
            int m_width, m_height;
            bool m_closed;

            const char *m_name;
            GLFWwindow *m_display;

            static bool m_keys[MAX_KEYS];
            static bool m_buttons[MAX_BUTTONS];
            static double m_xmouse, m_ymouse;

        public:
            Window(const char *name, int width, int height);
            ~Window();

            bool Closed() const;
            void Clear() const;

            void Update();

            inline int getWidth() const { return m_width; };
            inline int getHeight() const { return m_height; };

            static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
            static void mbutton_callback(GLFWwindow* window, int button, int action, int mods);
            
            static bool isKeyDown(unsigned int keycode);
            static bool isMButtonDown(unsigned int button);

            // Debugging Only
            void printButtons()
            {
                for (int i = 0; i < MAX_BUTTONS; i++) 
                std::cout << m_buttons[i];
                std::cout << "" << std::endl;
            }

        private:
            bool Init();
        };
    }
}