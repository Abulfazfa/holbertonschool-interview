#include<stdio.h>
#include "slide_line.h"

/**
 * Slide and merge an array of integers to the left or right.
 *
 * @param line      Pointer to an array of integers.
 * @param size      Number of elements in the array.
 * @param direction Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * @return 1 on success, 0 on failure.
 */

int slide_line(int *line, size_t size, int direction) {
    int i, j;

    if (line == NULL || (direction != SLIDE_RIGHT && direction != SLIDE_LEFT)) {
        return 0;
    }

    if (direction == SLIDE_LEFT) { 

        for (i = 0; i < (int)size; i++) {
            if (line[i] == 0) {
                for (j = i + 1; j < (int)size; j++) {
                    if (line[j] != 0) {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }

        for (i = 0; i < (int)size - 1; i++) {
            if (line[i] == line[i + 1]) {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }

        for (i = 0; i < (int)size; i++) {
            if (line[i] == 0) {
                for (j = i + 1; j < (int)size; j++) {
                    if (line[j] != 0) {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }

    } else if (direction == SLIDE_RIGHT) {
        for (i = (int)size - 1; i >= 0; i--) {
            if (line[i] == 0) {
                for (j = i - 1; j >= 0; j--) {
                    if (line[j] != 0) {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }

        for (i = (int)size - 1; i > 0; i--) {
            if (line[i] == line[i - 1]) {
                line[i] *= 2;
                line[i - 1] = 0;
            }
        }

        for (i = (int)size - 1; i >= 0; i--) {
            if (line[i] == 0) {
                for (j = i - 1; j >= 0; j--) {
                    if (line[j] != 0) {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
        }
    }

    return 1;
}
