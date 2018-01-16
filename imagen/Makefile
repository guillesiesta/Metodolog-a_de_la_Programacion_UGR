BIN = bin
SRC = src
INC = include
OBJ = obj
DATOS = datos
LIB = lib

CXX = g++
CXXFLAGS = -Wall -g  -I$(INC) -c

# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/ocultar : $(SRC)/ocultar.cpp $(LIB)/libtodo.a  
	$(CXX) -I$(INC) -L$(LIB) -o $(BIN)/ocultar $(SRC)/ocultar.cpp  -ltodo

$(BIN)/revelar : $(SRC)/revelar.cpp $(LIB)/libtodo.a  
	$(CXX) -I$(INC) -L$(LIB) -o $(BIN)/revelar $(SRC)/revelar.cpp  -ltodo

$(BIN)/transformar : $(SRC)/transformar.cpp $(LIB)/libtodo.a  
	$(CXX) -I$(INC) -L$(LIB) -o $(BIN)/transformar $(SRC)/transformar.cpp  -ltodo

$(BIN)/generar : $(SRC)/generar.cpp $(LIB)/libtodo.a  
	$(CXX) -I$(INC) -L$(LIB) -o $(BIN)/generar $(SRC)/generar.cpp  -ltodo

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CXXFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h $(OBJ)/imagenES.o
	$(CXX) $(CXXFLAGS) -o $(OBJ)/imagen.o $(SRC)/imagen.cpp
	
$(OBJ)/procesar.o : $(SRC)/procesar.cpp $(INC)/imagen.h $(OBJ)/imagenES.o $(OBJ)/transformar.o 
	$(CXX) $(CXXFLAGS) -o $(OBJ)/procesar.o $(SRC)/procesar.cpp

$(OBJ)/transformacion.o : $(SRC)/transformacion.cpp $(INC)/transformacion.h  
	$(CXX) $(CXXFLAGS) -o $(OBJ)/transformacion.o $(SRC)/transformacion.cpp 

$(OBJ)/transformar.o : $(SRC)/transformar.cpp $(INC)/transformacion.h
	$(CXX) $(CXXFLAGS) -o $(OBJ)/transformar.o $(SRC)/transformar.cpp

$(OBJ)/generadores.o : $(SRC)/generadores.cpp $(INC)/generadores.h
	$(CXX) $(CXXFLAGS) -o $(OBJ)/generadores.o $(SRC)/generadores.cpp

$(OBJ)/generar.o : $(SRC)/generar.cpp $(INC)/generadores.h $(OBJ)/transformar.o $(OBJ)/generadores.o  
	$(CXX) $(CXXFLAGS) -o $(OBJ)/generar.o $(SRC)/generar.cpp

# ************ Todo *****************
all: $(BIN)/ocultar $(BIN)/revelar $(BIN)/transformar $(BIN)/generar
	
# ************ Librerias ************ 
$(LIB)/libtodo.a: $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/procesar.o $(OBJ)/transformar.o $(OBJ)/transformacion.o $(OBJ)/generadores.o
	ar -rvs $(LIB)/libtodo.a $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/procesar.o $(OBJ)/transformar.o $(OBJ)/transformacion.o $(OBJ)/generadores.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
