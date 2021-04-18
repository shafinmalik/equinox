#include "window.h"

namespace equinox
{
    namespace graphics
    {
        void windowResizeCall(GLFWwindow *window, int width, int height);

        Window::Window(const char *name, int width, int height)
        {
            m_name = name;
            m_width = width;
            m_height = height;

            if (!Init())
            {
                glfwTerminate();
            }
        }
        
        Window::~Window()
        {
            glfwTerminate();
        }

        // Private Methods
        bool Window::Init()
        {
            if (!glfwInit())
                {
                    std::cout << "Error: !glfwInit()" << std::endl;
                    return false;
                } else
                {
                    std::cout << "Initialized Successfully." << std::endl;
                }

            m_display = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
            if (!m_display)
            {
                // uncomment for debugging. 
                // glfwTerminate();
                std::cout << "Error: Failed to create glfw window!" << std::endl;
                return false;
            }
            glfwMakeContextCurrent(m_display);
            glfwSetWindowSizeCallback(m_display, windowResizeCall);

            // Attempt to Initialize GLEW
            // This MUST occur after glfwMakeContextCurrent(), otherwise GLEW will automatically fail
            if (glewInit() != GLEW_OK)
            {
                std::cout << "Could not initialize GLEW!" << std::endl;
                return false;
            }
            
            std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

            return true;
        }

        // Public Methods
        bool Window::Closed() const
        {
            return (glfwWindowShouldClose(m_display) == 1);
        }
        
        void Window::Update() 
        {
            glfwPollEvents();
            // glfwGetFramebufferSize(m_display, &m_width, &m_height);
            glfwSwapBuffers(m_display);
        }

        void Window::Clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void windowResizeCall(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }
    } // namespace graphics
    
} // namespace equinox