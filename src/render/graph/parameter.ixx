export module synodic.soul.engine:render.graph.parameter;

import :core.composition.entity.registry;
import :render.raster.types;
import std;

export struct RenderTaskParameters {
public:
	RenderTaskParameters() = default;
	~RenderTaskParameters() = default;

	std::string name;
	ShaderSet shaders;
};

export struct RenderGraphOutputParameters {
public:
	RenderGraphOutputParameters() = default;
	~RenderGraphOutputParameters() = default;

	std::string name;
	Entity resource;
};

export struct RenderGraphInputParameters {
public:
	RenderGraphInputParameters() = default;
	~RenderGraphInputParameters() = default;

	std::string name;
	Entity resource;
};
