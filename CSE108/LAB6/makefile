all: clear clean compile run

clear:
	@clear

clean: *.o *.out
	@echo "---------------------------------------------------------\nCleaning any excess files...\n"
	@rm -f *.o *.out
	@echo "---------------------------------------------------------\nSuccesfully cleaned all excess files.\n"

compile: main.c
	@echo "---------------------------------------------------------\nCompiling...\n"
	@gcc -o program main.c -lm
	@echo "---------------------------------------------------------\nCompilation success..\n"

run: program
	@echo "---------------------------------------------------------\n"
	@./program
	@echo "\n---------------------------------------------------------\nComplete.\n"
