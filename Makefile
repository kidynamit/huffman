CPPFLAGS = -std=c++11 -fPIC
GCC = g++

huffencode: huffmantree.o huffmannode.o
	$(GCC) driver.cpp -c $(CPPFLAGS)
	$(GCC) -o huffencode huffmannode.o huffmantree.o driver.o

huffmantree.o: huffmantree.cpp huffmantree.h
	$(GCC) huffmantree.cpp -c $(CPPFLAGS)

huffmannode.o: huffmannode.cpp huffmannode.h
	$(GCC) huffmannode.cpp -c $(CPPFLAGS)

clean:
	rm -rf huffmannode.o huffmantree.o driver.o huffencode
