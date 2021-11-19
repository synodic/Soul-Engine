export module synodic.soul.engine:tracer.film;

import std;

// TODO: Replace glm types with module types
// #include <glm/glm.hpp>
struct uvec2 { std::uint32_t x, y; };
struct vec4 { float x, y, z, w; };

export class Film {
public:
	Film();
	~Film();

	uvec2 resolutionPrev;
	uvec2 resolution;
	uvec2 resolutionMax;

	float resolutionRatio;

	vec4* results;
	std::int32_t* hits;
};

//results(S_BEST_DEVICE)
inline Film::Film(){
	resolutionRatio = 1.0f;
}

inline Film::~Film() {

}


//__device__ glm::vec2 Film::GetSample(std::uint32_t id, curandState& randState) {
//
//	glm::vec2 parameterization = glm::vec2(
//		(curand_uniform(&randState) - 0.5f + id % resolution.x) / (resolution.x - 1),
//		(curand_uniform(&randState) - 0.5f + id / resolution.x) / (resolution.y - 1)
//	);
//
//	return parameterization;
//
//}
