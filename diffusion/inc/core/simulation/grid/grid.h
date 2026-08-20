#pragma once
#include <vector>
#include <iostream>
#include "../cell/cell.h"

constexpr float dc = 2;

class Grid
{
public:
	Grid() = default;
	Grid(const Grid&) = default;
	Grid(Grid&&) noexcept = default;

	Grid& operator=(const Grid&) = default;
	Grid& operator=(Grid&&) noexcept = default;

	void init(int width, int height);

	Cell& at(int x, int y);
	const Cell& at(int x, int y) const;

	void diffuse(float dt);

	int width() const;
	int height() const;
	int size() const;
private:
	int m_Width;
	int m_Height;
	int m_Size;

	std::vector<Cell> m_Cells;
};