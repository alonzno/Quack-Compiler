scanner: lex.yy.cpp
	g++ -L/usr/local/include/reflex -lreflex lex.yy.cpp -o scanner
lex.yy.cpp: lexerspec.l
	reflex lexerspec.l
