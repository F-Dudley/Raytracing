
#add_subdirectory("Core")
add_subdirectory("Renderer")
add_subdirectory("Window")

add_executable(${PROJECT_NAME}
	"main.cpp"
	"App.cpp"
	"AppLayers.cpp"
)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE
		#${PROJECT_NAME}::Core
		${PROJECT_NAME}_Renderer
		${PROJECT_NAME}_Window

		glfw
		imgui::imgui
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)