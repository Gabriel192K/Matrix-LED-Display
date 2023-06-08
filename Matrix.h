#ifndef __MATRIX_H__
#define __MATRIX_H__

/* Dependencies */
#include "MAX7219/MAX7219.h"

class Matrix
{
    public:
        Matrix(MAX7219* max);
        ~Matrix();
        void begin         (void);
        void turnOn        (void);
        void turnOff       (void);
        void clear         (void);
        void write         (uint8_t x, uint8_t y, uint8_t state);
        void write         (uint8_t x, uint8_t data);
    private:
        MAX7219* max;
        uint8_t matrix[8];
        /*
        An 8x8 matrix using 8 - 8bit numbers
        Used by bit twiddling the 8 bytes 
          | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
        0 | x | x | x | x | x | x | x | x |
        1 | x | x | x | x | x | x | x | x |
        2 | x | x | x | x | x | x | x | x |
        3 | x | x | x | x | x | x | x | x |
        4 | x | x | x | x | x | x | x | x |
        5 | x | x | x | x | x | x | x | x |
        6 | x | x | x | x | x | x | x | x |
        7 | x | x | x | x | x | x | x | x |
        */
};

#endif
