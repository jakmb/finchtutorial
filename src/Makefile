##############################################################################
# This makefile originally created by gmakemake, Fri Apr 15 18:40:16 EDT 2016
# 
# Note: documentation for (GNU) make can be found online at 
#       http://www.gnu.org/software/make/manual/make.html
##############################################################################

####
#### Special (built-in) targets for make/gmake
####

.SUFFIXES:	$(SUFFIXES:.cc=.cpp)

# The following target stops commands from being displayed during execution
.SILENT:

# The following target is only supported for GNU make, and indicates that 
# certain other targets don't actually produce a result in the file system 
# an object file, or an executable program), and instead they are just 
# 'convenience targets' to support what the programmer is doing.
.PHONY: clean purge reallyclean all objs archive unarchive help library docs findTodos rebuild release debug beautify diff diffDir 



####
#### Macros (variables) that will be used by make/gmake
####

# The various source files for our program(s)
MAIN_CPP_FILES  = 
OTHER_CPP_FILES =  Finch.cpp

MAIN_C_FILES  = 

OS := $(shell uname)

ifeq ("$(OS)","Linux")
OTHER_C_FILES = hid-linux.c  
else
ifeq ("$(OS)","Darwin")
OTHER_C_FILES = hid-osx.c  
endif
endif

HFILES =  Finch.h hidapi.h  

# Other files for your project, such as a 'ReadMe', etc.
OTHER_FILES = 

# Compilers and compiler settings
INCLUDE_DIRS += 
LIB_DIRS     += 

COMMONFLAGS += -Wall -Wextra -Wundef  \
               -Wcast-qual -Wcast-align -Wconversion -Wreturn-type \
               -Wfloat-equal

REAL_CXX = g++
# GFILT = INSERT PATH TO GFILT FILTER HERE (AND ENABLE THIS LINE)

ifeq ("$(GFILT)","")
CXX      = $(REAL_CXX) 
else
CXX      = $(GFILT) -banner:N
endif
CXXFLAGS += -Wold-style-cast \
            -Wsign-promo \
            -Wctor-dtor-privacy \
            -Woverloaded-virtual -Wnon-virtual-dtor \
            -Wno-deprecated

## Some other options....
# COMMONFLAGS += -Wpointer-arith -Wunreachable-code 
#
# CFLAGS += -Wimplicit -Wwrite-strings -Wstrict-prototypes 
# CFLAGS += -Wold-style-definition -Wmissing-prototypes 
# CFLAGS += -Wmissing-declarations -Wmissing-noreturn 
#
# CXXFLAGS += -Weffc++ 

CC       ?= gcc
CFLAGS   += -Wmissing-declarations  


LDFLAGS += -lm 

# Settings for code beautification (via 'astyle')
ASTYLE = astyle
ASTYLE_FLAGS += -A2 --add-brackets --indent=spaces=4 --break-closing-brackets
ASTYLE_FLAGS += --convert-tabs -C -S -N -w --pad-header --add-brackets 
ASTYLE_FLAGS += --align-pointer=name --add-one-line-brackets 

# Default target style (debug/release mode)
MODE = debug

# Additional flags for debug/release mode builds
DBG_FLAGS += -g -g3 -ggdb -O0 
REL_FLAGS += -DNDEBUG 
REL_FLAGS += -O3 
# Note that -O3 includes -finline-functions (among others)
# To optimize for speed/size tradeoff, use: REL_FLAGS += -Os 
# To optimize purely for speed, use: REL_FLAGS += -fast

# The subdirectory where intermediate files (.o, etc.) will be stored
OBJDIR = objs


# The extension used for object code files on this system
OBJEXT = o


# The subdirectory where executable files (.EXE under Windows) will be stored
EXEDIR = exes

# The directory in which the library is to be built
LIBDIR = .

# The name of the library that we'll build
LIBRARY = $(LIBDIR)/libFinch++.a

####
# Doxygen support macros

# Inside the file included below -- which you must create -- you will specify 
# the value for the "DOXYGEN_DIR" macro, which contains the base directory for 
# Doxygen's installation on your machine
-include Doxygen.mk

# This specifies the name of the Doxygen configuration file for your project
DOXYGEN_CONFIG_FILE = project.doxy

# This will "point at" the Doxygen executable
ifeq ("$(DOXYGEN_DIR)","")
DOXYGEN = doxygen
else
DOXYGEN = "$(DOXYGEN_DIR)/bin/doxygen"
endif

# Add the Doxygen configuration file to the list of things not to "auto-zap"
.PRECIOUS: $(DOXYGEN_CONFIG_FILE)

#-------------------------------------------------------------------
# The values for the rest of the macro variables are generated from 
# the settings above (or are typically "well-known" values).
#-------------------------------------------------------------------

