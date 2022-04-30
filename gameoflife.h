#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#define SIZEX 190
#define SIZEY 51
#define T_WAIT 75000


static volatile sig_atomic_t running = 1;


int** create_world();

void print_world(int** world);

int create_cell(int x, int y, int is_alive);

int get_neighbors_count(int** world, int x, int y);

void update_world(int** old_world, int** new_world);

void delete_world(int** world);

void clear_screen();
