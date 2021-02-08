BUILD_DIR = cmake-build-debug

.PHONY: all
all: build

.PHONY: base
base:
	@echo "> Run CMake"
	@cmake -S . -B $(BUILD_DIR)

.PHONY: build
build: base
	@echo "> Build"
	@make -C $(BUILD_DIR)

.PHONY: test
test: build
	@echo "> Run the tests"
	@make -C $(BUILD_DIR) test

.PHONY: coverage
coverage: test
	@echo "> Show the test coverage"
	@gcovr -e '$(BUILD_DIR).*' -e '.*_tests.cpp' -r . $(BUILD_DIR)
