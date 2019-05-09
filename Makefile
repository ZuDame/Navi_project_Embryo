include infra/Make_h

SUBDIRS = libs apps docs configs

include infra/Make_t

INSTALLDIR = Release

#LDFLAGS += -L./vendor/fsdb/Linux64

execute		:
#	cd $(INSTALLDIR) && ./$(APP_EXE) && cd ..

all	:   
	make objects
	make release
	make execute

clean_all	:   
	make clean
	rm -rf $(INSTALLDIR)
