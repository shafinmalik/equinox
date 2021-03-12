#include "window.h"

namespace equinox
{
    namespace graphics
    {
        Window::Window(const char *name, int width, int height)
        {
            m_name = name;
            m_width = width;
            m_height = height;
            Init();
        }
        
        Window::~Window()
        {
            glfwTerminate();
        }

        // Private Methods
        void Window::Init()
        {
            if (!glfwInit())
                {
                    std::cout << "bad" << std::endl;
                } else
                {
                    std::cout << "ok" << std::endl;
                }

            m_display = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
            if (!m_display)
            {
                glfwTerminate();
                std::cout << "Failed to create glfw window!" << std::endl;
            }
            glfwMakeContextCurrent(m_display);
        }

        // Public Methods
        bool Window::Closed() const
        {
            glfwWindowShouldClose(m_display);
        }
        
        void Window::Update() const
        {
            glfwSwapBuffers(m_display);
            glfwPollEvents();
        }
    } // namespace graphics
    
} // namespace equin
