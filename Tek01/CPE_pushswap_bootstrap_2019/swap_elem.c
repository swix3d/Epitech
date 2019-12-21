/*
** EPITECH PROJECT, 2019
** bubble sort
** File description:
** swap_elem
*/

#include <stdio.h>
#include <stdlib.h>

void swap_elem(int *array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}
