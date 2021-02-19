BUILD_DIR = cmake-build-debug

.PHONY: all
all: build

.PHONY: init
init:
	@echo "> Run CMake"
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR)

.PHONY: build
build:
	@echo "> Build"
	@make -j 4 -C $(BUILD_DIR)

.PHONY: test
test: build
	@echo "> Run the tests"
	@make -j 4 -C $(BUILD_DIR) test

.PHONY: fmt
fmt:
	@echo "> Run clang-format"
	@find ./src -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i

.PHONY: clean
clean:
	@echo "> Clean"
	@make -C $(BUILD_DIR) clean
