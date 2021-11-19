export module synodic.soul.engine:transput.spirv.loader;

import :transput.shader.loader;
import std;

export class SPIRVLoader : public ShaderLoader {

public:

	SPIRVLoader() = default;
	~SPIRVLoader() override = default;

	void Load(const std::string_view&) override;


};
