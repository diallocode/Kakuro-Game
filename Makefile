# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Répertoires
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Sources
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Fichier main
MAIN = main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

# Cible finale
TARGET = $(BIN_DIR)/kakuro

# Règle principale
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJ_FILES) $(MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

# Compilation de main.cpp
$(MAIN_OBJ): $(MAIN)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilation des autres fichiers
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Exécution rapide
run: all
	./$(TARGET)
