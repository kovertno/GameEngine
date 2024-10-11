cmake_minimum_required(VERSION 3.29)
project(GameEngine2D)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

set(SDL2_INCLUDE_DIRS /opt/homebrew/Cellar/sdl2/2.30.7/include)
set(SDL2_ttf_INCLUDE_DIRS /opt/homebrew/Cellar/sdl2_ttf/2.22.0/include)
set(SDL2_mixer_INCLUDE_DIRS /opt/homebrew/Cellar/sdl2_image/2.8.2_2/include)
set(SDL2_image_INCLUDE_DIRS /opt/homebrew/Cellar/sdl2_mixer/2.8.0/include)
set(GLM_INCLUDE_DIRS /opt/homebrew/Cellar/glm/1.0.1/include)
set(LUA_INCLUDE_DIRS /opt/homebrew/Cellar/lua/5.4.7/include/lua)
set(SOL2_INCLUDE_DIRS /opt/homebrew/cellar/sol2/include)
set(IMGUI_INCLUDE_DIRS /opt/homebrew/Cellar)

set(SDL2_LIBRARIES /opt/homebrew/Cellar/sdl2/2.30.7/lib/libSDL2.dylib)
set(SDL2_ttf_LIBRARIES /opt/homebrew/Cellar/sdl2_ttf/2.22.0/lib/libSDL2_ttf.dylib)
set(SDL2_mixer_LIBRARIES /opt/homebrew/Cellar/sdl2_mixer/2.8.0/lib/libSDL2_mixer.dylib)
set(SDL2_image_LIBRARIES /opt/homebrew/Cellar/sdl2_image/2.8.2_2/lib/libSDL2_image.dylib)
set(GLM_LIBRARIES /opt/homebrew/Cellar/glm/1.0.1/lib/libglm.dylib)
set(LUA_LIBRARIES /opt/homebrew/Cellar/lua/5.4.7/lib/liblua.dylib)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(glm REQUIRED)
find_package(Lua REQUIRED)


file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp)


add_executable(Engine ${SRC_FILES})


target_link_directories(Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../libs)


include_directories(${SDL2_INCLUDE_DIRS}
        ${SDL2_ttf_INCLUDE_DIRS}
        ${SDL2_mixer_INCLUDE_DIRS}
        ${SDL2_image_INCLUDE_DIRS}
        ${LUA_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
        ${SOL2_INCLUDE_DIRS}
        ${IMGUI_INCLUDE_DIRS})


message(STATUS "SDL2_INCLUDE_DIRS: ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2_ttf_INCLUDE_DIRS: ${SDL2_ttf_INCLUDE_DIRS}")
message(STATUS "SDL2_mixer_INCLUDE_DIRS: ${SDL2_mixer_INCLUDE_DIRS}")
message(STATUS "SDL2_image_INCLUDE_DIRS: ${SDL2_image_INCLUDE_DIRS}")


target_link_libraries(Engine ${SDL2_LIBRARIES}
        ${SDL2_ttf_LIBRARIES}
        ${SDL2_mixer_LIBRARIES}
        ${SDL2_image_LIBRARIES}
        ${LUA_LIBRARIES}
        ${GLM_LIBRARIES}
        dl)