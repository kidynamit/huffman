CPPFLAGS = -std=c++11 -fPIC
GCC = g++

huffmantree.o: huffmantree.cpp
	$(GCC) huffmantree.cpp -c $(CPPFLAGS)

huffmannode.o: huffmannode.cpp
	$(GCC) huffmannode.cpp -c $(CPPFLAGS)

clean:
	rm -rf huffmannode.o
