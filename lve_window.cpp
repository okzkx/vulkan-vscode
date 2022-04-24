#include "lve_window.hpp"
#include <stdexcept>

namespace lve {

	LveWindow::LveWindow(int width, int height, std::string windowName)
		: width{ width }, height{ height }, windowName{ windowName } {
		initWindow();
	}

	void LveWindow::initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // no to create opengl context
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // allow glfw window resize
		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr); // create window use settings upon
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create window surface");
		}
	}
} 