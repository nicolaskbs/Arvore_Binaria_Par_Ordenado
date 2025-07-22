CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++11 -g

BINDIR = bin

OBJDIR = obj

INCLUDEDIR = libs

SRCDIR = src

EXECUTABLE = $(BINDIR)/bst_par_ordenado

SOURCES = $(wildcard $(SRCDIR)/*.cpp)

OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

CPPFLAGS = -I$(INCLUDEDIR)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo "Vinculando os arquivos objeto para criar o executável..."
	@mkdir -p $(BINDIR) # Cria o diretório do executável, se não existir
	$(CXX) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR) # Cria o diretório de objetos, se não existir
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

run: all
	@echo "Executando o programa..."
	./$(EXECUTABLE)

clean:
	@echo "Limpando arquivos gerados..."
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean run