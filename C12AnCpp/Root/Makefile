
#INCDIR := inc
SRCDIR := src
OBJDIR := build

#INCCORE := $(C12CORE)/inc
LIBCORE := $(C12CORE)

#INCClas := $(C12CLAS12)/inc
LIBClas := $(C12CLAS12)


ROOT := $(shell root-config --cflags) $(shell root-config --libs)

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CFLAGS  := -Wall -O2 -fPIC -std=c++14

BUILD := $(shell mkdir -p build)

CFLAGS := $(ROOT) $(CFLAGS)

INCLUDES := -I$(CLAS12CPPBASE)/includes
LIBS := -L$(LIBCORE) -L$(LIBClas)

.PHONY: all clean
all: $(BUILD) $(OBJECTS)
	$(CXX) $(DEBUG) -I$(INCDIR)  $(INCLUDES) $(LIBS) -o libRootTools.so -shared $(CFLAGS)  $(OBJECTS)	

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(DEBUG) $(CFLAGS) $(INCLUDES) $(LIBS) -c $< -o $@

clean:
	rm build/*; rm libRootTools.so; rm -rf build
