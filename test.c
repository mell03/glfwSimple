// test.c
#include <GLFW/glfw3.h>
#include <cstdio>

int main(void)
{
    GLFWwindow* window;
    GLFWmonitor** monitors = NULL;
    int monitorCount = 0;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    monitors = glfwGetMonitors(&monitorCount);
    printf("Num mon : %d", monitorCount);    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        printf("could not create window");
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
