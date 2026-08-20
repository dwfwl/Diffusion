#include "grid_renderer.h"

void GridRenderer::init(Grid& ins)
{
	grid = &ins;
	initGrid(0.1f);
	vao_create(*vao.get());
	vbo_create(*vbo.get());
	ebo_create(*ebo.get());

	vao_bind(*vao.get());
	vbo_buffer(*vbo.get(), geo.vertices);
	ebo_buffer(*ebo.get(), geo.indices);

	vao_attr(*vao.get(), 0, 3, GL_FLOAT, sizeof(Vertex), offsetof(Vertex, pos));
	vao_attr(*vao.get(), 1, 3, GL_FLOAT, sizeof(Vertex), offsetof(Vertex, col));
}

void GridRenderer::initGrid(float cs)
{
	cellSize = cs;
	int count = 0;
	for (int y = 0; y < grid->height(); y++)
	{
		for (int x = 0; x < grid->width(); x++)
		{
			geo.vertices.push_back(Vertex{ glm::vec3(-1.0f + cellSize * x, 1.0f - cellSize * y, 1.0f), grid->at(x, y).getColor() });
			geo.vertices.push_back(Vertex{ glm::vec3((-1.0f + cellSize) + cellSize * x, 1.0f - cellSize * y, 1.0f), grid->at(x, y).getColor() });
			geo.vertices.push_back(Vertex{ glm::vec3((-1.0f + cellSize) + cellSize * x, (1.0f - cellSize) - cellSize * y, 1.0f), grid->at(x, y).getColor() });
			geo.vertices.push_back(Vertex{ glm::vec3(-1.0f + cellSize * x, (1.0f - cellSize) - cellSize * y,  1.0f), grid->at(x, y).getColor() });

			std::array<uint32_t, 6> indices =
			{
				count * 4, count * 4 + 1, count * 4 + 2,
				count * 4, count * 4 + 3, count * 4 + 2
			};

			geo.indices.push_back(count*4);
			geo.indices.push_back(count*4 + 1);
			geo.indices.push_back(count*4 + 2);
			geo.indices.push_back(count*4);
			geo.indices.push_back(count*4 + 3);
			geo.indices.push_back(count*4 + 2);

			count++;
		}
	}
}

void GridRenderer::update()
{
	vao_bind(*vao.get());
	for (int y = 0; y < grid->height(); y++)
	{
		for (int x = 0; x < grid->width(); x++)
		{
			int v = (y * grid->width() + x) * 4;
			glm::vec3 color = grid->at(x, y).getColor();

			geo.vertices[v].col   = color;
			geo.vertices[v+1].col = color;
			geo.vertices[v+2].col = color;
			geo.vertices[v+3].col = color;
		}
	}
	vbo_buffer(*vbo.get(), geo.vertices);
}

void GridRenderer::draw()
{
	vao_bind(*vao.get());
	glDrawElements(GL_TRIANGLES, geo.indices.size(), GL_UNSIGNED_INT, 0);
}