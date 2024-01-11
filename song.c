#include "defs.h"

/*
  Function:   initSongList
  Purpose:    initializes both fields of the given list parameter to default values.
  Parameters: 
    in:       songList to initialize (output)
    return:     
*/
void initSongList(SongListType *list){
  list->nextId = SONG_IDS;
  list->songList=NULL;
  list->head=NULL;
}

/*
  Function:   initSongTime
  Purpose:    dynamically allocates memory for a SongTimeType structure, initializes its fields to the given parameters
  Parameters: 
    in:       st (output), year, month, day, min, second (all input)
    return:     
*/
void initSongTime(SongTimeType **st, int yr, int mth, int day, int min, int sec){
  SongTimeType *tempST = malloc(sizeof(SongTimeType));
  tempST->year=yr;
  tempST->month=mth;
  tempST->day=day;
  tempST->minutes=min;
  tempST->seconds=sec;
  
  *st=tempST;
}

/*
  Function:   initSong
  Purpose:    dynamically allocates memory for a SongType structure, initializes its artist and song time fields to the given parameters
  Parameters: 
    in:       SongType s (output), ArtistType a (input), SongTimeType st (input)
    return:     
*/
void initSong(SongType **s, ArtistType *a, SongTimeType *st){
  SongType *songHold=malloc(sizeof(SongType));
  songHold->artist=a;
  songHold->id=0;
  songHold->songTime=st;
  
  *s=songHold;
}

/*
  Function:   lessThan
  Purpose:    compares two song release times to see which is earlier
  Parameters: 
    in:       s1 (input), s2 (input)
    return:   constant related to if s1 is sooner (C_TRUE = 1), or not (C_FALSE=0)
*/
int lessThan(SongTimeType *s1, SongTimeType *s2) {
  if (((s1->year <= s2->year) && (s1->month <= s2->month)) && (s1->day <= s2->day)){
    if (s1->day < s2->day)
      return C_TRUE;
  }
 return C_FALSE;
}

/*
  Function:   addSong
  Purpose:    adds the song s in its correct position in the given list
  Parameters: 
    in:       list to add to (input/output), song to add (input)
    return:     
*/
void addSong(SongListType *list, SongType *s) {
  NodeType *head = list->head;
  
  NodeType *newNode;
  NodeType *currNode;
  NodeType *prevNode;

  newNode = malloc(sizeof(NodeType));

  newNode->data = s;
  newNode->prev = NULL;
  newNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) { //if there are any nodes in the dlList
    if (lessThan(newNode->data->songTime,currNode->data->songTime) == C_TRUE){  //if the new node goes before currNode
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  
  if (prevNode == NULL) { // add to front case, add to empty list case
    head = newNode;
    (list->head)=(newNode);
  }
  else {
    prevNode->next = newNode;
    newNode->prev  = prevNode;
  }

  newNode->next = currNode;

  if (currNode != NULL) {
    currNode->prev = newNode;
  }

  (newNode->data->id) = (list->nextId);
  ++(list->nextId);
}

/*
  Function:   printSong
  Purpose:    prints out all the details of the given song
  Parameters: 
    in:       song to print (input)
    return:     
*/
void printSong(SongType *s){
  printf("%d :: %d-%d-%02d %02d:%02d  :: %s\n", s->id, s->songTime->year, s->songTime->month, s->songTime->day,s->songTime->minutes,s->songTime->seconds, s->artist->name);
}

/*
  Function:   printSongs
  Purpose:    prints out the details of every song in the given list (forwards & backwards)
  Parameters: 
    in:       SongListType to print (input)
    return:     
*/
void printSongs(SongListType *list){
  NodeType *currNode = list->head;
  NodeType *prevNode = NULL;

  printf("\n---FORWARD:\n");
  while (currNode != NULL) {
    printSong(currNode->data);
    prevNode = currNode;
    currNode = currNode->next;
  }

  printf("\n---BACKWARD:\n");
  currNode = prevNode;
  while (currNode != NULL) {
    printSong(currNode->data);
    currNode = currNode->prev;
  }
}

/*
  Function:   cleanupSongList
  Purpose:    deallocates all the required dynamically allocated memory for the given list
  Parameters: 
    in:       the SongListType you want to free (output)
    return:     
*/
void cleanupSongList(SongListType *list) {
  NodeType *currNode = list->head;
  NodeType *nextNode;

  while (currNode != NULL) {
    nextNode = currNode->next;
    free(currNode->data->songTime);
    free(currNode->data);
    free(currNode);
    currNode = nextNode;
  }
}
