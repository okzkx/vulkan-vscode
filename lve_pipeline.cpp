#include "lve_pipeline.hpp"

#include <string>
#include <vector>

// std
#include <fstream>
#include <iostream>

namespace lve {
	LvePipeline::LvePipeline(LveDevice& device, const std::string& vertFilePath,
		const std::string& fragFilePath, const PipelineConfigInfo& configInfo) : lveDevice{ device } {
		createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
	}

	std::vector<char> LvePipeline::readFile(const std::string& filePath) {
		std::ifstream file{ filePath, std::ios::ate | std::ios::binary };

		if (!file.is_open())
		{
			throw std::runtime_error("failed to open file: " + filePath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();
		return buffer;
	}

	void LvePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo) {
		std::cout << "Vertex Shader Code Path: " << vertFilePath << std::endl;
		std::cout << "Fragment Shader Code Path: " << fragFilePath << std::endl;
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);
		std::cout << "Vertex Shader Code Size: " << vertCode.size() << std::endl;
		std::cout << "Fragment Shader Code Size: " << fragCode.size() << std::endl;
	}

	void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) == VK_SUCCESS)
		{
			throw std::runtime_error("failed to create shader module");
		}
	}

	PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
		PipelineConfigInfo configInfo{};

		return configInfo;
	}
}