# Updating preproc/library paths to cover extra directories
COMMONFLAGS += $(patsubst %,-I%,$(INCLUDE_DIRS))
LDFLAGS     += $(patsubst %,-L%,$(LIB_DIRS))

# Tying common flags into C/C++ compiler settings
CFLAGS += $(COMMONFLAGS)
CXXFLAGS += $(COMMONFLAGS)

# Generate the full list(s) of typed source files under our concern
CPP_FILES += $(MAIN_CPP_FILES) $(OTHER_CPP_FILES)
C_FILES   += $(MAIN_C_FILES) $(OTHER_C_FILES)

# Generate the master list of *all* source files under our concern
SOURCEFILES  += $(HFILES) 
SOURCEFILES  += $(CPP_FILES) 
SOURCEFILES += $(C_FILES) 

# The names of the applications are derived from the 'base names' 
# for their respective source files (without extensions)
MAIN_C_BASES =   $(basename $(MAIN_C_FILES))
MAIN_CPP_BASES = $(basename $(MAIN_CPP_FILES))

# Figure out the 'base names' of the other source files
OTHER_C_BASES =  $(basename $(OTHER_C_FILES))
OTHER_CPP_BASES = $(basename $(OTHER_CPP_FILES))

# Here's the (type-specific) list of base names for all source files
C_BASES    = $(MAIN_C_BASES) $(OTHER_C_BASES)
CPP_BASES  = $(MAIN_CPP_BASES) $(OTHER_CPP_BASES)

# Build a list of the names of all applications this makefile can produce
APPS += $(patsubst %,$(EXEDIR)/%,$(MAIN_CPP_BASES)) 
APPS += $(patsubst %,$(EXEDIR)/%,$(MAIN_C_BASES)) 


# Figure out the names of all of the compiled files
MAIN_OBJFILES =  $(MAIN_CPP_BASES:%=$(OBJDIR)/%.$(OBJEXT)) 
MAIN_OBJFILES += $(MAIN_C_BASES:%=$(OBJDIR)/%.$(OBJEXT)) 
OTHER_OBJFILES =  $(OTHER_CPP_BASES:%=$(OBJDIR)/%.$(OBJEXT)) 
OTHER_OBJFILES += $(OTHER_C_BASES:%=$(OBJDIR)/%.$(OBJEXT))
OBJFILES = $(MAIN_OBJFILES) $(OTHER_OBJFILES)


# Figure out how we're going to cache dependency information
DEPS_FILES =  $(CPP_BASES:%=$(OBJDIR)/%.d) 
DEPS_FILES += $(C_BASES:%=$(OBJDIR)/%.d) 

# Depending on what mode we're building under, activate different settings
ifeq ("$(MODE)","release")
CXXFLAGS += $(REL_FLAGS)
CFLAGS += $(REL_FLAGS)
LDFLAGS += $(REL_FLAGS)
else
CXXFLAGS += $(DBG_FLAGS)
CFLAGS += $(DBG_FLAGS)
LDFLAGS += $(DBG_FLAGS)
endif


####
#### Implicit rules, telling make/gmake how to create one kind of file 
#### from another kind of file (e.g. how to create "foo.o" from 
#### "foo.cpp")
####

# Compiling C code in ".c" files
$(OBJDIR)/%.$(OBJEXT): %.c
	@echo "$@"
	@if [ ! -d $(OBJDIR) ] ; then mkdir -p $(OBJDIR) ; fi
	$(CC) $(CFLAGS) -c $< -o $@

# Compiling C++ code in ".cpp" files
$(OBJDIR)/%.$(OBJEXT): %.cpp
	@echo "$@"
	@if [ ! -d $(OBJDIR) ] ; then mkdir -p $(OBJDIR) ; fi
	$(CXX) $(CXXFLAGS) -c $< -o $@


####
#### Explicit targets
####
all:	$(LIBRARY) $(APPS) 

help:
	@echo "Targets include:"
	@echo "all clean purge archive unarchive objs library docs findTodos diff rebuild release debug beautify " | fmt -65 | sed -e 's/^/	/'

objs: $(OBJFILES) 

library: $(LIBRARY) 

archive:
	tar cvf Archive.tar $(SOURCEFILES) $(OTHER_FILES) [mM]akefile 
	compress Archive.tar

unarchive:
	zcat Archive.tar | tar xvf - 

rebuild: clean all

