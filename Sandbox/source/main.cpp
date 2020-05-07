#include <iostream>
#include <CoreRenderer.h>

int main()
{
	CoreRenderer rendering_instance;
	rendering_instance.InitializeResource();
	rendering_instance.RenderLoop();

	return 0;
}