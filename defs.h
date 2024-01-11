#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_OK            0
#define C_NOK          -1
#define C_TRUE          1
#define C_FALSE         0

#define MAX_STR        64
#define MAX_CAP       128

#define ARTIST_IDS   1001
#define SONG_IDS      4001

#define CURR_YR      2024

typedef struct {
  int   id;
  char  name[MAX_STR];
} ArtistType;

typedef struct {
  int day;
  int month;
  int year;
  int minutes;
  int seconds;
} SongTimeType;

typedef struct {
  int           id;
  ArtistType   *artist;
  SongTimeType *songTime;
} SongType;

typedef struct {
  int         size;
  ArtistType *elements;
  int         nextId;
} ArtistArrayType;

typedef struct Node {
  SongType    *data;
  struct Node *prev;
  struct Node *next;
} NodeType;

typedef struct {
  NodeType *songList; 
  NodeType *head; 
  int       nextId;  
} SongListType;

typedef struct {
  char            name[MAX_STR];
  SongListType    allSongs;
  ArtistArrayType artists;
} PlaylistType;


void printMenu(int*);
void loadArtistData(PlaylistType*);
void loadSongData(PlaylistType*);

void initArtistArray(ArtistArrayType*);
void addArtist(ArtistArrayType*, char*);
int findArtist(ArtistArrayType*, int, ArtistType **);
void printArtists(ArtistArrayType*);
void cleanupArtistArray(ArtistArrayType*);

void initSongList(SongListType*);
void initSongTime(SongTimeType**, int, int, int, int,int); 
void initSong(SongType**, ArtistType*, SongTimeType*);
int lessThan(SongTimeType*, SongTimeType*);
void addSong(SongListType*, SongType*);
void printSong(SongType*);
void printSongs(SongListType*); 
void cleanupSongList(SongListType*);

void initPlaylist(PlaylistType*, char*);
int validateSongTime(int, int, int, int, int);
void createSong(PlaylistType*, int, int, int, int, int, int);
void printSongByArtist(PlaylistType*, int);
void cleanupPlaylist(PlaylistType*);
