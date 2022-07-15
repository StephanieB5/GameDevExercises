#include "Matrix.h"

void Matrix::clearToZero()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            elements[i][j] = 0.f;
        }
    }
}

void Matrix::VectorMultiply(Vector4F const& inVector, Vector4F& result) const
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            result.elements[i] = result.elements[i] + elements[i][j] * inVector.elements[j];
        }
    }
}

void Matrix::Multiply(Matrix const& inMatrix, Matrix& result) const
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            for (int k = 0; k < size; k++) 
            {
                result.elements[i][k] = result.elements[i][k] + elements[i][j] * inMatrix.elements[j][k];
            }
        }
    }
}


