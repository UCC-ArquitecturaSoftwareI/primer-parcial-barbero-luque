cmake_minimum_required(VERSION 3.12)
project(raylibTemplate)

set(CMAKE_CXX_STANDARD 14)

# Get the source toegher
file(GLOB sources *.cpp)

# Get the source  of classes toegher
file(GLOB sources_clases clases/*.cpp)


include("cmake/raylib_web.cmake")
include("cmake/raylib.cmake")


add_executable(${PROJECT_NAME} ${sources} ${sources_clases} clases/Nave.cpp clases/Nave.h clases/torre.h clases/torre.cpp clases/WindowController.cpp clases/hud.cpp clases/gameplayScreen.cpp clases/WindowController.h clases/hud.h clases/gameplayScreen.h clases/enemies.h clases/enemies.cpp clases/map.h clases/map.cpp clases/player.h clases/rendering.h clases/projectile.h clases/projectile.cpp)
add_dependencies(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ${raylib_LDFLAGS})
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

file(COPY "resources/"  DESTINATION "resources/")

include("cmake/raylib_web_post.cmake")
