##############################################
#Compute/CUDA

target_sources(soul-engine
    PUBLIC
		FILE_SET CXX_MODULES FILES
			compute.cuda.ixx
			cuda_backend.ixx
			cuda_device.ixx
			cuda_buffer.ixx
    PRIVATE
			CUDABackend.cpp
			CUDABuffer.cpp
			CUDADevice.cpp
)
