CURRENT_DIR = $(shell pwd)
NLOPT_DIR = /data/01/martines/Tools/nlopt-install
CXX = g++
CPPFLAGS = -I$(NLOPT_DIR)/include -I$(CURRENT_DIR)/include -I$(CURRENT_DIR)/external
# CXXFLAGS = -stdlib=libc++ -pthread -std=c++20
CXXFLAGS = -pthread -std=c++20 -m64
# LDFLAGS = -L$(NLOPT_DIR)/lib -Wl,-rpath,$(NLOPT_DIR)/lib
LDFLAGS = -L$(NLOPT_DIR)/lib64 -Wl,-rpath,$(NLOPT_DIR)/lib64
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

ZprimeFitServer: ZprimeFitServer.o $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

ZprimeFitServer.o: $(CURRENT_DIR)/Zprime/ZprimeFitServer.cpp $(DEPS) $(CURRENT_DIR)/Zprime/ZprimeMatching.h
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)

WprimeFitServer: WprimeFitServer.o $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

WprimeFitServer.o: $(CURRENT_DIR)/Wprime/WprimeFitServer.cpp $(DEPS) $(CURRENT_DIR)/Wprime/WprimeMatching.h
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)

clean:
	rm -rf $(ODIR)/*.o 
	rm -rf *.o 
	rm -rf ZprimeFit
	rm -rf ZprimeFitServer
	rm -rf WprimeFitServer

# Phony targets
.PHONY: clean