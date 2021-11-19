export module synodic.soul.engine:tracer.film;

// TODO: Replace glm types with module types
// #include <glm/glm.hpp>

export class Film {
public:
	Film();
	~Film();

	glm::uvec2 resolutionPrev;
	glm::uvec2 resolution;
	glm::uvec2 resolutionMax;

	float resolutionRatio;

	glm::vec4* results;
	std::int32_t* hits;
};
