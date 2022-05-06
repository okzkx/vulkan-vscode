#include "lve_model.hpp"

namespace lve
{
    LveModel::LveModel(LveDevice& device, const std::vector<Vertex> & vertices):lveDevice(device){
        createVertexBuffers(vertices);
    }

    LveModel::~LveModel(){
        vkDestroyBuffer(lveDevice.device(), vertexBuffer, nullptr);
        vkFreeMemory(lveDevice.device(), vertexBufferMemory, nullptr);
    }

    ~LveModel();
} // namespace lve