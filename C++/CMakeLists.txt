# CMakeList.txt : CMake project for RaytracingInOneWeekend, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Raytracer"
	VERSION 0.0.1
	DESCRIPTION "Raytracing in One Weekend, by Peter Shirley"
)

# Find Packages
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)


# Add Project Source Directory
add_subdirectory("src")

# Add Tests Directory
#add_subdirectory("tests")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()
