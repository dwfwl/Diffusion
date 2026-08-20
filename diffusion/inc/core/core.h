#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Shader.h>

#include <rendering/grid_renderer.h>
#include <simulation/grid/grid.h>
class App
{
public:
	App(App&& other) = delete;
	App()
	{
		init();
		run();
	}
	~App()
	{
		clean();
	}

private:
	void init();
	void run();
	void clean();

	// win info
	GLFWwindow* m_Window;
	int width = 1000;
	int height = 1000;

	// opengl context
	std::unique_ptr<Shader> shader = std::make_unique<Shader>();

	Grid grid;
	GridRenderer grid_renderer;
};