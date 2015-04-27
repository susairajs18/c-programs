#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "pelota.h"

#define N 20


int
main (int argc, char *argv[])
{

  Pelota pelota[N];
  srand (time (NULL));

  initscr ();
  while (1)
    {				/* Buzz Lightyear */
      /* Actualizar las coordenadas de la pelota */
      for (int i = 0; i < N; i++)
	pelota[i].actualizate ();

      /* Pintar */
      for (int i = 0; i < N; i++)
	mvprintw (pelota[i].get_y (), pelota[i].get_x (),
		  "%c", pelota[i].get_dibujo ());

      usleep (100000);
      refresh ();
    }
  endwin ();

  return EXIT_SUCCESS;
}