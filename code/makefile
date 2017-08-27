SrcDir = src
IncDir = include
BinDir = .

OutputFileName   = main
OutputFile       = $(BinDir)/$(OutputFileName)
CompilationUnits = $(shell find $(SrcDir) -name '*.cpp')

Build    = g++
Standard = c++11
Warnings = -g -Wall
Optimize = -flto -O2

BuildFlags  = $(Warnings)       \
              -std=$(Standard)  \
              $(Optimize)       \
              -I $(IncDir)      \
              -o $(OutputFile)


directories: $(SrcDir)
	@[ -d "$(BinDir)" ] || mkdir "$(BinDir)";


build: directories
	@$(Build) $(BuildFlags) $(CompilationUnits)


clean:
	rm -f $(OutputFile)
