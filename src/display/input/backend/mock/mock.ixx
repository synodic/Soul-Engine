export module synodic.soul.engine:display.input.mock;

import :display.input.input_module;

export class MockInputBackend : public InputModule
{
public:
	MockInputBackend()			 = default;
	~MockInputBackend() override = default;

	MockInputBackend(const MockInputBackend&) = delete;
	MockInputBackend(MockInputBackend&&)	  = default;

	MockInputBackend& operator=(const MockInputBackend&)	 = delete;
	MockInputBackend& operator=(MockInputBackend&&) noexcept = default;

	bool Poll() override
	{
		return false;
	}
};
