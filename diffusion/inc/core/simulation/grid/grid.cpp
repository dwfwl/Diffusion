#include "grid.h"

void Grid::init(int width, int height)
{
	m_Width = width;
	m_Height = height;
	m_Size = m_Width * m_Height;
	m_Cells.resize(m_Size);

/*
	for (int i = 0; i < m_Size; i++)
	{
		int x = i % m_Width;
		int y = i / m_Width;

		int cc = 17 - y;
		if (x <= cc)
		{
			at(x, y).concentration = 1.0f;
		}
	}*/

	for (int i = 0; i < m_Size; i++)
	{
		int x = i % m_Width;
		int y = i / m_Width;

		if (x >= 5 && x <= 15 && y >= 5 && y <= 15)
		{
			at(x, y).concentration = 1.0f;
		}
	}
}

int Grid::width() const
{
	return m_Width;
}

int Grid::height() const
{
	return m_Height;
}

int Grid::size() const
{
	return m_Size;
}

Cell& Grid::at(int x, int y)
{
	return m_Cells[y * m_Width + x];
}

const Cell& Grid::at(int x, int y) const
{
	return m_Cells[y * m_Width + x];
}

void Grid::diffuse(float dt)
{
	Grid newGrid = *this;

	const int offsets[4][2] = {
		{0, -1},
		{1, 0},
		{0, 1},
		{-1, 0}
	};

	for (int i = 0; i < size(); i++)
	{
		float change = 0.0f;

		int x = i % m_Width;
		int y = i / m_Width;
		
		Cell& current = at(x, y);

		for (const auto& offset : offsets)
		{
			int dx = offset[0];
			int dy = offset[1];

			int nx = x + dx;
			int ny = y + dy;

			if (nx < 0 || nx >= m_Width || ny < 0 || ny >= m_Height)
				continue;

			Cell& neighbour = at(nx, ny);
			change += dc * dt* (neighbour.concentration - current.concentration);
		}

		newGrid.at(x, y).concentration = current.concentration + change;
	}

	*this = std::move(newGrid);

	std::cout << dt << "\n";
}
