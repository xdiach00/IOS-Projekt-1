//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     Nikhail Diachenko <xdiach00@stud.fit.vutbr.cz>
// $Date:       $2022-03-06
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Mikhail Diachenko
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"


class MainMatrix:public::testing::Test
{
    protected:

        /**
         * @brief Creates a Matrix 1x1 with element 0
         * 
         * @return Matrix 
         */
        Matrix createUnitZeroMatrix()
        {
            Matrix matrix = Matrix();

            return matrix;
        }

        /**
         * @brief Creates a Matrix 4x4 with following elements:
         * 
         * {0, 1, 2, 3},
         * {2.2, 6, 1, -3},
         * {12, 43.241, 5, 89},
         * {32, 56.5, 34, 76.3432}
         * 
         * @return Matrix 
         */
        Matrix createSquareMatrix()
        { 
            Matrix matrix = Matrix(4, 4);
            matrix.set(std::vector<std::vector<double>> {
                {0, 1, 2, 3},
                {2.2, 6, 1, -3},
                {12, 43.241, 5, 89},
                {32, 56.5, 34, 76.3432},
            }); 

            return matrix;
        }

        /**
         * @brief Creates a Matrix 2x4 with following elemetns:
         * 
         * {0, 1, 2, 3},
         * {4, 5, 6, 7}
         * 
         * @return Matrix 
         */
        Matrix createHorizontalMatrix()
        {
            Matrix matrix = Matrix(2, 4);
            matrix.set(std::vector<std::vector<double>> {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
            });

            return matrix;
        }

        /**
         * @brief Create a Matrix 4x2 with following elements:
         * 
         * {0, 1},
         * {2, 3},
         * {4, 5},
         * {6, 7}
         * 
         * @return Matrix 
         */
        Matrix createVerticalMatrix()
        {
            Matrix matrix = Matrix(4, 2);
            matrix.set(std::vector<std::vector<double>> {
                {0, 1},
                {2, 3},
                {4, 5},
                {6, 7},
            });

            return matrix;
        }

};


TEST_F(MainMatrix, ConstructorTest)
{
    EXPECT_NO_THROW(Matrix());
    EXPECT_NO_THROW(Matrix(1, 1));
    EXPECT_NO_THROW(Matrix(5, 5));
    EXPECT_NO_THROW(Matrix(200, 13));
    EXPECT_NO_THROW(Matrix(999, 2523));
    
    EXPECT_ANY_THROW(Matrix(0, 0));
    EXPECT_ANY_THROW(Matrix(0, 1));
    EXPECT_ANY_THROW(Matrix(1, 0));
    EXPECT_ANY_THROW(Matrix(0, -10));
    EXPECT_ANY_THROW(Matrix(-10, 1));
    EXPECT_ANY_THROW(Matrix(250, 0));
}

TEST_F(MainMatrix, SetValueUnitZeroMatrix)
{
    Matrix matrix = createUnitZeroMatrix();

    EXPECT_TRUE(matrix.set(0, 0, 0));
    EXPECT_TRUE(matrix.set(0, 0, 1));
    EXPECT_TRUE(matrix.set(0, 0, 17));
    EXPECT_TRUE(matrix.set(0, 0, -228));
    EXPECT_TRUE(matrix.set(0, 0, 1234567));
    EXPECT_TRUE(matrix.set(0, 0, 478.664));
    EXPECT_TRUE(matrix.set(0, 0, -666.777));
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{1}}));
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{-1}}));
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{228.888}}));
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{1111}}));

    EXPECT_FALSE(matrix.set(1, 1, 1));
    EXPECT_FALSE(matrix.set(1, 2, 1));
    EXPECT_FALSE(matrix.set(1, 0, 1));
    EXPECT_FALSE(matrix.set(0, 1, 1));
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>> {'a'}));

}

TEST_F(MainMatrix, SetValuesUnitZeroMatrix)
{
    Matrix matrix = createUnitZeroMatrix();

    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{1}}));
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{-1}}));
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{228.888}}));
    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{1111}}));

    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>> {'a'}));

}

TEST_F(MainMatrix, GetValueUnitZeroMatrix)
{
    Matrix matrix = createUnitZeroMatrix();

    EXPECT_EQ(matrix.get(0, 0), 0);
}

