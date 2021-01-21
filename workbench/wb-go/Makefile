.PHONY: build
build:
	@echo "> Build binaries"
	@mkdir -p ./bin
	@go build -o ./bin/wb-go

.PHONY: test
test:
	@echo "> Run the tests"
	@go test ./pkg/...
