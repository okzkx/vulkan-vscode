cmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME vulkan-vscode)
project(${PROJECT_NAME} VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find_package(Git QUIET)
# if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")

# # Update submodules as needed   更新子模块
#     option(GIT_SUBMODULE "Check submodules during build" ON)
#     if(GIT_SUBMODULE)
#         message(STATUS "Submodule update")
#         execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
#                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#                         RESULT_VARIABLE GIT_SUBMOD_RESULT)
#         if(NOT GIT_SUBMOD_RESULT EQUAL "0")
#             message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMODE_RESULT}, please check")
#         endif()
#     endif()

# endif()

include_directories(thirdParty/glm)
include_directories(thirdParty/vulkan/include)

find_library(VULKAN_1_LIB vulkan-1 thirdParty/vulkan/lib)

set(EXE_NAME renderer)

# 执行编译命令
add_executable(${EXE_NAME} main.cpp lve_window.cpp first_app.cpp lve_pipeline.cpp lve_device.cpp lve_swap_chain.cpp lve_model.cpp)
add_subdirectory(thirdParty/glfw)
target_link_libraries(${EXE_NAME} ${VULKAN_1_LIB} glfw)

# 复制 glfw3.dll 到编译目录下
# add_custom_command( 
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy ${3RD_PATH}/lib/glfw/glfw3.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>/
# )

#execute_process(COMMAND ./compile)

add_custom_command(
        TARGET ${EXE_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo Recompile shaders to ${CMAKE_CURRENT_SOURCE_DIR}/build/shaders
)

add_custom_command(
        TARGET ${EXE_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/shaders ${CMAKE_CURRENT_SOURCE_DIR}/build/shaders
)
