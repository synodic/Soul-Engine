export module synodic.soul.engine:tracer.ray;

import :types;
import std;

// TODO: Replace glm types with module types
// #include <glm/glm.hpp>
struct vec4 { float x, y, z, w; };
struct vec2 { float x, y; };

export class Ray {
public:
	vec4 storage;
	vec4 origin;
	vec4 direction;
	vec2 bary;
	std::uint32_t currentHit;
	std::uint32_t resultOffset;
	char job;
};
