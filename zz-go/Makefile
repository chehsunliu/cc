.PHONY: build
build:
	@echo "> Build binaries"
	@mkdir -p ./bin
	@go build -o ./bin/zz-go

.PHONY: test
test:
	@echo "> Run the tests"
	@go test ./pkg/...
