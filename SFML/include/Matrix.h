/**
 @file Matrix.h
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

/*! \class Matrix
 \brief A 2D matrix template
 */

template <class N> class Matrix
{
private:
	std::vector<std::vector<N>> m_Matrix; //!< 2D matrix (vector of vectors)
public:
	Matrix<N>(){}; //!< Default constructor
	Matrix<N>(const unsigned int kuiSize /*!< Size of the rows and columns*/){setSize(kuiSize, kuiSize);}; //!< Constructor which takes an unsigned integer which sets the size of the N and M axies
    Matrix<N>(const unsigned int kuiRowSize /*!< Number of rows*/, const unsigned int kuiColumnSize /*!< Number of columns*/){setSize(kuiRowSize,kuiColumnSize);}; //!< Constructor which takes two unsigned integers which sets the size of the N and M axies
    
	N getNum(const unsigned int kuiRow /*!< Row number*/, const unsigned int kuiColumn /*!< Column number*/)const {return m_Matrix[kuiRow-1][kuiColumn-1];}; //!< Returns the value at a position

    void setNum(N number /*!< Number value */, const unsigned int kuiRow /*!< Row number*/, const unsigned int kuiColumn /*!< Column Number*/)
    {
        if (kuiRow <= getRowSize() && kuiColumn <= getColumnSize())
            m_Matrix[kuiRow-1][kuiColumn-1] = number;
    };  //!< Sets the value at a position

	unsigned long getRowSize()const {return m_Matrix.size();};//!< Returns the size of the rows
	unsigned long getColumnSize()const {return m_Matrix[0].size();}; //!< Returns the size of the columns

	void setSize(const unsigned int kuiRowSize /*!< Row Size*/, const unsigned int kuiColumnSize/*Column Size*/) 
    {
		m_Matrix.resize(kuiRowSize);
		for (unsigned int i = 0; i < getRowSize(); ++i) {
			m_Matrix[i].resize(kuiColumnSize);
		}
	}; //!< Sets the size of the matrix
    
    Matrix<N>& identityMatrix() 
    {
        for (unsigned int m = 0; m < getRowSize(); m++) {
            for (unsigned int n = 0; n <getColumnSize(); n++)
            {
                if (n == m)
                    m_Matrix[m][n] = 1;
                else
                    m_Matrix[m][n] = 0;
            }
        }
        return *this;
    }; //!< Sets the matrix to the identity matrix
    
	Matrix<N> operator+ (const Matrix<N>* kpOther /*!< Other matrix*/) const; //!< Returns the current matrix plus another matrix
	Matrix<N> operator- (const Matrix<N>* kpOther /*!< Other matrix*/) const;  //!< Returns the current matrix minus another matrix
    Matrix<N> operator* (const Matrix<N>* kpOther /*!< Other matrix*/) const;  //!< Returns the current matrix multiplied by another matrix
    Matrix<N> operator* (const float kfScalar /*!< Scalar value */) const;  //!< Returns the current matrix multiplied by a scalar
	Matrix<N>& operator= (const Matrix* kpOther /*!< Matrix assignment value */); //!< Assignment operator
};

template <class N>
Matrix<N> Matrix<N>::operator+ (const Matrix* kpOther /*!<Other matrix*/) const //!< Returns the current matrix plus another matrix
{
		Matrix newMatrix;
		if (getRowSize() == kpOther->getRowSize() && getColumnSize() == kpOther->getColumnSize())
		{
			newMatrix.setSize(getRowSize(), getColumnSize());
			for (int y = 1; y <= getColumnSize(); y++)
			{
				for (int x = 1; x <= getRowSize(); x++)
				{
					newMatrix.setNum(getNum(x, y) + kpOther->getNum(x,y), x, y);
				}
			}
		}
		return newMatrix;
}

template <class N>
Matrix<N> Matrix<N>::operator- (const Matrix* kpOther /*!<Other matrix*/) const //!< Returns the current matrix minus another matrix
{
		Matrix newMatrix;
		if (getRowSize() == kpOther->getRowSize() && getColumnSize() == kpOther->getColumnSize())
		{
			newMatrix.setSize(getRowSize(), getColumnSize());
			for (int y = 1; y <= getColumnSize(); y++)
			{
				for (int x = 1; x <= getRowSize(); x++)
				{
					newMatrix.setNum(getNum(x, y) - kpOther->getNum(x,y), x, y);
				}
			}
		}
		return newMatrix;
}

template <class N>
Matrix<N> Matrix<N>::operator* (const Matrix* kpOther/* !<Other matrix*/) const //!< Returns the current matrix multiplied by another matrix
{
    Matrix newMatrix;
    if (getRowSize() == kpOther->getRowSize() && getColumnSize() == kpOther->getColumnSize())
    {
        newMatrix.setSize(getRowSize(), getColumnSize());
        for (int y = 1; y <= getColumnSize(); y++)
        {
            for (int x = 1; x <= getRowSize(); x++)
            {
                newMatrix.setNum(getNum(x, y) * kpOther->getNum(x,y), x, y);
            }
        }
    }
    return newMatrix;
}

template <class N>
Matrix<N> Matrix<N>::operator* (const float kfScalar /*!< Scalar value */) const  //!< Returns the current matrix multiplied by a scalar
{
    Matrix newMatrix;
    newMatrix.setSize(getRowSize(), getColumnSize());
    for (int y = 1; y <= getColumnSize(); y++)
    {
        for (int x = 1; x <= getRowSize(); x++)
        {
            newMatrix.setNum(getNum(x, y) * kfScalar, x, y);
        }
    }
    return newMatrix;
}

template <class N>
Matrix<N>& Matrix<N>::operator= (const Matrix* kpOther /*!< Matrix assignment value */) //!< Assignment operator
{
		setSize(kpOther->getRowSize(), kpOther->getColumnSize());
		for (int y = 1; y <= getColumnSize(); y++)
		{
			for (int x = 1; x <= getRowSize(); x++)
			{
                setNum(kpOther->getNum(x,y), x, y);
			}
		}
}

#endif