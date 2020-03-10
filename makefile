
#define macros
EXECUTABLE_NAME = main.exe
DIR_SRC := .\src
#DIR_INCLUDE = \
DIR_BIN := .
DIR_BIN_X86 := .
#DIR_SYMBOLS = $(DIR_BIN_X86)\symbols
DIR_INTERMEDIATE := .
DIR_INTERMEDIATE_X86 = .
SRC_FILES := \
	$(DIR_SRC)\Framework\Solucion.cpp \
	$(DIR_SRC)\Framework\Problema.cpp \
	$(DIR_SRC)\Framework\Framework.cpp \
	$(DIR_SRC)\Fibonacci\FibonacciS.cpp \
	$(DIR_SRC)\Fibonacci\FibonacciP.cpp \
	$(DIR_SRC)\MergeSort\MergeSort.cpp \
	$(DIR_SRC)\QuickSort\QuickSort.cpp \
	$(DIR_SRC)\main.cpp
  
OBJ_FILES := \
	$(DIR_INTERMEDIATE_X86)\Solucion.o \
	$(DIR_INTERMEDIATE_X86)\Problema.o \
	$(DIR_INTERMEDIATE_X86)\Framework.o \
	$(DIR_INTERMEDIATE_X86)\FibonacciS.o \
	$(DIR_INTERMEDIATE_X86)\FibonacciP.o \
	$(DIR_INTERMEDIATE_X86)\MergeSort.o \
	$(DIR_INTERMEDIATE_X86)\QuickSort.o \
	$(DIR_INTERMEDIATE_X86)\main.o 


compile : 
	del main.exe
	g++ -std=c++11 -ggdb -o $(DIR_BIN_X86)\$(EXECUTABLE_NAME) $(SRC_FILES) -I.
# delete output directories. No funca
clean:
	@echo "Limpiando workspace..."
	rmdir /S /Q $(DIR_BIN)
	rmdir /S /Q $(DIR_INTERMEDIATE)
 
# create output directories. No funca
create_dirs:
	@echo "Creando directorios..."
	mkdir $(DIR_BIN_X86)
	mkdir $(DIR_INTERMEDIATE_X86)
	
# build application
build: $(EXECUTABLE_NAME)

# create directories and build application
all: compile

