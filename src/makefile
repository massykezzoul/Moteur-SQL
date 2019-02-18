##################################################################################################################
##																												##
## Created By Massili Kezzoul to compile Code written in C++ on linux distribution								##
## 																												##
## How to use :																									##
## 		-make all      = Compilation																			##
## 		-make exe      = run the program (it will be compiled first)											##
##		-make debug	   = run the program with the debugger 'gdb'  												##
## 		-make clean    = delete object files (*.o)																##
## 		-make mrproper = delete object files (*.o) and the executable that was created $(EXEC)					##
## 		-make tar      = create an archive .tar with all the source code, headers and this makefile				##
## 		-make zip 	   = create an archive .zip with all the source code, headers and this makefile				##
##																												##
##################################################################################################################
 
CC=g++
CFLAGS=-Wall -pedantic -ansi -O3
LDFLAGS= -g #for debugging
EXEC=sql
SRC= $(wildcard *.cpp) test/test-proj.cpp
HEADERS = $(wildcard *.h)
OBJ= $(SRC:.cpp=.o) 
ARCHIVE_NAME = source_code

## Compilation



all: $(EXEC)

$(EXEC) : $(OBJ) $(HEADERS)
	@$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS) && echo "$(EXEC) created"

%.o: %.cpp 
	@$(CC) -o $@ -c $< $(CFLAGS) 


## clean and all that shit

.PHONY : clean mrproper

clean :
	@rm $(OBJ) -rvf

mrproper :	clean
	@rm $(EXEC) -rvf

exe : $(EXEC)
	@./$(EXEC) && echo "'$(EXEC)' Done" || echo "Fail on running '$(EXEC)'"

debug :
	@gdb $(EXEC)

tar : 
	@tar -czvf $(ARCHIVE_NAME).tar.gz makefile $(SRC) $(HEADERS) && echo "'$(ARCHIVE_NAME).tar.gz' created" || echo "FAIL"
zip : 
	@zip -r $(ARCHIVE_NAME).zip makefile $(SRC) $(HEADERS) && echo "'$(ARCHIVE_NAME).zip' created" || echo "FAIL"
