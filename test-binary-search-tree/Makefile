##########################################################################
<<<<<<< HEAD
## MAKEFILE: BST-TEMPLATE           					                ##
=======
## MAKEFILE FOR TEST FOR BST-TEMPLATE					##
>>>>>>> 1b2571f3b456e316b83e84f7f65589aa35026898
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
<<<<<<< HEAD
## CLEAN TASK								                            ##
=======
## CLEAN TASK								##
>>>>>>> 1b2571f3b456e316b83e84f7f65589aa35026898
##########################################################################
.PHONY: clean
clean:
	rm $(EXET) $(OBJS)
