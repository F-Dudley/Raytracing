add_library(${PROJECT_NAME}_Renderer STATIC
	"Renderer.cpp"
)

target_link_libraries(${PROJECT_NAME}_Renderer PRIVATE
	${PROJECT_NAME}_Core

	glad::glad
)

target_include_directories(${PROJECT_NAME}_Renderer 
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}

	PRIVATE
		${PROJECT_NAME}_Core
)