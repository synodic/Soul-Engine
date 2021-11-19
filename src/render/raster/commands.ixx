export module synodic.soul.engine:render.raster.commands;

import std;
import :render.raster.types;
import :render.raster.resource;
import :core.composition.entity.registry;

// Temporary types until proper ones are available
struct uvec2 { std::uint32_t x, y; };
template<typename T> using ExternalBuffer = std::vector<T>;

export enum class CommandType {
	Draw,
	DrawIndirect,
	UpdateBuffer,
	UpdateTexture,
	CopyBuffer,
	CopyTexture
};

export class RenderCommand{

public:

	RenderCommand() = default;
	~RenderCommand() = default;

};


export struct DrawCommand : RenderCommand {

	//draw
	std::uint32_t elementSize;
	std::uint32_t indexOffset;
	std::uint32_t vertexOffset;

	//scissor
	uvec2 scissorOffset;
	uvec2 scissorExtent;

	//data
	Entity* vertexBuffer;
	Entity* indexBuffer;

};

export struct DrawIndirectCommand : RenderCommand {

};

export struct UpdateBufferCommand : RenderCommand {

	std::uint32_t offset;
	ExternalBuffer<std::byte> data;
	Entity* buffer;

};

export struct UpdateTextureCommand : RenderCommand {

};

export struct CopyBufferCommand : RenderCommand {

};

export struct CopyTextureCommand : RenderCommand {

};
