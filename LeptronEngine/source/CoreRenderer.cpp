#include "../public/CoreRenderer.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

CoreRenderer::CoreRenderer()
{
	std::cout << "[Leptron] : Starting a Rendering Instance";
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifndef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

CoreRenderer::~CoreRenderer()
{

}

void CoreRenderer::CreateWindow()
{
	window = glfwCreateWindow(width, height, "Rendering Instance", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create a GLFW window" << std::endl;
		glfwTerminate();
		throw std::exception("GLFW Window Failed");
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::exception("Failed to load GLAD");
}

void CoreRenderer::InitializeResource()
{
	CreateWindow();
}

void CoreRenderer::RenderLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	Cleanup();
}

void CoreRenderer::Cleanup()
{
	glfwTerminate();
}

void CoreRenderer::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

//private callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
