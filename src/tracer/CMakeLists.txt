
##############################################
#Tracer

target_sources(soul-engine
    PUBLIC
		FILE_SET CXX_MODULES FILES
			tracer.ixx
			camera/camera.ixx
			camera/film/filter/filter.ixx
			ray/ray.ixx
			Camera/Film/Film.cpp
			Ray/RayJob.cpp
)

