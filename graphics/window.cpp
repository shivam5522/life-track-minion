#include "window.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

void Window::InitAppWindow() {
  GLFWwindow* window;
  #ifdef __linux__
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
  #endif
  if(!glfwInit()){
    std::cerr << "Could not initialize glfw \n";
    return;
  }
  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
  glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
  glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, GLFW_TRUE);
  glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
  window = glfwCreateWindow(win_width, win_height, "LifeTrack", nullptr, nullptr);
  glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), nullptr, nullptr, &screen_width, &screen_height);
  glfwSetWindowPos(window,  screen_width - win_width, screen_height - win_height);
  if(!window){
    glfwTerminate();
    std::cerr << "Window building failed \n";
    return;
  }

  glfwMakeContextCurrent(window);
  glClearColor(0.2, 0.2, 0.2, 0.2);
  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
}
