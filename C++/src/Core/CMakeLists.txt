add_library(${PROJECT_NAME}_Core STATIC
	"Image.cpp"
)

target_link_libraries(${PROJECT_NAME}_Core PRIVATE
	glad::glad
	OpenGL::GL
	glm::glm
)

target_include_directories(${PROJECT_NAME}_Core PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)