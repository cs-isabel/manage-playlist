#include "defs.h"

/*
  Function:   initArtistArray
  Purpose:    initializes every field of the given artist collection to default values.
  Parameters: 
    in:       artist array you want to initialize (output)
    return:     
*/
void initArtistArray(ArtistArrayType *arr) {
  (arr->elements) = calloc(MAX_CAP, sizeof(ArtistType));
  arr->size=0;
  arr->nextId=ARTIST_IDS;
}

/*
  Function:   addArtist
  Purpose:    adds a new rtist to the back of the given artist collection
  Parameters: 
    in:       artist array to add to (input/output), name of artist you want to add (input)
    return:     
*/
void addArtist(ArtistArrayType *arr, char *n){
  arr->elements[(arr->size)].id = arr->nextId;
  ++(arr->nextId);
  strcpy(arr->elements[(arr->size)].name, n);
  ++(arr->size);
}

/*
  Function:   findArtist
  Purpose:    searches through the given artist collection to find the artist with the given id
  Parameters: 
    in:       artist array (input), id you're searching for (input), p (output)
    return:   constant indicating if the artist was added
*/
int findArtist(ArtistArrayType *arr, int id, ArtistType **a){
  for (int i=0; i<arr->size; ++i){
    if(arr->elements[i].id == id){
      *a=&(arr->elements[i]);
      return C_OK;
    }
  }
  return C_NOK;
}

/*
  Function:   printArtists
  Purpose:    prints out to the screen all the details of every artist in the given artist collection
  Parameters: 
    in:       the artist array you want to print (input)
    return:     
*/
void printArtists(ArtistArrayType *arr){
  for(int i=0; i<arr->size; ++i){
    printf("Artist #%d %s\n", arr->elements[i].id, arr->elements[i].name);
  }
}

/*
  Function:   cleanupArtistArray
  Purpose:    deallocates all the required dynamically allocated memory for the given artist collection
  Parameters: 
    in:       artist array you want to free (output)
    return:     
*/
void cleanupArtistArray(ArtistArrayType *arr){
  free(arr->elements);
}
