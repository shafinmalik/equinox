#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

namespace equinox 
{
    namespace graphics {
        class Window
        {
        private:
            int m_width, m_height;
            bool m_closed;

            const char *m_name;
            GLFWwindow *m_display;

        public:
            Window(const char *name, int width, int height);
            ~Window();

            bool Closed() const;
            void Update() const;

        private:
            void Init();
        };
    }
}