# Copyright (c) 2019 by Hendrik Klein-Hitpaß

cmake_minimum_required(VERSION 3.1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
if(CMAKE_VERSION VERSION_LESS "3.7.0")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(rts)



add_executable(main
		src/main.cpp
		src/mockwindow.cpp
		src/mockwindow.h
		src/RTS.cpp
		src/RTS.h
		src/OpenGLWindow.cpp
		src/OpenGLWindow.h
		lib/stb_image.cpp
		lib/stb_image.h
		src/Texture.cpp src/Texture.h src/MoveableUnit.cpp src/MoveableUnit.h src/Weapon.cpp src/Weapon.h src/RangedWeapon.cpp src/RangedWeapon.h src/RenderObject.cpp src/RenderObject.h src/TextureObject.cpp src/TextureObject.h src/Building.cpp src/Building.h src/Villager.cpp src/Villager.h src/MapUnit.cpp src/MapUnit.h)


#Qt5
find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(main PUBLIC Qt5::Widgets)



#Catch2
find_package(Catch2)
target_link_libraries(main PUBLIC Catch2::Catch2)



# GLEW
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	# Ubuntu using thirdparty libs via apt
	find_package(GLEW REQUIRED)
	target_link_libraries(main
			PUBLIC GLEW::GLEW
			)
else()
	find_package(GLEW REQUIRED CONFIG)
	target_link_libraries(main
			PUBLIC GLEW::glew
			)
endif()

# OpenGL
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(OpenGL_GL_PREFERENCE GLVND)

	find_package(OpenGL REQUIRED)
	target_link_libraries(main
			PUBLIC OpenGL::GL
			)
else()
	find_package(OpenGL REQUIRED)
	target_link_libraries(main
			PUBLIC OpenGL::GL
			)
endif()

#glm
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	find_package(glm REQUIRED)
	target_link_libraries(main
			PUBLIC glm
			)
else()
	find_package(glm REQUIRED)
	target_link_libraries(main
			PUBLIC glm
			)
endif()



# SDL2
find_package(SDL2 REQUIRED)
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
	# Windows using thirdparty-folder via Moodle
	target_link_libraries(main
			PUBLIC SDL2::SDL2
			PUBLIC SDL2::SDL2main
			)
elseif ((CMAKE_SYSTEM_NAME MATCHES "Darwin"))
	# macOS using thirdparty libs via Homebrew
	# Ubuntu using thirdparty libs via apt
	target_include_directories(main
			PUBLIC ${SDL2_INCLUDE_DIRS}
			)
	target_link_libraries(main
			PUBLIC ${SDL2_LIBRARIES}
			)
else((CMAKE_SYSTEM_NAME MATCHES "Linux"))
	target_link_libraries(main
			PUBLIC
			SDL2
			)
endif()