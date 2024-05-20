#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

//using namespace std;

void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
unsigned int SCR_WIDTH = 1280;
unsigned int SCR_HEIGHT = 1024;
// --------

int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // ------------------------------

    // glfw: window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "5SAE0PG102 2024 Lab 1", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
    // ---------------------

    // glad: load OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load OpenGL function pointers!" << std::endl;
        glfwTerminate();
        return -1;
    }
    // -----------------------------------

    // MAIN RENDERING LOOP
    while (!glfwWindowShouldClose(window))
    {
        // handle user input
        processInput(window);
        // -----------------

        // RENDER STUFF
        
        // Reinitialize frame buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // -------------------------
        
        //TODO MORE RENDERING
        // ------------

        // glfw: double buffering and polling IO events (keyboard, mouse, etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
        // --------------------------------------------------------------------
    }
    // ------------------

    // Resource and GLFW cleanup
    // TODO resources
    glfwTerminate();
    // -------------------------

    return 0;
}

//Handle keyboard input events
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

// frame buffer resizing callback
void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