TEST_F(MainMatrix, SetValueSquareMatrix)
{
    Matrix matrix = createSquareMatrix();

    EXPECT_TRUE(matrix.set(0, 1, 220));
    EXPECT_TRUE(matrix.set(1, 3, 0));
    EXPECT_TRUE(matrix.set(3, 2, -2));
    EXPECT_TRUE(matrix.set(2, 2, 13.4));

    EXPECT_FALSE(matrix.set(-1, 4, 3));
    EXPECT_FALSE(matrix.set(4, 4, 3));
    EXPECT_FALSE(matrix.set(3, 6, 3));
    
}

TEST_F(MainMatrix, SetValuesSquareMatrix)
{
    Matrix matrix = createSquareMatrix();

    EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {
        {4, 3, 2, 1},
        {5.2, 8, 1, -234},
        {32, 44.221, 52, 489},
        {322, 53.3, 334, 756.432},
    }));
    
    EXPECT_FALSE(matrix.set(std::vector<std::vector<double>> {
        {0, 1, 2, 3},
        {2.2, 6, 1, -3},
        {12, 43.241, 5, 89},
    }));

}

TEST_F(MainMatrix, GetValueSquareMatrix)
{
    Matrix matrix = createSquareMatrix();

    EXPECT_EQ(matrix.get(0, 0), 0);
    EXPECT_DOUBLE_EQ(matrix.get(2, 1), 43.241);
}

TEST_F(MainMatrix, OperatorEquals)
{
    Matrix matrixHorizontal = createHorizontalMatrix();
    Matrix matrixVertical = createVerticalMatrix();
    Matrix matrixSquare = createSquareMatrix();
    Matrix matrixSquareNew = matrixSquare;

    matrixSquareNew.set(1, 2, 1323);

    EXPECT_TRUE(matrixHorizontal == matrixHorizontal);
    EXPECT_TRUE(matrixVertical == matrixVertical);
    EXPECT_TRUE(matrixSquare == matrixSquare);

    EXPECT_FALSE(matrixSquare == matrixSquareNew);

    EXPECT_ANY_THROW(matrixHorizontal == matrixVertical);
    EXPECT_ANY_THROW(matrixVertical == matrixSquare);
}

TEST_F(MainMatrix, OperatorPlus)
{
    Matrix matrixHorizontal = createHorizontalMatrix();
    Matrix matrixVertical = createVerticalMatrix();
    Matrix matrixVerticalNew = matrixVertical;
    Matrix matrixResult1 = createHorizontalMatrix();
    Matrix matrixResult2 = createVerticalMatrix();

    matrixVerticalNew.set(1, 1, 123);
    matrixResult1.set(std::vector<std::vector<double>>{
        {0, 2, 4, 6},
        {8, 10, 12, 14},
    });
    matrixResult2.set(std::vector<std::vector<double>>{
        {0, 2},
        {4, 126},
        {8, 10},
        {12, 14},
    });

    EXPECT_ANY_THROW(matrixHorizontal + matrixVertical);

    EXPECT_EQ(matrixHorizontal + matrixHorizontal, matrixResult1);
    EXPECT_EQ(matrixVertical + matrixVerticalNew, matrixResult2);
}

TEST_F(MainMatrix, MultiplicationOperator)
{
    Matrix matrixVertical = createVerticalMatrix();
    Matrix matrixHorizontal = createHorizontalMatrix();
    Matrix matrixSquare = createSquareMatrix();
    Matrix matrixResult1 = matrixSquare;

    matrixResult1.set(std::vector<std::vector<double>>{
        {4, 5, 6, 7},
        {12, 17, 22, 27},
        {20, 29, 38, 47},
        {28, 41, 54, 67},
    });

    EXPECT_ANY_THROW(matrixSquare * matrixHorizontal);

    EXPECT_EQ(matrixVertical * matrixHorizontal, matrixResult1);
}

