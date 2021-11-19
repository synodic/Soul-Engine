export module synodic.soul.engine:render.raster.types;

import :core.composition.entity.registry;

export struct ShaderSet
{

	Entity* vertex;

	Entity* tessellationControl;

	Entity* tessellationEvaluation;

	Entity* geometry;

	Entity* fragment;

};

export enum class Format {

	RGBA,
	Unknown

};
