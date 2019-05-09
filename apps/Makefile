include ../infra/Make_h
RELDIR =../Release
RELS = $(APP_EXE)

INCLUDES += -I/usr/local/include/libxml2

#CXXFLAGS += -std=gnu++11 
#LDFLAGS += -L../../vendor/fsdb/Linux64
#LDLIBS = -lboost_regex -lboost_system -lboost_filesystem -lxml2 
LDLIBS = -lxml2 

SOURCES = main.cc

include ../infra/Make_t

$(RELDIR)/$(RELS):	$(wildcard ../libs/$(TARGETDIR)/*.o) $(wildcard $(TARGETDIR)/*.o) 
	@if test ! -d $(RELDIR);	\
	then				\
		mkdir $(RELDIR);	\
	fi
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) -o $(RELDIR)/$(APP_EXE) $(wildcard ../libs/$(TARGETDIR)/*.o) $(wildcard $(TARGETDIR)/*.o) 
