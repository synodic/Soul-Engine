export module synodic.soul.engine:display.window;

export import :display.window.monitor;

import :parameters;
import :core.composition.entity.registry;

export class Window
{

public:

	Window(const WindowParameters&);
	virtual ~Window() = default;

	Window(const Window &) = delete;
	Window(Window &&) noexcept = default;

	Window& operator=(const Window &) = delete;
	Window& operator=(Window &&) noexcept = default;

	WindowParameters& Parameters();
	Entity Surface();

protected:

	Entity layout_;
	Entity surface_;
	WindowParameters windowParams_;

};

inline Window::Window(const WindowParameters& params) :
	layout_(),
	windowParams_(params)
{
	//std::make_unique<SingleLayout>();
}

inline WindowParameters& Window::Parameters()
{

	return windowParams_;

}

inline Entity Window::Surface()
{

	return surface_;

}

export class WindowModule
{
public:
	WindowModule();
	virtual ~WindowModule() = default;

	WindowModule(const WindowModule&)	  = delete;
	WindowModule(WindowModule&&) noexcept = default;

	WindowModule& operator=(const WindowModule&)	 = delete;
	WindowModule& operator=(WindowModule&&) noexcept = default;

	virtual void Update() = 0;
	virtual bool Active() = 0;

	// TODO: Enable with Service support
	//virtual void CreateWindow(const WindowParameters&, std::shared_ptr<RasterModule>&) = 0;

	virtual std::span<const char*> GetRasterExtensions() = 0;

	//virtual Window& MasterWindow() = 0;

protected:
	bool active_;
};
