SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

default : all

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
all: $(BIN)/pruebatraductor $(BIN)/traductor_inverso

$(BIN)/traductor_inverso: $(OBJ)/traductor_inverso.o $(OBJ)/traductor.o $(OBJ)/palabra.o
	$(CXX) -o $(BIN)/traductor_inverso $(OBJ)/traductor_inverso.o $(OBJ)/traductor.o $(OBJ)/palabra.o

$(OBJ)/traductor_inverso.o: $(SRC)/traductor_inverso.cpp $(INC)/traductor.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/traductor_inverso.o $(SRC)/traductor_inverso.cpp

$(BIN)/pruebatraductor: $(OBJ)/pruebatraductor.o $(OBJ)/traductor.o $(OBJ)/palabra.o
	$(CXX) -o $(BIN)/pruebatraductor $(OBJ)/pruebatraductor.o $(OBJ)/traductor.o $(OBJ)/palabra.o

$(OBJ)/pruebatraductor.o: $(SRC)/pruebatraductor.cpp $(INC)/traductor.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebatraductor.o $(SRC)/pruebatraductor.cpp

$(OBJ)/traductor.o: $(SRC)/traductor.cpp $(INC)/traductor.h $(INC)/palabra.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/traductor.o $(SRC)/traductor.cpp

$(OBJ)/palabra.o: $(SRC)/palabra.cpp $(INC)/palabra.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/palabra.o $(SRC)/palabra.cpp

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
