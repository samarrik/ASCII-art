OUT    = ascii 														#name of the output file
CXX    = g++														#compiler
LD     = g++														#linker
CXXFLAGS   = -std=c++17 -Wall -pedantic -Wextra -O2					#flags to compile
LIBS   = -lpng -ljpeg												#libraries used in the project
SRCDIR = src														#specifuying source directory
OBJDIR = build														#build directory
DOC    = doc														#documentation directory
SRC    = $(wildcard $(SRCDIR)/*.cpp)								#cpp files
OBJS   = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC) )		#objects
HEADERS = $(wildcard src/*.h)										#headers


.PHONY: all
all: compile

.PHONY: compile
compile: $(OBJDIR)/$(OUT)

$(OBJDIR)/$(OUT): $(OBJS)
	$(LD) $(CXXFLAGS) -o $@  $^ $(LIBS)								#link the target from all prerequisites

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)							# '|' means separator
	$(CXX) $(CXXFLAGS) -MMD -c -o $@  $<							#compile each cpp file + make dependencies

$(OBJDIR):
	mkdir $@														#make the build directory

.PHONY: run
run: compile
	$(OBJDIR)/$(OUT)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/$(OUT) $(OBJDIR)/*.o $(OBJDIR)/*.d
	rm -fd $(OBJDIR)
	rm -fr $(DOC)/*

.PHONY: doc															#generates all documentation
doc: Doxyfile $(HEADERS)
	doxygen Doxyfile

.PHONY: pack														#makes a zip with the project
pack: clean
	rm -f samariva.zip
	ls . | zip -@ -r samariva.zip									# -@ takes file list from the input, -r recursively

-include $(OBJDIR)/*.d
