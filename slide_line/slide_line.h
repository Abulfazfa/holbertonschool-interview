#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT -5
#define SLIDE_RIGHT 5

int slide_line(int *line, size_t size, int direction);

#endif