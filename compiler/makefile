#Definitions
CC = g++
INC_DIR = headers
SRC_DIR = ./source
OBJ_DIR = ./objects
CFLAGS  = -I./headers -Wall
CPPFLAGS = -DDEBUG

#Collections
SRCS =	$(wildcard $(SRC_DIR)/*.cpp)
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
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(SRC_DIR)/analyzer.cpp -o $@

$(OBJ_DIR)/lexer.o: $(OBJ_DIR)/word.o $(SRC_DIR)/lexer.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(SRC_DIR)/lexer.cpp -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJ_DIR)/lexerTest.o
	rm -f lexerTest

######################################
#	Executable for testing the lexer   #
######################################
lexerTest: $(OBJ_DIR)/lexerTest.o $(OBJS)
	$(CC) $(CPPFLAGS) -o lexerTest $(OBJS) $(OBJ_DIR)/lexerTest.o

$(OBJ_DIR)/lexerTest.o: $(SRC_DIR)/testSource/lexerTest.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(SRC_DIR)/testSource/lexerTest.cpp -o $@

analyzerTest: $(OBJ_DIR)/analyzerTest.o $(OBJS)
	$(CC) $(CPPFLAGS) -o analyzerTest $(OBJS) $(OBJ_DIR)/analyzerTest.o

$(OBJ_DIR)/analyzerTest.o: $(SRC_DIR)/testSource/analyzerTest.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(SRC_DIR)/testSource/analyzerTest.cpp -o $@
