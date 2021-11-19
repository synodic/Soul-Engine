
##############################################
#Resource

target_sources(soul-engine
    PUBLIC
		FILE_SET CXX_MODULES FILES
			transput.shader.ixx
			ShaderAsset.cpp
			ShaderResource.cpp
			ShaderLoader.cpp
			modules/spirv/transput.spirv.ixx
			modules/spirv/SPIRVAsset.cpp
			modules/spirv/SPIRVResource.cpp
			modules/spirv/SPIRVLoader.cpp
)
