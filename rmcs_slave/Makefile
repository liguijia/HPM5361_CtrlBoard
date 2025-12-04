# 定义构建目录
BUILD_DIR := build

# 默认的 CMake 配置指令（配置阶段）
# 注意：这里我们使用默认值，因为它们已经在 CMakeLists.txt 中定义了
CMAKE_CONFIG := cmake -B $(BUILD_DIR) -GNinja

# 默认的构建指令 (编译阶段)
CMAKE_BUILD := cmake --build $(BUILD_DIR)

.PHONY: all build rebuild clean config

# 默认目标：执行配置和编译
all: build

# 目标 1: 配置项目 (如果 build 目录不存在则执行)
config:
	@echo "--- 1. Running CMake Configuration ---"
	@$(CMAKE_CONFIG)

# 目标 2: 编译项目
build: config
	@echo "--- 2. Building Project with Ninja ---"
	@$(CMAKE_BUILD)

# 目标 3: 清理构建目录并重新编译
rebuild: clean build

# 目标 4: 清理构建目录
clean:
	@echo "--- Cleaning Build Directory ---"
	@rm -rf $(BUILD_DIR)