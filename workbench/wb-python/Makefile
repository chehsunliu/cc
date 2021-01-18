SRC = ./src/lib.py

.PHONY: test
test: $(SRC)
	pytest $^

.PHONY: install-deps
install-deps: requirements.txt
	pip-sync $^

.PHONY: compile-deps
compile-deps: requirements.txt

requirements.txt: requirements.in
	pip-compile -o $@ $<
