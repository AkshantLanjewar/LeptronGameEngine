#pragma once
#ifndef BUFFEROBJECTS_H
#define BUFFEROBJECTS_H

#include <vector>

class BufferObjects
{
public:
	BufferObjects();
	~BufferObjects();

private:
	unsigned int VBO, VAO, EBO;
	
	std::vector<float> verticies;
	std::vector<int> indicies;
};

#endif