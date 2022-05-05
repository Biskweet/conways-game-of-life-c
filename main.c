#include "gameoflife.h"
#include "shapes.h"


static volatile sig_atomic_t running = 1;

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


    // Glider
    // draw_glider(world);

    // Pulsar
    // draw_pulsar(world);

    // Activating (SIZEX * SIZEY)/4 random cells (yes this is a very arbitrary number and so what)
    activate_cells(world, (SIZEX * SIZEY)/4);


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
