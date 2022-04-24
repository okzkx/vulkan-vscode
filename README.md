# vscode vulkan 渲染器

## 工程 

在 vscode 配置好 cmake + gcc 后可以直接进行开发

项目所依赖的三个模块, 已经全部包含在工程文件中

- glfw
- glm
- vulkan

## 环境配置

1. 使用 vscode 打开工程
2. vscode 配置好 cmake （Makefile 生成辅助）和 gcc（编译器）

## 构建并运行
### 方法一

1. vscode 执行指令 `CMake:Config`，或者 vscode cmake 插件大部分情况会自动运行 
2. vscode 执行指令 `CMake:Build`，或者按 `F7`
3. TERMINAL 运行 `./build/renderer` ，或者按 `F5` 使用 Debug 模式运行

### 方法二

1. 直接按 Ctrl + Shift + B，自动执行 tasks 内容进行，配置，构建，运行

![](doc/HelloVulkan.png)