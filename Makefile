OUT    = samariva
CXX    = g++
LD     = g++
CXXFLAGS   = -std=c++17 -Wall -pedantic -O2
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

$(OBJDIR)/$(OUT): $(OBJS)
	@$(LD) $(CXXFLAGS) -o $(OUT)  $^ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -MMD -c -o $@  $<

$(OBJDIR):
	@mkdir -p $@

.PHONY: run
run: compile
	@./$(OUT) examples/config.txt

#sanitizer
.PHONY: san
san: $(OBJS)
	@$(LD) $(CXXFLAGS) -g -fsanitize=address -o $(OUT) $^ $(LIBS)
	@./$(OUT) examples/config.txt

#valgrind
.PHONY: val
val: compile
	@valgrind --leak-check=full ./$(OUT) examples/config.txt

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

.PHONY: pack
pack: clean
	@rm -f samariva.zip
	@ls . | zip -@ -r samariva.zip

-include $(OBJDIR)/*.d