TEST_F(MainMatrix, MultiplicationConstOperator)
{
    Matrix matrixVertical = createVerticalMatrix();
    Matrix matrixUnitZero = createUnitZeroMatrix();
    Matrix matrixZero = Matrix(7, 7);
    Matrix matrixResult1 = matrixVertical;
    Matrix matrixResult2 = matrixVertical;


    matrixResult1.set(std::vector<std::vector<double>>{
        {0, 5},
        {10, 15},
        {20, 25},
        {30, 35},
    });
    matrixResult2.set(std::vector<std::vector<double>>{
        {0, -2.5},
        {-5, -7.5},
        {-10, -12.5},
        {-15, -17.5},
    });

    EXPECT_EQ(matrixVertical * 5, matrixResult1);
    EXPECT_EQ(matrixVertical * -2.5, matrixResult2);
    EXPECT_EQ(matrixUnitZero * 5, matrixUnitZero);
    EXPECT_EQ(matrixZero * 256.62, matrixZero);
}

TEST_F(MainMatrix, EquationMatrix)
{
    Matrix matrixFirst = Matrix(2, 2);
    Matrix matrixSecond = Matrix();
    Matrix matrixVertical = createVerticalMatrix();

    EXPECT_ANY_THROW(matrixVertical.solveEquation(std::vector<double> {22, 3, 4, 5}));


    /**
     * Solving of the following system of equations:
     * 
     * 4x - 2y = 22
     * 6x + y = 45
     * 
     */
    matrixFirst.set(std::vector<std::vector<double>> {
        {4, -2},
        {6, 1},
    });

    EXPECT_ANY_THROW(matrixFirst.solveEquation(std::vector<double> {22}));
    EXPECT_ANY_THROW(matrixFirst.solveEquation(std::vector<double> {}));

    EXPECT_EQ(matrixFirst.solveEquation(std::vector<double> {22, 45}), 
                                        (std::vector<double> {7, 3}));

    /**
     * Solving of the equation:
     * 
     * 12x = 24
     * 
     */
    matrixSecond.set(0, 0, 12);
    EXPECT_EQ(matrixSecond.solveEquation(std::vector<double> {24}), (std::vector<double>{2}));

}

TEST_F(MainMatrix, TransposeMatrix)
{
    Matrix matrixVertical = createVerticalMatrix();
    Matrix matrixVerticalTransposed = Matrix(2, 4);
    Matrix matrixSquare = createSquareMatrix();
    Matrix matrixSquareTransposed = Matrix(4, 4);

    matrixVerticalTransposed.set(std::vector<std::vector<double>> {
        {0, 2, 4, 6},
        {1, 3, 5, 7},
    });

    matrixSquareTransposed.set(std::vector<std::vector<double>> {
        {0, 2.2, 12, 32},
        {1, 6, 43.241, 56.5},
        {2, 1, 5, 34},
        {3, -3, 89, 76.3432},
    });

    EXPECT_TRUE(matrixVertical.transpose() == matrixVerticalTransposed);
    EXPECT_TRUE(matrixSquare.transpose() == matrixSquareTransposed);

    EXPECT_ANY_THROW(matrixVertical.transpose() == matrixVertical);
}

TEST_F(MainMatrix, InverseMatrix)
{
    Matrix matrixDouble = Matrix(2, 2);
    Matrix matrixQuadro = createSquareMatrix();
    Matrix matrixVertical = createVerticalMatrix();
    Matrix matrixTriple = Matrix(3, 3);
    Matrix matrixDoubleInversed = matrixDouble;
    Matrix matrixTripleInversed = matrixTriple;

    matrixDouble.set(std::vector<std::vector<double>> {
        {5, 1},
        {4, 1},
    });
    matrixDoubleInversed.set(std::vector<std::vector<double>> {
        {1, -1},
        {-4, 5},
    });

    matrixTriple.set(std::vector<std::vector<double>> {
        {2, 5, 7},
        {6, 3, 4},
        {5, -2, -3},
    });
    matrixTripleInversed.set(std::vector<std::vector<double>> {
        {1, -1, 1},
        {-38, 41, -34},
        {27, -29, 24},
    });

    EXPECT_ANY_THROW(matrixVertical.inverse());
    EXPECT_ANY_THROW(matrixQuadro.inverse());

    EXPECT_TRUE(matrixDouble.inverse() == matrixDoubleInversed);
    EXPECT_TRUE(matrixTriple.inverse() == matrixTripleInversed);
}

/*** Konec souboru white_box_tests.cpp ***/