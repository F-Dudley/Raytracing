
#add_subdirectory("Core")
add_subdirectory("Renderer")
add_subdirectory("Window")

add_executable(${PROJECT_NAME}
	"main.cpp"
	"App.h" "App.cpp"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${PROJECT_NAME}::Core
	${PROJECT_NAME}::Renderer
	${PROJECT_NAME}::Window
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)