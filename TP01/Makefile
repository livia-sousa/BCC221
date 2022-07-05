all: exe

exe: main.o funcoes.o imovel.o chacara.o apartamento.o casa.o
	g++ main.o funcoes.o imovel.o chacara.o apartamento.o casa.o -o exe -Wall

main.o: main.cpp
	g++ main.cpp -c -Wall

funcoes.o: funcoes.cpp funcoes.h
	g++ funcoes.cpp -c -Wall

imovel.o: imovel.cpp imovel.h
	g++ imovel.cpp -c -Wall

chacara.o: chacara.cpp chacara.h
	g++ chacara.cpp -c -Wall

apartamento.o: apartamento.cpp apartamento.h
	g++ apartamento.cpp -c -Wall

casa.o: casa.cpp casa.h
	g++ casa.cpp -c -Wall

clean:
	rm *.o exe
