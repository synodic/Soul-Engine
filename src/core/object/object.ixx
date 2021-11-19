export module synodic.soul.engine:core.object;

import :types;

export class Object {
public:
	Object() = default;

	std::uint32_t verticeAmount;
	std::uint32_t faceAmount;
	std::uint32_t tetAmount;
	std::uint32_t materialAmount;
};
