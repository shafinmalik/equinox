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
            void Clear() const;

            void Update();

            inline int getWidth() const { return m_width; };
            inline int getHeight() const { return m_height; };

        private:
            bool Init();
        };
    }
}