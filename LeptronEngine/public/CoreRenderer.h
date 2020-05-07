#pragma once
#ifndef CORERENDERER_H
#define CORERENDERER_H

#include <iostream>
#include <GLFW/glfw3.h>
#include <exception>
#include <glad/glad.h>

class CoreRenderer
{
public:
	CoreRenderer();
	~CoreRenderer();

	//Resource Initialization
	void InitializeResource();
	void RenderLoop();

private:
	void CreateWindow();
	void Cleanup();

	void processInput(GLFWwindow* window);

private:
	GLFWwindow* window;

	int width = 1280;
	int height = 720;
};

#endif // !CORERENDERER_H