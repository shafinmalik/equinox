#include "window.h"

namespace equinox
{
    namespace graphics
    {
        bool Window::m_keys[MAX_KEYS];
        bool Window::m_buttons[MAX_BUTTONS];
        double Window::m_xmouse;
        double Window::m_ymouse;

        void window_resize_call(GLFWwindow *window, int width, int height);

        Window::Window(const char *name, int width, int height)
        {
            m_name = name;
            m_width = width;
            m_height = height;

            if (!Init())
            {
                glfwTerminate();
            }

            for (int i = 0; i < MAX_KEYS; i++)
            {
                m_keys[i] = false;
            }

            for (int i = 0; i < MAX_BUTTONS; i++)
            {
                m_buttons[i] = false;
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
            glfwSetWindowUserPointer(m_display, this);
            glfwSetWindowSizeCallback(m_display, window_resize_call);
            glfwSetKeyCallback(m_display, key_callback);
            glfwSetMouseButtonCallback(m_display, mbutton_callback);

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

        bool Window::isKeyDown(unsigned int keycode)
        {
            if (keycode >= MAX_KEYS)
            {
                // Log an error once a logging system is implemented. 
                return false;
            }
            return m_keys[keycode];
        }

        bool Window::isMButtonDown(unsigned int button)
        {
            if (button >= MAX_BUTTONS)
            {
                return false;
            }
            return m_buttons[button];
        }

        void Window::Clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        // may need to go above Init()
        void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            Window* winmgr = (Window*) glfwGetWindowUserPointer(window);
            
            // set keys[key] to true/false of if key has been released
            winmgr->m_keys[key] = (action != GLFW_RELEASE);
        }

        void Window::mbutton_callback(GLFWwindow* window, int button, int action, int mods)
        {     
            Window* winmgr = (Window*) glfwGetWindowUserPointer(window);
            
            winmgr->m_buttons[button] = (action != GLFW_RELEASE);
        }


        // C naming concention for indepenent functions
        void window_resize_call(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        
    } // namespace graphics
    
} // namespace equinox