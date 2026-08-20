#include "core.h"

void App::init()
{
	glfwSetErrorCallback([](int error, const char* description)
		{
			std::cout << "GLFW Error " << error << ": " << description << '\n';
		});
	glfwInit();

	m_Window = glfwCreateWindow(width, height, "Diffusion", nullptr, nullptr);
	if (!m_Window)
	{
		throw std::exception("Window = NULL");
	}
	
	glfwMakeContextCurrent(m_Window);

	gladLoadGL();

	shader_create(shader, "inc/opengl/shaders/default.vert", "inc/opengl/shaders/default.frag");

	grid.init(20,20);
	grid_renderer.init(grid);
}

void App::run()
{
	float pt = glfwGetTime();
	while (!glfwWindowShouldClose(m_Window))
	{
		float ct = glfwGetTime();
		float dt = ct - pt;

		pt = ct;
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		shader_use(shader);
		grid.diffuse(dt);
		grid_renderer.update();
		grid_renderer.draw();

		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
}

void App::clean()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}