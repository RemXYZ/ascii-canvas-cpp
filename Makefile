mainFile = main.cpp
classes = ASCIICanvas.cpp
main1.exe: $(mainFile)
	g++  $(mainFile) $(classes) -o main