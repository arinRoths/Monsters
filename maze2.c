#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "maze.h"

static room_t maze[10][10];
static int location_x;
static int location_y;
static int sword;
void set_location_x(int i)
{
location_x = i;
}

void set_location_y(int i)
{
location_y =i;
}

void clear_maze()
{
set_location_x(0);
set_location_y(0);
clear_sword();
for(int i=0; i<10; i++ ) 
  {
    for(int j =0; j<10;j++)
    {
       maze[i][j].wall=0;
    }
  }
}

int is_wall(int i,int j )
{

 if(maze[j][i].wall == 1)
   {
     return 1;
   }
 else if(maze[j][i].wall == 0)
   {
    return 0;
   }
 else if(maze[j][i].wall == 3)
   {
	return 3;
   }
 else if(maze[j][i].wall ==4)
   {
	return 4;
   }
 else
   {
	return 5;
   }

}



void build_wall(int i, int j)
{
maze[i][j].wall = 1;
}

void clear_wall(int i, int j)
{
maze[i][j].wall =0;
}
void build_treasure(int i, int j)
{
maze[i][j].wall = 3;
}
void build_monster(int i, int j)
{
maze[i][j].wall = 4;
}

void add_sword()
{
sword =1;

} 
void clear_sword()
{
sword =0;
}
void build_sword(int i, int j)
{
maze[i][j].wall = 5;
}
int have_sword()
{
  if(sword == 1)
  {
     return 1;
  }
  else
  {
    return 0;
  }
}

int get_location_x()
{
return location_x;
}

int get_location_y()
{
return location_y;
}



void print_maze()
{
for(int i=0; i<10; i++ ) 
 {
  for(int j=0; j<10; j++)
   {
    if( i == location_y&& j== location_x )
    {
      fprintf( stdout, "x "); 
 
    }
    else if(i== location_y-1 && j ==location_x-1)
    {
	if(is_wall(i,j)==0)
        {
	  fprintf(stdout, ". ");
        }
        else if(is_wall(i,j)==1)
        {
	  fprintf(stdout, "##");
        }
        else if(is_wall(i,j) ==3)
        {
	  fprintf(stdout, "T ");
        }
        else if(is_wall(i,j)==4)
        {
          fprintf(stdout, "M ");
        }
        else if(is_wall(i,j) ==5)
        {
	  fprintf(stdout, "S ");
        }
    }
    else if(i== location_y && j ==location_x-1)
    {
        if(is_wall(i,j)==0)
        {
          fprintf(stdout, ". ");
        }
        else if(is_wall(i,j)==1)
        {
          fprintf(stdout, "##");
        }
        else if(is_wall(i,j) ==3)
        {
          fprintf(stdout, "T ");
        }
        else if(is_wall(i,j)==4)
        {
          fprintf(stdout, "M ");
        }
        else if(is_wall(i,j) ==5)
        {
          fprintf(stdout, "S ");
        }
    }
    else if(i== location_y+1 && j ==location_x-1)
    {
        if(is_wall(i,j)==0)
        {
          fprintf(stdout, ". ");
        }
        else if(is_wall(i,j)==1)
        {
          fprintf(stdout, "##");
        }
        else if(is_wall(i,j) ==3)
        {
          fprintf(stdout, "T ");
        }
        else if(is_wall(i,j)==4)
        {
          fprintf(stdout, "M ");
        }
        else if(is_wall(i,j) ==5)
        {
          fprintf(stdout, "S ");
        }
    }
    else if(i== location_y-1 && j ==location_x)
    {
        if(is_wall(i,j)==0)
        {
          fprintf(stdout, ". ");
        }
        else if(is_wall(i,j)==1)
        {
          fprintf(stdout, "##");
        }
        else if(is_wall(i,j) ==3)
        {
          fprintf(stdout, "T ");
        }
        else if(is_wall(i,j)==4)
        {
          fprintf(stdout, "M ");
        }
        else if(is_wall(i,j) ==5)
        {
          fprintf(stdout, "S ");
        }
    }
    else if(i== location_y+1 && j ==location_x)
    {
        if(is_wall(i,j)==0)
        {
          fprintf(stdout, ". ");
        }
        else if(is_wall(i,j)==1)
        {
          fprintf(stdout, "##");
        }
        else if(is_wall(i,j) ==3)
        {
          fprintf(stdout, "T ");
        }
        else if(is_wall(i,j)==4)
        {
          fprintf(stdout, "M ");
        }
        else if(is_wall(i,j) ==5)
        {
          fprintf(stdout, "S ");
        }
    }
    else if(i== location_y-1 && j ==location_x+1)
    {
        if(is_wall(i,j)==0)
        {
          fprintf(stdout, ". ");
        }
        else if(is_wall(i,j)==1)
        {
          fprintf(stdout, "##");
        }
        else if(is_wall(i,j) ==3)
        {
          fprintf(stdout, "T ");
        }
        else if(is_wall(i,j)==4)
        {
          fprintf(stdout, "M ");
        }
        else if(is_wall(i,j) ==5)
        {
          fprintf(stdout, "S ");
        }
    }
    else if(i== location_y && j ==location_x+1)
    {
        if(is_wall(i,j)==0)
        {
          fprintf(stdout, ". ");
        }
        else if(is_wall(i,j)==1)
        {
          fprintf(stdout, "##");
        }
        else if(is_wall(i,j) ==3)
        {
          fprintf(stdout, "T ");
        }
        else if(is_wall(i,j)==4)
        {
          fprintf(stdout, "M ");
        }
        else if(is_wall(i,j) ==5)
        {
          fprintf(stdout, "S ");
        }
    }
    else if(i== location_y+1 && j ==location_x+1)
    {
        if(is_wall(i,j)==0)
        {
          fprintf(stdout, ". ");
        }
        else if(is_wall(i,j)==1)
        {
          fprintf(stdout, "##");
        }
        else if(is_wall(i,j) ==3)
        {
          fprintf(stdout, "T ");
        }
        else if(is_wall(i,j)==4)
        {
          fprintf(stdout, "M ");
        }
        else if(is_wall(i,j) ==5)
        {
          fprintf(stdout, "S ");
        }
    }

    else
    {
      fprintf( stdout, "??");
    }
   }
  fprintf(stdout, "\n");
 }
fprintf( stdout, "\n");
}

void move_right()
{
int place = location_x+1;
//we want the columns to increase by one
 if(is_wall(location_y, place) !=1 && place <=9)
 {
  set_location_x(place );
 }
}

void move_left()
{
int place = location_x-1;
//we want the columns o decrease by one
 if(is_wall(location_y,place) !=1 && place>=0)
 {
   set_location_x(place);
 }
}

void move_up()
{
int place = location_y-1;
//we want the rows to decrease by one
 if(is_wall(place, location_x) !=1 && place>=0)
 {
  set_location_y(place);
 }
}

void move_down()
{
int place = location_y+1;
//we want the rows to increase by one
 if(is_wall(place, location_x) !=1 && place <=9)
 {
  set_location_y(place);
 }
}


