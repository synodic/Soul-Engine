##############################################
#Compute/OpenCL

target_sources(soul-engine
    PUBLIC
		FILE_SET CXX_MODULES FILES
			compute.opencl.ixx
			opencl_backend.ixx
			opencl_device.ixx
			opencl_buffer.ixx
    PRIVATE
			OpenCLBackend.cpp
			OpenCLBuffer.cpp
			OpenCLDevice.cpp
)
