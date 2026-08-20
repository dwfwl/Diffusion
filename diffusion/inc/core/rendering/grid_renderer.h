#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../simulation/grid/grid.h"

#include <VAO.h>
#include <VBO.h>
#include <EBO.h>

#include <memory>
#include <array>

class GridRenderer
{
public:
	GridRenderer() = default;

	void init(Grid& ins);

	void initGrid(float cs);
	void update();
	void draw();
private:
	Grid* grid;
	Geometry geo;

	float cellSize = 0.05f;

	std::unique_ptr<VAO> vao = std::make_unique<VAO>();
	std::unique_ptr<VBO> vbo = std::make_unique<VBO>();
	std::unique_ptr<EBO> ebo = std::make_unique<EBO>();
};