add_library(${PROJECT_NAME}_Renderer STATIC
	"Renderer.cpp"
)

target_link_libraries(${PROJECT_NAME}_Renderer PRIVATE
	glm::glm
)

target_include_directories(${PROJECT_NAME}_Renderer PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)