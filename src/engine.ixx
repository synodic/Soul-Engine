export module synodic.soul.engine;

import std;

import synodic.cppaste;

// Re-export public partitions
export import :types;
export import :parameters;
export import :render.raster;

import :core.frame;
import :display.input;
import :display.gui;
import :display.window;
import :core.composition.event;
import :core.composition.entity.registry;
import :compute;
import :parallelism.scheduler;
import :render.graph;

// TODO: These imports are for the specific hardcoded backends. Remove with DI
import :display.input.mock;
import :render.raster.mock;
import :render.graph.standard;
import :display.window.mock;
import :display.gui.standard;

namespace synodic
{

	// Soul class - templated to support different module implementations
	export template<
		typename SchedulerModuleType   = SchedulerModule,
		typename ComputeModuleType	   = ComputeModule,
		typename InputModuleType	   = MockInputBackend,	// TODO: Replace with InputModule with DI
		typename RasterModuleType	   = MockRasterBackend,	 // TODO: Replace with RasterModule with DI
		typename RenderGraphModuleType = StandardRenderGraphBackend,  // TODO: Replace with RenderGraphModule with DI
		typename WindowModuleType	   = MockWindowBackend,
		typename GUIModuleType		   = StandardGUIBackend>
	class Soul final
	{
	public:
		Soul(soul::Parameters& params) :
			parameters_(params),
			frameTime_(),
			active_(true),
			entityRegistry_(),
			eventRegistry_(),
			schedulerModule_(parameters_.threadCount),
			computeModule_(),
			inputModule_(MockInputBackend()),
			rasterModule_(),
			renderGraphModule_()
		{
			parameters_.engineRefreshRate.AddCallback(
				[this](const std::int32_t value)
				{
					frameTime_ = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::seconds(1)) / value;
				});

			// flush parameters_ with new callbacks
			parameters_.engineRefreshRate.Update();
		}

		~Soul() = default;

		Soul(const Soul&)	  = delete;
		Soul(Soul&&) noexcept = default;

		Soul& operator=(const Soul&)	 = delete;
		Soul& operator=(Soul&&) noexcept = default;

		void Init()
		{
			Warmup();

			// TODO: Remove as it is temporary
			Run();
		}

		void CreateWindow(WindowParameters& params)
		{
			if (!windowModule_)
			{
				windowModule_.emplace();
			}
			windowModule_->CreateWindow(params, rasterModule_);
		}

	private:
		void Run()
		{
		}

		void Process(Frame&, Frame&)
		{
		}

		void Update(Frame&, Frame&)
		{
		}

		void Render(Frame&, Frame&)
		{
		}

		void Warmup()
		{
		}

		void EarlyFrameUpdate(Frame&, Frame&)
		{
		}

		void LateFrameUpdate(Frame&, Frame&)
		{
		}

		void EarlyUpdate(Frame&, Frame&)
		{
		}

		void LateUpdate(Frame&, Frame&)
		{
		}

		soul::Parameters& parameters_;
		std::chrono::nanoseconds frameTime_;
		bool active_;

		EntityRegistry entityRegistry_;
		EventRegistry eventRegistry_;
		SchedulerModuleType schedulerModule_;
		ComputeModuleType computeModule_;
		cppaste::Service<InputModule, InputModuleType> inputModule_;
		RasterModuleType rasterModule_;
		RenderGraphModuleType renderGraphModule_;

		// Potentially empty modules
		std::optional<cppaste::Service<WindowModuleType, Window>> windowModule_;
		std::optional<GUIModuleType> guiModule_;
	};

	namespace soul
	{

		export class App
		{
		public:
			App(Parameters params = Parameters()) :
				hasControl(true),
				parameters(params),
				soul(parameters)
			{
			}

			virtual ~App() = default;

			void CreateWindow(WindowParameters&)
			{
			}

			void Run()
			{
			}

		protected:
			bool hasControl;
			Parameters parameters;

		private:
			void CheckParameters();
			Soul<> soul;
		};
	}
}
