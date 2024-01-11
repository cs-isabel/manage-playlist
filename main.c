#include <stdio.h>
#include <string.h>

#include "defs.h"

int main()
{
  int choice=C_NOK;
  PlaylistType isabelPlaylist;
  initPlaylist(&isabelPlaylist, "Isabel's Playlist");

  loadArtistData(&isabelPlaylist); 
  loadSongData(&isabelPlaylist);
  
  while(choice != 0){
    printf("\n");
    printMenu(&choice);
    while(choice != 1 && choice != 2 && choice != 3 && choice != 0){ //invalid entry
      printf("Error, please enter again");
      printMenu(&choice);
    }  
    printf("\n");
    if(choice == 1){
      printf("ARTISTS IN %s\n", isabelPlaylist.name); 
      printArtists(&isabelPlaylist.artists);
    }
    else if (choice ==2){  
      printf("SONGS in %s\n", isabelPlaylist.name); 
      printSongs(&isabelPlaylist.allSongs);
    }
    else if (choice ==3){
      int id;      
      printf("Enter artist id: ");
      scanf("%d", &id);     
      printSongByArtist(&isabelPlaylist, id);
    }
  }

  cleanupPlaylist(&isabelPlaylist);
  return(C_OK);
  
}

/*
  Function:   printMenu
  Purpose:    to print out the menu for the user to enter their choice
  Parameters: 
    in:       choice the user makes (output)
    return:     
*/
void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print artists\n");
  printf("  (2) Print songs\n");
  printf("  (3) Print songs by artist\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}
