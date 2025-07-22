all: test.out check_compiler

test.out:
	@g++ -std=c++17 test.cpp -o test.out
	@echo "Compile success!!"
	@./test.out
	@rm -rf ./test.out
check_compiler:
	@COMPILER=$$(g++ --version 2>&1| grep g++); \
	if [ "$${COMPILER}" != "" ]; then \
	    echo "compiling using g++!!"; \
	else \
	    COMPILER=$$(g++ --version 2>&1| grep clang); \
	    if [ "$${COMPILER}" != "" ]; then \
	        echo "compiling using clang!!"; \
	    else \
	        echo "Error: compiler not found"; \
	    fi \
	fi; \
	if [ "$${COMPILER}" != "" ]; then \
	    echo "compiler check pass !!"; \
	fi
	@echo
	@echo "compiler using :"
	@echo "$$(g++ --version)"
