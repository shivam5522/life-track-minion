add_library(graphics STATIC window.cpp)
target_include_directories(graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(graphics PUBLIC glfw OpenGL::GL)
