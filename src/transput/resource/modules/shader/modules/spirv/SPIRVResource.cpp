export module synodic.soul.engine:transput.spirv.resource;

import :transput.shader.resource;
import std;

export class SPIRVResource : public ShaderResource {

public:

	SPIRVResource(std::string_view);
	~SPIRVResource() = default;


private:



};

inline SPIRVResource::SPIRVResource(const std::string_view resourcePath):
    ShaderResource(resourcePath)
{

}
