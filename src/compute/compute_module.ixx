export module synodic.soul.engine:compute.compute_module;

import :compute.policy;
import :compute.cpu;
// import :compute.cuda;    // TODO: Implement CUDA module partition
// import :compute.opencl;  // TODO: Implement OpenCL module partition
import std;

export class ComputeModule {
public:
	ComputeModule() = default;
	virtual ~ComputeModule() = default;

	ComputeModule(const ComputeModule&) = delete;
	ComputeModule(ComputeModule&&) noexcept = default;

	ComputeModule& operator=(const ComputeModule&) = delete;
	ComputeModule& operator=(ComputeModule&&) noexcept = default;

	template <typename KernelFunction, typename... Args>
	void Launch(const ComputePolicy& policy,
		const KernelFunction& kernel,
		Args&&... parameters);

	// Factory
	static std::shared_ptr<ComputeModule> CreateModule();

private:
	// CUDABackend CUDABackend_;       // TODO: Uncomment when CUDA module is implemented
	// OpenCLBackend OpenCLBackend_;   // TODO: Uncomment when OpenCL module is implemented
	CPUBackend CPUBackend_;

	// std::vector<CUDADevice> CUDADevices_;      // TODO: Uncomment when CUDA module is implemented
	// std::vector<OpenCLDevice> OpenCLDevices_;  // TODO: Uncomment when OpenCL module is implemented
	CPUDevice CPUDevice_;
};

// Implementation
inline std::shared_ptr<ComputeModule> ComputeModule::CreateModule() {
	return std::make_shared<ComputeModule>();
}

template <typename KernelFunction, typename... Args>
void ComputeModule::Launch(const ComputePolicy& policy,
	const KernelFunction& kernel,
	Args&&... parameters) {
	// Implementation placeholder
}
