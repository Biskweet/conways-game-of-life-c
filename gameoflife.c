#include "gameoflife.h"


int** create_world()
{
    int** world = (int**) malloc(sizeof(int*) * SIZEY);
    if (world == NULL) {
        printf("Allocation error (create_world).\n");
    }

    for (int y = 0; y < SIZEY; y++) {
        world[y] = (int*) malloc(sizeof(int) * SIZEX);
        if (world[y] == NULL) {
            printf("Allocation error (create_world) (2).\n"); return NULL;
        }

        for (int x = 0; x < SIZEX; x++) {
            world[y][x] = 0;
        }
    }

    return world;
}


void print_world(int** world)
{
    for (int y = 0; y < SIZEY; y++) {
        for (int x = 0; x < SIZEX; x++) {
            printf("%s", world[y][x] ? "#" : " ");
        }
        printf("\n");
    }
}


int get_neighbors_count(int** world, int x, int y)
{
    int alive_neighbors = 0;

    if (x > 0) {
        alive_neighbors += world[y][x-1];

        if (y > 0) alive_neighbors += world[y-1][x-1];
        if (y < (SIZEY - 1)) alive_neighbors += world[y+1][x-1];
    }

    if (x < (SIZEX - 1)) {
        alive_neighbors += world[y][x+1];

        if (y > 0) alive_neighbors += world[y-1][x+1];
        if (y < (SIZEY - 1)) alive_neighbors += world[y+1][x+1];
    }

    if (y > 0) alive_neighbors += world[y-1][x];
    if (y < (SIZEY - 1)) alive_neighbors += world[y+1][x];

    return alive_neighbors;
}


void update_world(int** old_world, int** new_world)
{
    for (int y = 0; y < SIZEY; y++) {
        for (int x = 0; x < SIZEX; x++) {
            int alive_neighbors = get_neighbors_count(old_world, x, y);

            // Rule 1 : Any live cell with two or three live neighbours survives, the others die
            if (old_world[y][x] == 1 && alive_neighbors != 2 && alive_neighbors != 3) {
                new_world[y][x] = !old_world[y][x];
            }

            // Rule 2 : Any dead cell with three live neighbours becomes a live cell.
            else if (old_world[y][x] == 0 && alive_neighbors == 3) {
                new_world[y][x] = !old_world[y][x];
            }

            // Rule 3 : All other live cells stay unchanged in the next generation.
            else {
                new_world[y][x] = old_world[y][x];
            }
        }
    }
}


void delete_world(int** world)
{
    if (world == NULL) return;

    for (int y = 0; y < SIZEY; y++) free(world[y]);
    free(world);
}


void clear_screen() {
    printf("\x1b[2J\x1b[1;1H");
}
