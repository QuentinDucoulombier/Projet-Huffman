CFLAGS := -Wall -Wextra -Og -ggdb

exe: fonctions.o trisRapide.o main.o compresse.o decompresse.o
	gcc -Wall fonctions.o trisRapide.o main.o compresse.o decompresse.o -o exe
	touch compressé.txt

fonctions.o: fonctions.c fonctions.h
	gcc -c fonctions.c -o fonctions.o $(CFLAGS)

trisRapide.o: trisRapide.c trisRapide.h
	gcc -c trisRapide.c -o trisRapide.o $(CFLAGS)
	
compresse.o: compresse.c compresse.h
	gcc -c compresse.c -o compresse.o $(CFLAGS)

decompresse.o: decompresse.c decompresse.h
	gcc -c decompresse.c -o decompresse.o $(CFLAGS)

main.o: main.c fonctions.h trisRapide.h compresse.h decompresse.h
	gcc -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm compressé.txt
	rm -f exe
	@echo "tout a été éffacé"

push:
	bash git_push.sh

.PHONY: clean
