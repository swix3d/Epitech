/*
** EPITECH PROJECT, 2019
** Bootstrap_initiation_csfml
** File description:
** test.c
*/

#include <SFML/Graphics.h>
int main()
{
    sfVideoMode mode = {700, 798, 64};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;
    /* Create the main window */
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return (84);
    /* Load a sprite to display */
    texture = sfTexture_createFromFile("pika.jpg", NULL);
    if (!texture)
        return (84);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    /* Start the game loop */
    while (sfRenderWindow_isOpen(window))
    {
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            /* Close window : exit */
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);
        /* Draw the sprite */
        sfRenderWindow_drawSprite(window, sprite, NULL);
        /* Update the window */
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return (0);
}