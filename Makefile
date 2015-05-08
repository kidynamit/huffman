CPPFLAGS = -std=c++11 -fPIC
GCC = g++

huffencode: huffmantree.o huffmannode.o
	$(GCC) driver.cpp -c $(CPPFLAGS)
	$(GCC) -o huffencode huffmannode.o huffmantree.o driver.o

huffmantree.o: huffmantree.cpp
	$(GCC) huffmantree.cpp -c $(CPPFLAGS)

huffmannode.o: huffmannode.cpp
	$(GCC) huffmannode.cpp -c $(CPPFLAGS)

clean:
	rm -rf huffmannode.o
