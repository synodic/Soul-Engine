##############################################
#Compute/Mock

target_sources(soul-engine
    PUBLIC
		FILE_SET CXX_MODULES FILES
			compute.mock.ixx
			mock_backend.ixx
			mock_device.ixx
			mock_buffer.ixx
    PRIVATE
			MockBackend.cpp
			MockBuffer.cpp
			MockDevice.cpp
)
