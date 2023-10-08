add_library(${PROJECT_NAME}::Renderer

)

target_link_libraries(${PROJECT_NAME}::Renderer PRIVATE
	glm::glm
)