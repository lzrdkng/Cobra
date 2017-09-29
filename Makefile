#Compiler and Linker
CC          := g++

#The Target Binary Program
TARGET      := libCobra.so

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
INCDIR      := inc
BUILDDIR    := obj
TARGETDIR   := lib
RESDIR      := res
TESTSDIR    := tests
DOCDIR      := doc
SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -fPIC -fopenmp -Wall -g -std=gnu++14 -O3
LIB         := -lSDL2 -lSDL2_image
INC         := -I$(INCDIR)
INCDEP      := -I$(INCDIR)

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := $(shell echo $(SRCDIR)/*.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make
all: directories $(TARGET)

#Remake
remake: cleaner all


directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

#Clean only Objecst
clean:
	@$(RM) -rf $(BUILDDIR)

#Full Clean, Objects and Binaries
cleaner: clean clean-tests clean-doc
	@$(RM) -rf $(TARGETDIR)

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	$(CC) -shared -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

#Non-File Targets
.PHONY: all remake clean cleaner resources tests clean-tests doc clean-doc


# Testing
tests:
	make -C $(TESTSDIR)

clean-tests:
	make -C $(TESTSDIR) cleaner

# Documentation
doc:
	doxygen doc.config

clean-doc:
	@$(RM) -rf $(DOCDIR)
