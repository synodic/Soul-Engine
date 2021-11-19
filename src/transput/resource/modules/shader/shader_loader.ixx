export module synodic.soul.engine:transput.shader.loader;

import :transput.resource;
import std;

export class ShaderLoader : public ResourceLoader {

public:

	ShaderLoader() = default;
	~ShaderLoader() override = default;

	void Load(const std::string_view&) override = 0;


};
