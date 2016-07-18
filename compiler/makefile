#Definitions
CC = g++
MAIN_DIR = ./source/main
INC_DIR = headers
SRC_DIR = ./source
LEX_DIR = ./source/lexer
INT_DIR = ./source/inter
OBJ_DIR = ./objects
TST_DIR = ./testSource
CFLAGS  = -I./headers -Wall
CPPFLAGS = -DDEBUG

#Collections
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp)
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.cpp=.o)))
#$(SRC_DIR)/token.cpp	$(SRC_DIR)/word.cpp	$(SRC_DIR)/type.cpp	$(SRC_DIR)/array.cpp\
	$(SRC_DIR)/lexer.cpp	$(SRC_DIR)/id.cpp $(SRC_DIR)/env.cpp $(SRC_DIR)/analyzer.cpp\
	$(SRC_DIR)/stmnt.cpp
#OBJS = #$(OBJ_DIR)/token.o	$(OBJ_DIR)/word.o	$(OBJ_DIR)/type.o	$(OBJ_DIR)/array.o\
	$(OBJ_DIR)/lexer.o	$(OBJ_DIR)/id.o $(OBJ_DIR)/env.o $(OBJ_DIR)/analyzer.o\
	$(OBJ_DIR)/stmnt.o

###############################################
# Build all of the lexer library object files #
###############################################
all: $(OBJS)

$(OBJ_DIR)/analyzer.o: $(OBJ_DIR)/id.o $(OBJ_DIR)/lexer.o
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(SRC_DIR)/comp/analyzer.cpp -o $@

$(OBJ_DIR)/lexer.o: $(OBJ_DIR)/word.o $(SRC_DIR)/lexer/lexer.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(SRC_DIR)/lexer/lexer.cpp -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/**/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJ_DIR)/lexerTest.o
	rm -f lexerTest
	rm -f $(OBJ_DIR)/analyzerTest.o
	rm -f analyzerTest
	rm -f $(OBJ_DIR)/main.o
	rm -f main

######################################
#	Executable for testing the lexer   #
######################################
lexerTest: $(OBJ_DIR)/lexerTest.o $(OBJS)
	$(CC) $(CPPFLAGS) -o lexerTest $(OBJS) $(OBJ_DIR)/lexerTest.o

$(OBJ_DIR)/lexerTest.o: $(TST_DIR)/lexerTest.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(TST_DIR)/lexerTest.cpp -o $@

analyzerTest: $(OBJ_DIR)/analyzerTest.o $(OBJS)
	$(CC) $(CPPFLAGS) -o analyzerTest $(OBJS) $(OBJ_DIR)/analyzerTest.o

$(OBJ_DIR)/analyzerTest.o: $(TST_DIR)/analyzerTest.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(TST_DIR)/analyzerTest.cpp -o $@

main: $(OBJ_DIR)/main.o $(OBJS)
	$(CC) $(CPPFLAGS) -o main $(OBJS)

$(OBJ_DIR)/main.o: $(MAIN_DIR)/main.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(MAIN_DIR)/main.cpp -o $@
