
CXX=g++
CXXFLAGS= -c -v -Wall -mwindows

MC_API_targetdir=bin

#interprocess directories
IP_dir=InterProcess
IP_targetdir=$(IP_dir)/bin



all: $(MC_API_targetdir)/mc_api.dll
interprocess: $(IP_targetdir)/interprocess.o

#Make the wrapper API
mc_api_dll.o:  mc_api_dll.c mc_api_dll.h 
	$(CXX) $(CXXFLAGS) -DBUILDING_MC_API_DLL mc_api_dll.c
	
	
#Make the actual DLL
$(MC_API_targetdir)/mc_api.dll: mc_api_dll.o $(IP_targetdir)/interprocess.o 
	$(CXX) -shared -o mc_api.dll mc_api_dll.o $(IP_targetdir)/interprocess.o -Wl,--out-implib,mc_api.a 
	
#Make the underlying interprocess routine
$(IP_targetdir)/interprocess.o: 
	cd $(IP_dir) && make all && cd ..



.PHONY: run
run:
	start $(IP_targetdir)/host.exe 
	$(IP_targetdir)/client.exe
	
	
.PHONY: clean
clean:	
	rm -rf *.o 
