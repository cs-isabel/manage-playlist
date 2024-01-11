#include "defs.h"

void loadSongData(PlaylistType* p)
{
  createSong(p, 1002, 2023, 14,  3, 4, 16);
  createSong(p, 1002, 2023, 12, 32, 14, 40);
  createSong(p, 1001, 2021, 12, 9, 17, 12);
  createSong(p, 1005, 2023, 12, 9, 1, 30);
  createSong(p, 1002, 2022, 12, 9, 1, 0);
  createSong(p, 1003, 2023, 12, 9, 2, 50);
  createSong(p, 1004, 2010, 12, 9, 2, 75);
  createSong(p, 1006, 2022, 12, 9, 3, 30);
  createSong(p, 1006, 2012, 12, 9, 8, 2);
  createSong(p, 1006, 2016, 12, 9, 2, 48);
  createSong(p, 1001, 2013, 12, 9, 2, 30);
  createSong(p, 1004, 2014, 12, 9, 2, 0);
  createSong(p, 1002, 2016, 12, 9, 2, 11);
  createSong(p, 1004, 2004, 12, 8, 2, 33);
  createSong(p, 1003, 2023, 12, 8, 1, 45);
  createSong(p, 1006, 2021, 12, 8, 1, 0);
  createSong(p, 1004, 2021, 12, 8, 2, 0);
  createSong(p, 1004, 2017, 12, 8, 2, 47);
  createSong(p, 1003, 2020, 12, 8, 2, 15);
  createSong(p, 1004, 2023, 12, 8, 2, 0);
  createSong(p, 1001, 2016, 12, 8, 2, 30);
  createSong(p, 1001, 2021, 12, 8, 1, 15);
  createSong(p, 1006, 2020, 12, 8, 1, 58);
  createSong(p, 1001, 2023, 12, 8, 19, 16);
}

void loadArtistData(PlaylistType* p)
{
  addArtist(&p->artists, "Beabadoobee");
  addArtist(&p->artists, "Sade");
  addArtist(&p->artists, "Bruno");
  addArtist(&p->artists, "Joji");
  addArtist(&p->artists, "Laufey");
  addArtist(&p->artists, "Mitski");
}
