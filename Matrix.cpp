#include "Matrix.h"

/*********************************************
Function: Matrix()
Purpose:  Constructor to Matrix class
Input:    Reference to MAX7219 class
Return:   None
*********************************************/
Matrix::Matrix(MAX7219* max)
{
    this->max = max;
}

/*********************************************
Function: ~Matrix()
Purpose:  Destructor to Matrix class
Input:    None
Return:   None
*********************************************/
Matrix::~Matrix()
{
    this->max = NULL;
}

/*****************************************
Function: begin()
Purpose:  Initialize the Matrix
Input:    None
Return:   None
*****************************************/
void Matrix::begin(void)
{
    this->max->begin();             /* Initialize MAX */
    this->max->setDecodeMode(0x00); /* Set MAX to not decode any data (more suitable for a matrix) */
    this->clear();                  /* Clear the matrix */
    this->turnOn();                 /* Turn on the matrix */
}

/*****************************************
Function: turnOn()
Purpose:  Turn on the Matrix
Input:    None
Return:   None
*****************************************/
void Matrix::turnOn(void)
{
    this->max->turnOn();
}

/*****************************************
Function: turnOff()
Purpose:  Turn off the Matrix
Input:    None
Return:   None
*****************************************/
void Matrix::turnOff(void)
{
    this->max->turnOff();
}

/*****************************************
Function: clear()
Purpose:  Clear the Matrix
Input:    None
Return:   None
*****************************************/
void Matrix::clear(void)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        matrix[i] = 0;
        this->max->write(i + 1, matrix[i]);
    }
}

/*****************************************
Function: write()
Purpose:  Set state of an element of the matrix
Input:    Matrix element's coordonates and its state
Return:   None
*****************************************/
void Matrix::write(uint8_t x, uint8_t y, uint8_t state)
{
    switch (state)
    {
        case LOW:
            matrix[x] &= ~(1 << y);
        break;
        case HIGH:
            matrix[x] |= (1 << y);
        break;
        case TOGGLE:
            matrix[x] ^= (1 << y);
        break;
        default:
        break;
    }
    this->max->write(x + 1, matrix[x]); /* Add 1 because in MAX7219's memory the digit's registers start from 1 not from 0 */
                                        /* Also we write and entire digit register at once */
}

/*****************************************
Function: write()
Purpose:  Set state of an entire row of the matrix
Input:    Matrix row and data associated with it
Return:   None
*****************************************/
void Matrix::write(uint8_t x, uint8_t data)
{
    matrix[x] = data;
    this->max->write(x + 1, matrix[x]); /* Add 1 because in MAX7219's memory the digit's registers start from 1 not from 0 */
                                        /* Also we write and entire digit register at once */
}
