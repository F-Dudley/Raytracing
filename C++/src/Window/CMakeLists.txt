add_library(${PROJECT_NAME}_Window STATIC
	"Layer.cpp"
	"LayerStack.cpp"
)

target_link_libraries(${PROJECT_NAME}_Window PRIVATE
	glfw
	
	glad::glad
	imgui::imgui
)

target_include_directories(${PROJECT_NAME}_Window PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)