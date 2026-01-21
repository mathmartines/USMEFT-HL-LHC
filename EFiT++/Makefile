CURRENT_DIR = $(shell pwd)
NLOPT_DIR = /Users/martines/Desktop/Physics/nlopt-install
CXX = g++
CPPFLAGS = -I$(NLOPT_DIR)/include -I$(CURRENT_DIR)/include -I$(CURRENT_DIR)/external
CXXFLAGS = -stdlib=libc++ -pthread -std=c++20
LDFLAGS = -L$(NLOPT_DIR)/lib -Wl,-rpath,$(NLOPT_DIR)/lib
LIBS = -lnlopt -lm
IDIR = include/EFiT++
ODIR = lib

_DEPS = DataStorage EFTExpansion ChiSquare ChiSquareExpression Minimizer Fit Utilities
DEPS = $(patsubst %, $(IDIR)/%.h, $(_DEPS)) 
OBJ = $(patsubst %, $(ODIR)/%.o, $(_DEPS))

# Ensure that the output directory exists
$(ODIR):
	mkdir -p $(ODIR)

# Compile object files from the source files
$(ODIR)/%.o: src/%.cpp $(IDIR)/%.h | $(ODIR)
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)

ZprimeFit: ZprimeFit.o $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

ZprimeFit.o: $(CURRENT_DIR)/Zprime/ZprimeFit.cpp $(DEPS) $(CURRENT_DIR)/Zprime/ZprimeMatching.h
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)

clean:
	rm -rf $(ODIR)/*.o 
	rm -rf *.o 
	rm -rf ZprimeFit

# Phony targets
.PHONY: clean