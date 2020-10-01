##########################################################################
## MAKEFILE: BST-TEMPLATE           					                ##
##########################################################################
TMPL		:= ../_dtl
HDIR 		:= hdr
SDIR		:= src

EXET		:= a
OBJS		:= main.o testMyTemplate.o

CXX		:= g++
CXXFLAGS	:= -I$(TMPL) -I$(HDIR) -g \
			-Wall -Wextra -Wconversion -pedantic -std=c++2a


## BUILD DIRECTIVE:
all : $(EXET)

$(EXET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

%.o : $(SDIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $^ -o $@


##########################################################################
## CLEAN TASK								                            ##
##########################################################################
.PHONY: clean
clean:
	rm $(EXET) $(OBJS)
