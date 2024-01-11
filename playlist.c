#include "defs.h"

/*
  Function:   initPlaylist
  Purpose:    initializes the three fields of the given playlist structure
  Parameters: 
    in:       playlist to initialize (output), name of playlist (input)
    return:     
*/
void initPlaylist(PlaylistType *r, char *n){
  strcpy(r->name, n);
  initSongList(&r->allSongs);
  initArtistArray(&r->artists);
}

/*
  Function:   validateSongTime
  Purpose:    checks that the parameters represent a valid date and time, note: all months are given 31 days
  Parameters: 
    in:       year, month, day, minute, and second (all input)
    return:   constant to indicate if the time was valid  
*/
int validateSongTime(int yr, int mth, int day, int min, int sec){
  if(yr<=CURR_YR && (mth>=1 && mth<=12) && (day>=1 && day<=31) && (min>=0 && min<100) && (sec>=0 && sec<=60)){
  //printf("min is %d\n", min);
    return C_OK;
  }
  return C_NOK;
}

/*
  Function:   createSong
  Purpose:    creates a new song and adds it to the given playlist
  Parameters: 
    in:       the playlist (input), artist ID (input), year, month, day, minute, second (input)
    return:     
*/
void createSong(PlaylistType *p, int aId, int yr, int mth, int day, int min, int sec){
  if (validateSongTime(yr,mth,day,min,sec) == C_OK){
    ArtistType *tempA;
    if (findArtist(&p->artists, aId, &(tempA))==C_OK){
      SongTimeType *tempST;
      SongType *tempS;
      initSongTime(&tempST, yr, mth, day, min, sec);
      initSong(&tempS, tempA, tempST);

      tempS->songTime=tempST;
      
      addSong(&p->allSongs, tempS);
    }
    else{
      printf("ERROR: Artist id %d was not found\n", aId);
    }
  }
  else{
   printf("ERROR: Date %d-%d-%02d or time %02d:%02d is invalid\n", yr, mth, day,min,sec);
 }
}

/*
  Function:   printSongByArtist
  Purpose:    prints out the playlist name and the details of every song made by the artist with the given id.
  Parameters: 
    in:       the playlist (input) and the id of the artist (input)
    return:     
*/
void printSongByArtist(PlaylistType *p, int id){
  printf("SONG(S) BY ARTIST in %s:\n", p->name);
  
  SongListType *list;
  list = &p->allSongs;
  NodeType *currNode = list->head;

  int counter=0;
  while (currNode != NULL) {
    if (currNode->data->artist->id == id){
      counter++;
      printSong(currNode->data);
    }
    currNode = currNode->next;
  }
  if (counter == 0){
    printf("There are no songs by the artist ID %d in %s!\n", id, p->name);
  }
}

/*
  Function:   cleanupPlaylist
  Purpose:    cleans up all the dynamically allocated memory for the given playlist
  Parameters: 
    in:       playlist you want to free (output)
    return:     
*/
void cleanupPlaylist(PlaylistType *p){
  cleanupSongList(&p->allSongs);
  cleanupArtistArray(&p->artists);
}
