#include <glm/glm.hpp>

struct Cell
{
	float concentration = 0.0f;

	glm::vec3 getColor() const
	{
		return glm::vec3(concentration);
	}
};