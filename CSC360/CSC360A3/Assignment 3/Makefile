all: diskinfo disklist diskget diskput


diskinfo: diskinfo.o reader.o
	gcc diskinfo.o reader.o -o diskinfo

disklist: disklist.o reader.o
	gcc disklist.o reader.o -o disklist

diskget: diskget.o reader.o
	gcc diskget.o reader.o -o diskget

diskput: diskput.o reader.o
	gcc diskput.o reader.o -o diskput


diskinfo.o: diskinfo.c
	gcc diskinfo.c -o diskinfo.o -c

disklist.o: disklist.c
	gcc disklist.c -o disklist.o -c

diskget.o: diskget.c
	gcc diskget.c -o diskget.o -c

diskput.o: diskput.c
	gcc diskput.c -o diskput.o -c

reader.o: reader.c
	gcc reader.c -o reader.o -c


clean:
	rm diskinfo.o disklist.o reader.o diskget.o diskput.o