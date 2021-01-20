.PHONY: all
all: test lint check-fmt

.PHONY: test
test:
	@echo "> Run the tests"
	@deno test

.PHONY: lint
lint:
	@echo "> Run the linter"
	@deno lint --unstable

.PHONY: check-fmt
check-fmt:
	@echo "> Check file formats"
	@deno fmt --check

.PHONY: fmt
fmt:
	@echo "> Run the formatter"
	@deno fmt
