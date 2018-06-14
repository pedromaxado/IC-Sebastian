SrcDir = src
IncDir = include
BinDir = .

OutputFileName   = main
OutputFile       = $(BinDir)/$(OutputFileName)
CompilationUnits = $(shell find $(SrcDir) -name '*.cpp')

Build    = g++
Standard = c++11
Warnings = -Wall
Optimize = -O0

BuildFlags  = $(Warnings)       \
              -std=$(Standard)  \
              $(Optimize)       \
              -I $(IncDir)      \
              -o $(OutputFile)


directories: $(SrcDir)
	@[ -d "$(BinDir)" ] || mkdir "$(BinDir)";

build: directories
	@$(Build) $(BuildFlags) $(CompilationUnits)

run: $(OutputFile)
	./$(OutputFileName)

clean:
	rm -f $(OutputFile)
