# makefile
# Mike McMahon, A.Sc.T.
# March 29, 2015
# Student ID: 500605231
# Assignment #2 - List Manager
# CCPS 393 Section 1J0
# Instructor: L. Hiraki
# Purpose: To implement a linked list.  This is the makefile which is used
#          compile the source code files into the executable 'listmgr'.
#          The make file also 'cleans' up by removing all object files
#          after compilation.

OBJECTS = list_mgr.o list_funcs.o

all : listmgr clean

listmgr : $(OBJECTS)
    gcc -o listmgr $(OBJECTS)

list_mgr.o : list_mgr.c list_funcs.h list_types.h
    gcc -c list_mgr.c

list_funcs.o : list_funcs.c list_types.h
    gcc -c list_funcs.c

clean :
    $(RM) *.o