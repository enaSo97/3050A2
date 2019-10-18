##
##	Makefile for module formatter project
##


##
##	Variables
##	---------
##

EXE	= modFormatter

# List of all of the object files in your project
OBJS = \
	formatter_main.o \
	formatter_process.o \
	strconcat.o \
	strsplit.o

MODS = \
    moduleSrcCaps

# Flags for compiling
CFLAGS = -g

# Libs that need to be linked
LDLIBS = -ldl


##
##	Build Targets
##	-------------
##

all world : $(EXE) libs

# Default target - build the program
$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LDLIBS)


# Build all of the libraries
#
# Done by looping over all of the source directories that we see,
# using a variable that can be repopulated if we are inheriting
# this makefile build context in a uname defined makefile.
#t
# Note that this is all on one line as each line from a makefile
# is run separately in a subshell - if we want to span lines,
# we would need to have line continue characters at the end of
# each line
libs:
	SCRIPTDIR=`pwd`; \
    for dir in moduleSrc* ; do \
        if [ -d "$$dir" ] ; then \
            ( cd "$$dir" ; $${SCRIPTDIR}/mk ) ; \
        fi ;\
    done


##
##	Cleanup Targets
##	---------------
##

# Remove all the files we create in the top level directory.
# Lines beginning with a '-' will not cause make(1) to stop if they
# result in a non-zero exit status (so a missing item to clean
# up will simply be ignored)
clean : 
	- rm -f $(EXE)
	- rm -f $(OBJS)
	- rm -f tags


# In all the library source directories that we see, call for
# a cleanup to occur
libclean: 
	SCRIPTDIR=`pwd`; \
    for dir in moduleSrc* ; do \
        if [ -d "$$dir" ] ; then \
            ( cd "$$dir" ; $${SCRIPTDIR}/mk clean ) ; \
        fi ;\
    done

#pRemove both the top level items, and the libraries - done simply
# through dependencies
allclean : clean libclean


##
##	Convenience/Support Targets
##	---------------------------
##

# ctags makes a database of source code tags for use with vim and co
tags ctags : dummy
	- ctags *.c

# a rule like this dummy rule can be use to make another rule always
# run - ctags depends on this, so therefore ctags will always be
# executed by "make ctags" as make is fooled into thinking that it
# has performed a dependency each time, and therefore re-does the work
test : test1 test2 test3 test4

test1:
	@echo TEST 1 : loading one module [default]
	- ./modFormatter -o test/result/test1.result -D libDefault.so test/test/para1
	- diff test/expected/test1.expected test/result/test1.result
	@echo

test2:
	@echo TEST 2 : loading one module [caps]
	- ./modFormatter -o test/result/test2.result -D Caps test/test/para1
	- diff test/expected/test2.expected test/result/test2.result
	@echo

test3:
	@echo TEST 3 : loading one module [CRLF]
	- ./modFormatter -o test/result/test3.result -D CRLF test/test/para1
	- diff test/expected/test3.expected test/result/test3.result
	@echo

test4:
	@echo TEST 4 : loading three module Quote,Caps,Default
	- ./modFormatter -o test/result/test4.result -D quote,caps,default test/test/para1
	- diff test/expected/test3.expected test/result/test3.result
	@echo