clean:
	$(RM) $(OBJDIR)/*.$(OBJEXT) 
	$(RM) $(LIBRARY) 
	$(RM) $(APPS) *.exe $(EXEDIR)/*.exe core *.exe.stackdump 

purge reallyclean: clean
	if [ "$(EXEDIR)" != "." ] ; then $(RM) -r $(EXEDIR) ; fi
	$(RM) -r $(OBJDIR) $(CLASSDIR) $(JDOCDIR) 
	$(RM) $(DEPENDENCY_FILE) 

#
# A rule to build our library
#
$(LIBRARY):	$(OTHER_OBJFILES)
	@echo "$@..."
	mkdir -p "$(LIBDIR)"
	ar cr "$(LIBRARY)" $(OTHER_OBJFILES)
	if `which ranlib > /dev/null 2>&1` ; then ranlib "$(LIBRARY)" ; fi

####
# Rules to generate our applications would go here, similar to the 
# following (which is commented-out, since it's a fake....)
#

# $(EXEDIR)/MyApp:	$(OBJDIR)/MyApp.$(OBJEXT) $(LIBRARY)
#	@echo "$@..."
#	@mkdir -p $(EXEDIR)
#	$(CXX) -o $@ $(OBJDIR)/MyApp.$(OBJEXT) $(LIBRARY) $(LDFLAGS)


####
# Doxygen support targets
#
docs: $(DOXYGEN_CONFIG_FILE) 
	$(DOXYGEN) $(DOXYGEN_CONFIG_FILE)

$(DOXYGEN_CONFIG_FILE):
	$(DOXYGEN) -g $(DOXYGEN_CONFIG_FILE)
	sleep 5		# give the user a chance to read the info from doxygen


####
# Some code review support
#

findTodos:
	@echo "Unimplemented code:"
	@find . -name '*.[cmh]*' -exec fgrep -n -H NOT_IMPLEMENTED {} \; || true
	@echo ""
	@echo "Code review issues:"
	@find . -name '*.[cmh]*' -exec fgrep -n -H CODE_REVIEW {} \; || true
	@echo ""
	@echo "To-do items:"
	@(	    find . -name '*.[cmh]*' -exec fgrep -n -H TODO {} \; ; \
	    find . -name '*.[cmh]*' -exec fgrep -n -H @todo {} \; ; \
	    find . -name '*.[cmh]*' -exec fgrep -n -H @bug {} \; ; \
	    find . -name '*.xml' -exec fgrep -n -H 'TODO:' {} \; \
	  ) | fgrep -v /.svn/ | sort -u
	@echo ""


####
# Some additional (convenience) targets
#
rebuild: clean all 

release:
	@echo "Performing release mode build...."
	make MODE=release all

debug:
	@echo "Performing debug mode build...."
	make MODE=debug all


####
# Code beautification targets
#
beautify:
	for f in $(SOURCEFILES) ; do $(ASTYLE) $(ASTYLE_FLAGS) $$f ; done


####
# Some Subversion support functionality
#
diff: svn-diff

svn-diff:
	@make svn-diffDir DIFF_DIR=.

svn-diffDir:
	@if [ "$(DIFF_DIR)" = "" ] ; then \
		echo "Forgot to set DIFF_DIR=XYZ!" ; \
	else \
		FILE=/tmp/diff$$$$.txt ; \
		cd "$(DIFF_DIR)" ; \
		svn diff > $$FILE ; \
		if [ "$$OS" = "Windows_NT" ] ; then \
			write `cygpath -w "$$FILE"` ; sleep 3 ; \
		elif [ "$$OS_TYPE" = "MACOSX" ] ; then \
			open "$$FILE" ; sleep 3 ; \
		else \
			vi $$FILE ; \
		fi ; \
		$(RM) $$FILE ; \
	fi


# The following files (svnVersionText.[ch]) can be included into a build 
# in order to provide a string that can identify the version number 
# associated with the source code used to generate the build.
svnVersionText.c: svnVersionText.h updateSvnVersion_c
svnVersionText.h:
	@printf "/* Note: This file is auto-generated, and should not be manually updated or version controlled. */\n#ifndef SVN_VERSION_H\n#define SVN_VERSION_H\n\n#ifdef __cplusplus\nextern C {\n#endif\nextern const char * SVN_VERSION_TEXT;\n#ifdef __cplusplus\n}\n#endif\n\n#endif\n" > $@

SVN_BASE_DIR=.
updateSvnVersion_c:
	which svnversion > /dev/null 
	@(cd "$(SVN_BASE_DIR)" ; printf "/* Note: This file is auto-generated, and should not be manually updated or version controlled. */\n#include \"svnVersionText.h\"\n\nconst char * SVN_VERSION_TEXT = \"%s\";\n\n" "`svnversion`") > svn_version_foo.tmp
	@cmp -s svn_version_foo.tmp svnVersionText.c || (cp svn_version_foo.tmp svnVersionText.c ; echo "Updated SVN version text")
	@$(RM) svn_version_foo.tmp

####
#### Dependency management (courtesy of some intelligence in gcc.... ;-)
####

CFLAGS += -MP -MMD 
CXXFLAGS +=  -MP -MMD 

-include $(DEPS_FILES)


