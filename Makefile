OUT    = ascii
CXX    = g++
LD     = g++
CXXFLAGS   = -std=c++17 -Wall -pedantic -Wextra -O2
LIBS   = -lpng -ljpeg
SRCDIR = src
OBJDIR = build
DOCDIR = doc
SRC    = $(wildcard $(SRCDIR)/*.cpp)
OBJS   = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC) )
HEADERS = $(wildcard src/*.h)

.PHONY: all
all: compile

.PHONY: compile
compile: $(OBJDIR)/$(OUT)

$(OBJDIR)/$(OUT): $(OBJS)											# '|' means separator
	$(LD) $(CXXFLAGS) -o $@  $^ $(LIBS)								#link the target from all prerequisites

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -MMD -c -o $@  $<							#compile each cpp file + make dependencies

$(OBJDIR):
	mkdir -p $@														#make the build directory

.PHONY: run
run: compile
	$(OBJDIR)/$(OUT)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/$(OUT) $(OBJDIR)/*.o $(OBJDIR)/*.d
	rm -fd $(OBJDIR)
	rm -fdr $(DOCDIR)

.PHONY: doc															#generates all documentation
doc: Doxyfile $(HEADERS) | $(DOCDIR)
	mkdir -p $(DOCDIR)
	doxygen Doxyfile

.PHONY: pack														#makes a zip with the project
pack: clean
	rm -f samariva.zip
	ls . | zip -@ -r samariva.zip									# -@ takes file list from the input, -r recursively

-include $(OBJDIR)/*.d
