#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "maze.h"
#include "file.h"

int main( int argc, char** argv ) 
{

char input[1024];
  clear_maze();
 // print_maze();
  int i;
  int j;
  char filename[1024];
if(argc>1)
{
  load(argv[1]);
}
print_maze();

 while( fgets( input, 1024, stdin) != NULL)
 {
  if(input[0] == 'r')
   {
     move_right();
   }
  else if(input[0] == 'l')
   {
     if(sscanf( input, "load %s",filename)==1)
     {
        load(filename);
     }
     else
     {
	 move_left();
     }
   }
  else if(input[0] == 'u')
  {
	move_up();
  }
  else if(input[0] == 'd')
  {
	move_down();
  }
  else if(input[0] == 's') 
   { 
     if(sscanf( input, "save %s", filename)==1)
     {
        save(filename);
     }
     else if(sscanf( input, "sword %d %d", &i, &j)==2)
     {
        build_sword(i,j);
     }
   }
  else if(sscanf( input, "wall  %d %d",&i, &j)==2)
     {
    	build_wall(i,j);
     }
  else if(sscanf( input, "empty %d %d", &i, &j)==2)
     {
	clear_wall(i,j);
     }
  else if(sscanf( input, "X %d", &i)==1)
     {
	set_location_x(i);
     }
  else if(sscanf( input, "Y %d", &i)==1)
     {
	set_location_y(i);
     }
  else if(sscanf( input, "treasure %d %d", &i, &j)==2)
     {
	build_treasure(i, j);
     }
  else if(sscanf( input, "monster %d %d", &i, &j)==2)
     {
	build_monster(i, j);
     }
 if(is_wall(get_location_y(),get_location_x()) ==3)
 {
	print_maze();
	fprintf(stdout, "YOU WIN!\n");
        exit(0);
 }
 else if(is_wall(get_location_y(), get_location_x()) ==4)
 {
     if(have_sword() == 1)
     {
       print_maze();
       fprintf(stdout, "THOU HATH SLAIN THE MONSTER\n");
       clear_sword();
       clear_wall(get_location_x(), get_location_y());
     }
     else
     {
	print_maze();
	fprintf(stdout, "THOU ART DEAD\n");
	exit(0);
     }
 }

 else if(is_wall(get_location_y(), get_location_x())==5)
 {
	print_maze();
	add_sword();
	clear_wall(get_location_x(), get_location_y());
	fprintf(stdout, "THOU HATH FOUND THE SWORD!\n");
 }
else
{
print_maze();
}
 }
return 0;
}


