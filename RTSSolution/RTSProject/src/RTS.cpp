//
// Created by hendrik on 15.10.19.
//

#include "RTS.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

RTS::RTS() {
}
RTS::~RTS() {
}

int RTS::start(int argc, char** argv) {
	
		GLFWwindow* window;

		/* Initialize the library */
		if (!glfwInit())
			return -1;


		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -2;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK) {
			return -3;
		}

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

