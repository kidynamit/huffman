CPPFLAGS = -std=c++11 -fPIC
GCC = g++ 


huffmannode.o: huffmannode.cpp
	$(GCC) huffmannode.cpp -c $(CPPFLAGS)

clean:
	rm -rf huffmannode.o
