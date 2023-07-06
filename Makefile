OUT    = asciiart
CXX    = g++
LD     = g++
CXXFLAGS   = -std=c++17 -Wall -pedantic -O2
LIBS   = -lpng -ljpeg
SRCDIR = src
OBJDIR = build
DOCDIR = doc
SRC    = $(wildcard $(SRCDIR)/*.cpp)
OBJS   = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
HEADERS = $(wildcard src/*.h)
SHWCASE = examples/showcase/config.txt

.PHONY: all
all: compile doc

.PHONY: compile
compile: $(OBJDIR)/$(OUT)

$(OBJDIR)/$(OUT): $(OBJS)
	@$(LD) $(CXXFLAGS) -o $(OUT)  $^ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -MMD -c -o $@  $<

$(OBJDIR):
	@mkdir -p $@

.PHONY: run
run: compile
	@./$(OUT) $(SHWCASE)

#sanitizer
.PHONY: san
san: $(OBJS)
	@$(LD) $(CXXFLAGS) -g -fsanitize=address -o $(OUT) $^ $(LIBS)
	@./$(OUT) $(SHWCASE)

#valgrind
.PHONY: val
val: compile
	@valgrind --leak-check=full ./$(OUT) $(SHWCASE)

.PHONY: clean
clean:
	@rm -f $(OBJDIR)/$(OUT) $(OBJDIR)/*.o $(OBJDIR)/*.d
	@rm -fd $(OBJDIR)
	@rm -fr $(DOCDIR)
	@rm -f $(OUT)

.PHONY: doc
doc: Doxyfile $(HEADERS) | $(DOCDIR)
	@rm -dfr $(DOCDIR)
	@mkdir -p $(DOCDIR)
	@doxygen Doxyfile

-include $(OBJDIR)/*.d