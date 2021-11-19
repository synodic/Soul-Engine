export module synodic.soul.engine:display.window.mock;

import :display.window;

export class MockWindowBackend : public WindowModule
{
public:
	MockWindowBackend()			  = default;
	~MockWindowBackend() override = default;

	MockWindowBackend(const MockWindowBackend&) = delete;
	MockWindowBackend(MockWindowBackend&&)		= default;

	MockWindowBackend& operator=(const MockWindowBackend&)	   = delete;
	MockWindowBackend& operator=(MockWindowBackend&&) noexcept = default;

	void Update() override
	{
	}

	bool Active() override
	{
		return false;
	}

	std::span<const char*> GetRasterExtensions() override
	{
		return {};
	}
};
