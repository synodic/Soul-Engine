export module synodic.soul.engine:render.graph;

export import :render.graph.parameter;
export import :render.graph.builder;

import :core.composition.entity.registry;
import :parallelism.graph;
import :parallelism.scheduler;
import :render.graph.parameter;
import :render.graph.builder;
import :render.raster.command_list;
import std;

export class RenderGraphModule {
public:
	RenderGraphModule(std::shared_ptr<RasterModule>&, std::shared_ptr<SchedulerModule>&);
	virtual ~RenderGraphModule() = default;

	RenderGraphModule(const RenderGraphModule&) = delete;
	RenderGraphModule(RenderGraphModule&&) noexcept = default;

	RenderGraphModule& operator=(const RenderGraphModule&) = delete;
	RenderGraphModule& operator=(RenderGraphModule&&) noexcept = default;

	virtual void Execute() = 0;

	virtual void CreateRenderPass(RenderTaskParameters&,
		std::function<std::function<void(const EntityRegistry&, CommandList&)>(RenderGraphBuilder&)>) = 0;

	// Factory
	static std::shared_ptr<RenderGraphModule> CreateModule(
		std::shared_ptr<RasterModule>&,
		std::shared_ptr<SchedulerModule>&,
		std::shared_ptr<EntityRegistry>&);

protected:
	Graph renderGraph_;
};

// Implementation
inline RenderGraphModule::RenderGraphModule(
	std::shared_ptr<RasterModule>&,
	std::shared_ptr<SchedulerModule>& scheduler) :
	renderGraph_(scheduler) {
}

inline std::shared_ptr<RenderGraphModule> RenderGraphModule::CreateModule(
	std::shared_ptr<RasterModule>& rasterModule,
	std::shared_ptr<SchedulerModule>& scheduler,
	std::shared_ptr<EntityRegistry>& entityRegistry) {

	// TODO: Implement EntityRenderGraphBackend
	// return std::make_unique<EntityRenderGraphBackend>(rasterModule, scheduler, entityRegistry);
	return nullptr;
}
