#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>

#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
#include "Skybox.h"
#include "shader.h"
#include "GLFWStarterProject/SphereENV.h"
#include <string>

class Window
{
public:
	static int width;
	static int height;
	static glm::mat4 P; // P for projection
	static glm::mat4 V; // V for view

	// Setup
	static void initialize_objects();
	static void clean_up();
	static GLFWwindow* create_window(int width, int height);

	// Methods
	static glm::vec3 trackball(float x, float y);
	static void reset_ball();

	// Custom callbacks
	static void cursor_callback(GLFWwindow* window, double xpos, double ypos);
	static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	// Callbacks
	static void resize_callback(GLFWwindow* window, int width, int height);
	static bool idle_callback(int player1_att, int player2_att, int player1_med, 
		int player2_med, std::string p1_name, std::string p2_name);
	static void display_callback(GLFWwindow*);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif
