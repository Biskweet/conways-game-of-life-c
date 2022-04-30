#include "gameoflife.h"


static void signal_handler(int _)
{
    running = 0;
}


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    signal(SIGINT, signal_handler);

    int** world = create_world();
    int** new_world;

    /* Defining starting cells below */

    // Glider
    world[35][50] = 1;
    world[35][51] = 1;
    world[35][52] = 1;
    world[36][52] = 1;
    world[37][51] = 1;

    // Pulsar
    world[10][12] = 1;
    world[10][13] = 1;
    world[10][14] = 1;
    world[10][18] = 1;
    world[10][19] = 1;
    world[10][20] = 1;

    world[12][10] = 1;
    world[12][15] = 1;
    world[12][17] = 1;
    world[12][22] = 1;

    world[13][10] = 1;
    world[13][15] = 1;
    world[13][17] = 1;
    world[13][22] = 1;

    world[14][10] = 1;
    world[14][15] = 1;
    world[14][17] = 1;
    world[14][22] = 1;

    world[15][12] = 1;
    world[15][13] = 1;
    world[15][14] = 1;
    world[15][18] = 1;
    world[15][19] = 1;
    world[15][20] = 1;

    world[17][12] = 1;
    world[17][13] = 1;
    world[17][14] = 1;
    world[17][18] = 1;
    world[17][19] = 1;
    world[17][20] = 1;

    world[18][10] = 1;
    world[18][15] = 1;
    world[18][17] = 1;
    world[18][22] = 1;

    world[19][10] = 1;
    world[19][15] = 1;
    world[19][17] = 1;
    world[19][22] = 1;

    world[20][10] = 1;
    world[20][15] = 1;
    world[20][17] = 1;
    world[20][22] = 1;

    world[22][12] = 1;
    world[22][13] = 1;
    world[22][14] = 1;
    world[22][18] = 1;
    world[22][19] = 1;
    world[22][20] = 1;


    while (running) {
        new_world = create_world();

        clear_screen();
        print_world(world);
        
        update_world(world, new_world);

        delete_world(world);

        world = new_world;

        usleep(T_WAIT);
    }

    clear_screen();
    print_world(world);

    printf("Shutting down.\n");
    delete_world(world);

    return 0;
}
