##############################################
#Compute/CPU

target_sources(soul-engine
    PUBLIC
		FILE_SET CXX_MODULES FILES
			compute.cpu.ixx
			cpu_backend.ixx
			cpu_device.ixx
			cpu_buffer.ixx
)
