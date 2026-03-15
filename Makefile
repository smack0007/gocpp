CPP_FLAGS := -g -fsanitize=address,undefined -Wall -Werror

.PHONY: build

bin:
	mkdir -p ./bin

hello-world: bin
	clang++ $(CPP_FLAGS) $(shell pkg-config fmt --cflags --libs) -I./src ./examples/hello-world/main.cc -o ./bin/hello-world
