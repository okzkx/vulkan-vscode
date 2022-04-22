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

# add_subdirectory(thirdParty/glfw)

include_directories(thirdParty/glm)
# include_directories(thirdParty/glfw/include)
include_directories(thirdParty/vulkan/include)


# FIND_LIBRARY(GLFW_LIB glfw3 thirdParty/glfw/include)
# FIND_LIBRARY(VULKAN_1_LIB vulkan-1 thirdParty/vulkan/include)
# link_libraries(${GLFW_LIB} ${VULKAN_1_LIB} )

# 项目用到的三方库路径
# set(3RD_PATH ${PROJECT_SOURCE_DIR}/3rd)

# 头文件
# set(3RD_INCLUDE ${3RD_PATH}/include)
# include_directories(${3RD_INCLUDE})

# 库文件
# set(3RD_LIBS ${3RD_PATH}/lib)
# FIND_LIBRARY(GLFW_LIB glfw3 ${3RD_LIBS}/glfw)
# FIND_LIBRARY(VULKAN_1_LIB vulkan-1 ${3RD_LIBS}/vulkan)
# link_libraries(${GLFW_LIB} ${VULKAN_1_LIB} )

set(MAIN testEnv.cpp)
set(EXE_NAME testEnv)
# 执行编译命令
# link_libraries(${EXE_NAME} glfw)
add_executable(${EXE_NAME} ${MAIN})
add_subdirectory(thirdParty/glfw)
target_link_libraries(${EXE_NAME} glfw vulkan-1)

# 复制 glfw3.dll 到编译目录下
# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy ${3RD_PATH}/lib/glfw/glfw3.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>/
# )