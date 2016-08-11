.phony: nogcc yesgcc noclang yesclang
nogcc:
	g++ -fno-elide-constructors main.cpp

yesgcc:
	g++ -felide-constructors main.cpp

noclang:
	clang++ -fno-elide-constructors main.cpp

yesclang:
	clang++ -felide-constructors main.cpp
