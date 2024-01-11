OBJ = main.o load.o song.o artists.o playlist.o
EXE = playlist
CC = gcc -Wall 

$(EXE):	$(OBJ)
	$(CC) -o $(EXE) $(OBJ)

main.o:	main.c defs.h
	$(CC) -c main.c

load.o:	load.c defs.h
	$(CC) -c load.c

song.o:	song.c defs.h
	$(CC) -c song.c
	
artists.o:	artists.c defs.h
	$(CC) -c artists.c
	
playlist.o:	playlist.c defs.h
	$(CC) -c playlist.c

	
clean:
	rm -f $(EXE) $(OBJ)
