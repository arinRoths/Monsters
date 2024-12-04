#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "maze.h"

void load(char* filename)
{
clear_maze();
int i ;
int j;
char idk[1024];
FILE* file;
char oneline[1024];
file = fopen( filename, "r");
if( file !=NULL)
{
  while( fgets( oneline, 1024, file) != NULL)
   {
     if(sscanf( oneline, "WALL  %d %d",&i, &j)==2)
     {
        build_wall(i,j);
     }
     else if(sscanf( oneline, "TREASURE %d %d", &i, &j)==2)
     {
	build_treasure(i,j);
     }
     else if(sscanf( oneline, "MONSTER %d %d", &i, &j)==2)
     {
	build_monster(i,j);
     }
     else if(sscanf( oneline, "INVENTORY %s", idk) ==1)
     {
       if(idk[0] == 'S')
        {
	  add_sword();
        }
     }
     else if(sscanf( oneline, "X %d", &i)==1)
     {
	set_location_x(i);
     }
     else if(sscanf( oneline, "Y %d", &i)==1)
     {
	set_location_y(i);
     }
     else if(sscanf( oneline, "SWORD %d %d", &i, &j)==2)
     {
         build_sword(i,j);
     }
   }
fclose( file);
}

}

void save( char* filename)
{
FILE* file;
file = fopen( filename, "w");
if( file !=NULL)
{
 int locaX = get_location_x();
 int locaY = get_location_y();
  for( int i =0; i <10; i++)
   {
     for(int j =0; j<10; j++)
     {
      if(is_wall(i,j)==1)
      {
        fprintf(file, "WALL %d %d\n", j, i);
      }
      else if(is_wall(i,j) ==3)
      {
	fprintf(file, "TREASURE %d %d\n", j, i);
      }
      else if(is_wall(i,j) == 4)
      {
	fprintf(file, "MONSTER %d %d\n", j, i);
      }
      else if(is_wall(i,j) ==5)
      {
	fprintf( file, "SWORD %d %d\n", j, i);
      }
      else if(have_sword() == 1)
      {
	fprintf(file, "INVENTORY SWORD\n");
      }
     }
   }
fprintf(file,"X %d\n", locaX);
fprintf(file,"Y %d\n", locaY);
fclose( file);
}
}

