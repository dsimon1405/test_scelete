cmake_minimum_required(VERSION 3.22)
project(Test)

#========================= compiler
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ZC_STATIC ON)
set(ZC_AUDIO ON)
set(ZC_MY_DEBUG 0)
set(Game_ASSETS_DIRECTORY_NAME assets)
set(Game_ASSETS_DESTINATION_PATH 
    ${PROJECT_BINARY_DIR}/$<$<PLATFORM_ID:Windows>:$<IF:$<CONFIG:Debug>,Debug/,Release/>>${Game_ASSETS_DIRECTORY_NAME})   #   windows?
set(ZC_PARANT_BIN_DIR ${Game_ASSETS_DESTINATION_PATH})
add_subdirectory(${PROJECT_SOURCE_DIR}/ZeroCore)


add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${PROJECT_SOURCE_DIR}/ZeroCore/include
	)

target_link_libraries(${PROJECT_NAME} PUBLIC ZeroCore)