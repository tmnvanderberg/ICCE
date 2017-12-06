// allocation could throw
#include "matrix.ih"

Matrix::Matrix(Matrix const &other)
try
:
    d_nRows(other.d_nRows),
    d_nCols(other.d_nCols),
    d_data(new double[size()])
{
    memcpy(d_data, other.d_data, size() * sizeof(double));
}
catch (...)
{
    // new is smart, do nothing
    throw;
}
