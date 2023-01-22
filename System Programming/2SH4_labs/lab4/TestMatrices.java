package lab4_2sh4;

import java.util.Arrays;

public class TestMatrices {
    public static void main(String[] args)
    {
        //============================================================
        // Matrix
        //============================================================
        //------------------------------------------------------------
        // constructor
        //------------------------------------------------------------
        // test constructor1; invalid inputs
        Matrix a = new Matrix(-1, 2);
        System.out.println("Test constructor1--invalid inputs: (-1,2)");
        System.out.println(a.toString());
        System.out.println();
        System.out.println(a.getDim().toString());

        // test constructor1; invalid inputs
        Matrix b = new Matrix(1, 0);
        System.out.println("Test constructor1--invalid inputs: (1,0)");
        System.out.println(b.toString());
        System.out.println();

        // test constructor1; valid inputs
        Matrix d = new Matrix(3, 4);
        System.out.println("Test constructor1--valid inputs: (3,4)");
        System.out.println(d.toString());
        System.out.println();

        //test constructor2;
        int[][] temp = {{1, 1, 1, 1, 1}, {2, 2, 2, 8, 2}, {0, 0, 1, 7, 1}, {0, 0, 0, 1, 1}};
        Matrix f = new Matrix(temp);
        System.out.println("Test constructor2-- 4-by-5 array");
        System.out.println(f.toString());
        System.out.println();

        //------------------------------------------------------------
        //test getElement(); Indices begin with 0
        //------------------------------------------------------------
        try {
            System.out.println("Test getElement(1,3), Note that Indices begin with 0");
            System.out.println(f.getElement(1, 3));

            System.out.println("Test getElement(10,2), invalid indexes");
            System.out.println(f.getElement(10, 2));    // invalid indexes
        } catch (IndexOutOfBoundsException e) {
            System.out.println(e);
        }
        System.out.println();

                //------------------------------------------------------------
        //test subMatrix()
        //------------------------------------------------------------
        try {
            System.out.println("Test subMatrix(), valid inputs: (2,3)");
            Matrix y = f.subMatrix(2, 3);
            System.out.println(y.toString());
            System.out.println();

            System.out.println("Test subMatrix(), invalid inputs: (3,6)");
            System.out.println(f.subMatrix(3, 6));
        } catch (ArithmeticException e) {
            System.out.println(e);
            System.out.println();
        }

        //------------------------------------------------------------
        //test isUpperTr()
        //------------------------------------------------------------
        System.out.println("Test isUpperTr(), return true");
        int[][] temp1 = {{1, 2, 3, 4}, {0, 5, 6, 7}, {0, 0, 8, 0}};
        Matrix v = new Matrix(temp1);
        System.out.println(v.toString());
        System.out.println(v.isUpperTr());
        System.out.println();

        System.out.println("Test isUpperTr(), return false");
        int[][] temp2 = {{2, 0, 0, 0}, {0, 9, 6, 8}, {5, 0, 4, 4}, {0, 0, 0, 9}};
        Matrix n = new Matrix(temp2);
        System.out.println(n.toString());
        System.out.println(n.isUpperTr());
        System.out.println();

        int[][] temp3 = {{2, 0, 0, 0, 4}, {0, 2, 1, 1, 4}, {0, 0, 2, 1, 4}, {0, 0, 0, 2, 6}};
        Matrix p = new Matrix(temp3);
        System.out.println(p.toString());


        //------------------------------------------------------------
        // test addTo()
        //------------------------------------------------------------
        System.out.println("Test addTo() -- invalid operation");
        int[][] temp4 = {{3, 4, 5}, {1, 2, 3}, {0, 0, 0}, {1, 2, 1}};
        Matrix m = new Matrix(temp4);
        try {
            m.addTo(p);
            System.out.println(m);
        } catch (ArithmeticException e) {
            System.out.println(e);
            System.out.println();
        }

        System.out.println("Test addTo() -- valid operation");
        int[][] temp5 = {{0, 0, 0}, {1, 2, 3}, {0, 0, 0}, {1, 2, 1}};
        Matrix m1 = new Matrix(temp5);
        try {
            m.addTo(m1);
            System.out.println(m);
        } catch (ArithmeticException e) {
            System.out.println(e);
            System.out.println();
        }

        //------------------------------------------------------------
        // test sum()
        //------------------------------------------------------------
        System.out.println("Test sum() -- invalid operation");
        Matrix[] arr = new Matrix[4];
        for (int i = 0; i < 4; i++)
            arr[i] = new Matrix(2, 3);
        arr[2] = new Matrix(3, 3);
        try {
            System.out.println(Matrix.sum(arr).toString());
        } catch (ArithmeticException e) {
            System.out.println(e);
            System.out.println();
        }

        System.out.println("Test sum() -- valid operation");
        Matrix[] arr2 = new Matrix[3];
        int[][] temp10 = {{1, -1, 2}, {1, 0, -2}};
        int[][] temp11 = {{1, 0, 1}, {0, 1, 2}};
        arr2[0] = new Matrix(temp10);
        arr2[1] = new Matrix(temp10);
        arr2[2] = new Matrix(temp11);
        try {
            System.out.println(Matrix.sum(arr2).toString());
        } catch (ArithmeticException e) {
            System.out.println(e);
            System.out.println();
        }

        //============================================================
        //test class UpperTriangularMatrix
        //============================================================
        //------------------------------------------------------------
        // constructor
        //------------------------------------------------------------
        // test constructor1; invalid input
        UpperTriangularMatrix m11 = new UpperTriangularMatrix(-3);  // m1
        System.out.println("Test costructor1--invalid input");
        System.out.println(m11.toString());

        // test constructor1; valid input
        UpperTriangularMatrix m2 = new UpperTriangularMatrix(4);
        System.out.println("Test costructor1--valid input");
        System.out.println(m2.toString());
        m2.print1DArray();
        System.out.println();

        //test constructor2 - valid input;
        UpperTriangularMatrix m3 = null, m4;
        int[][] temp12 = {{1, 1, 1, 1, 1}, {0, 2, 2, 2, 2}, {0, 0, 3, 3, 3}, {0, 0, 0, 4, 4}, {0, 0, 0, 0, 5}};
        Matrix mm1 = new Matrix(temp12);
        try {
            m3 = new UpperTriangularMatrix(mm1);
            System.out.println("\nTest costructor2");
            System.out.println(m3.toString());
            m3.print1DArray();

            //test constructor2 - invalid input;
            int[][] temp13 = {{9, 0, 0}, {8, 7, 0,}, {6, 5, 4}};
            mm1 = new Matrix(temp13);
            System.out.println("\nTest costructor2");

            m4 = new UpperTriangularMatrix(mm1); // temp13
            System.out.println(m4.toString());
            m4.print1DArray();
        } catch (IllegalArgumentException e) {
            System.out.println(e);
            System.out.println();
        }// end try-catch

        int[][] temp15 = {{1, 2, 3, 4, 5, 6}, {0, 7, 8, 9, 9, 9}, {0, 0, 3, 3, 3, 3}, {0, 0, 0, 4, 4, 4}, {0, 0, 0, 0,5, 5}, {0, 0, 0, 0, 0, 7}};
        mm1 = new Matrix(temp15);
        m4 = new UpperTriangularMatrix(mm1);

        //------------------------------------------------------------
        //test getDim()
        //------------------------------------------------------------
        System.out.println("\n\nTest getDim()");
        System.out.println(m3.getDim());
        System.out.println(m4.getDim());
        System.out.println();

        //------------------------------------------------------------
        //test getElement()
        //------------------------------------------------------------
        try {
            System.out.println("Test getElement() - valid positions");
            for (int i = 0; i < m3.getDim(); i++) {
                for (int j = 0; j < m3.getDim(); j++)
                    System.out.print(m3.getElement(i, j) + "  ");
                System.out.println();
            }// end for i
            System.out.println();

            System.out.println("Test getElement() - invalid position ");
            System.out.println(m3.getElement(6, 4));    // invalid indexes
        } catch (IndexOutOfBoundsException e) {
            System.out.println(e);
        }
        System.out.println();

        //------------------------------------------------------------
        //test setElement()
        //------------------------------------------------------------
        try {
            System.out.println("Test setElement() - valid positions");
            m3.setElement(7, 1, 3);
            System.out.print(m3);
            System.out.println();
            m4.setElement(9, 4, 4);
            System.out.print(m4);

            System.out.println("Test setElement() - invalid position ");
            m3.setElement(-1, 4, 7);
            System.out.print(m3);    // invalid indexes

        } catch (IndexOutOfBoundsException e) {
            System.out.println(e);
        } catch (IllegalArgumentException e) {
            System.out.println(e);
            System.out.println("Pay attention! This is an upper triangular matrix!");
        }
        System.out.println();

        try {
            System.out.println("Test setElement() - attempt to put a non-zero value in the lower part ");
            m3.setElement(-2, 3, 0);
            System.out.print(m3);    // invalid argument
        } catch (IndexOutOfBoundsException e) {
            System.out.println(e);
        } catch (IllegalArgumentException e) {
            System.out.println(e);
            System.out.println("Pay attention! This is an upper triangular matrix!");
        }
        System.out.println();

        //------------------------------------------------------------
        //test fullMatrix()
        //------------------------------------------------------------
        System.out.println("Test fullMatrix()");
        mm1 = new Matrix(temp12);
        m3 = new UpperTriangularMatrix(mm1);
        System.out.print(m3.fullMatrix().toString());
        System.out.println();

        int[][] temp14 = {{9, 9, 9}, {0, 8, 8}, {0, 0, 7}};
        mm1 = new Matrix(temp14);
        m4 = new UpperTriangularMatrix(mm1);
        System.out.print(m4.fullMatrix().toString());
        System.out.println();

        //------------------------------------------------------------
        // test getDet()
        //------------------------------------------------------------
        System.out.println("Test m4.getDet() -- valid operation");
        try {
            System.out.println(m4.getDet() + "\n");
        } catch (ArithmeticException e) {
            System.out.println(e);
            System.out.println();
        }

        //------------------------------------------------------------
        // test effSolve()
        //------------------------------------------------------------
        System.out.println("Test effSolve() -- invalid operation");
        double[] bb1 = {2, 3, 4, 5};
        try {
            System.out.println(Arrays.toString(m4.effSolve(bb1)) + "\n");
        } catch (IllegalArgumentException e) {
            System.out.println(e);
            System.out.println();
        }

        System.out.println("Test effSolve() -- valid operation");
        double[] bb2 = {2, 3, 4};
        try {
            System.out.println(Arrays.toString(m4.effSolve(bb2)) + "\n");
        } catch (IllegalArgumentException e) {
            System.out.println(e);
            System.out.println();
        }

        System.out.println("Test effSolve() -- invalid operation");
        m4.setElement(0, 0, 0);
        try {
            System.out.println(Arrays.toString(m4.effSolve(bb2)) + "\n");
        } catch (IllegalArgumentException e) {
            System.out.println(e);
            System.out.println();
        }

        
        
        Matrix newmat1 = new Matrix(2, 3);
        // int[][] newnewarr1 = new int[0][0];
        // newnewarr1[0] = {1,1,1};
        //cannot pass newnewarray by value
        // Matrix newmat2 = new Matrix(int[][] newnewarr2 = {{1,2,3}, {1,2,3}, {1,2,3}});
        int[][] newnewarr2 = {{1,2,3}, {1,2,3}, {1,2,3}};
        int[][] newnewarr3 = {{1,1,1}, {1,1,1}, {1,1,1}};
        Matrix newmat2 = new Matrix(newnewarr2);
        System.out.println(newmat2.getElement(0, 1));
        newmat2.setElement(532, 2, 2);
        newmat2.printMatrix(newmat2);
        newmat2.printMatrix();
        Matrix newmat3 = newmat2.copy();
        newmat2.setElement(69, 2, 2);
        newmat2.printMatrix();
        newmat3.printMatrix();
        Matrix newmat4 = new Matrix(newnewarr3);
        newmat2.printMatrix();
        newmat2.addTo(newmat4);
        System.out.println("newmat2 is");
        newmat2.printMatrix();
        System.out.println("Creating a subMatrix");
        Matrix newmat5 = newmat2.subMatrix(2, 2);
        System.out.println("newmat5 is");
        newmat5.printMatrix();
        int[][] newnewarr4 = {{1,4,1}, {0,9,0}, {0,0,3}};
        int[][] newnewarr5 = {{1,5,1,4}, {0,9,6,6}, {0,0,3,8}};
        int[][] newnewarr6 = {{1,4,2}, {0,9,6}, {0,0,3}, {0,0,0}};
        Matrix newmat6 = new Matrix(newnewarr4);
        Matrix newmat7 = new Matrix(newnewarr5);
        Matrix newmat8 = new Matrix(newnewarr6);
        newmat6.isUpperTr();
        newmat7.isUpperTr();
        newmat8.isUpperTr();
        newmat5.printMatrix();
        System.out.println(newmat4.toString());
        int[][] newnewarr7 = {{1,1,1}, {1,1,1}, {1,1,1}, {1,1,1}};
        int[][] newnewarr8 = {{1,1,1}, {1,1,1}, {1,1,1}, {1,1,1}};
        int[][] newnewarr9 = {{1,1,1}, {1,1,1}, {1,1,1}, {1,1,1}};
        int[][] newnewarr10 = {{1,1,1}, {1,1,1}, {1,1,1}, {1,1,1}};
        int[][] newnewarr11 = {{1,1,1}, {1,1,1}, {1,1,1}, {1,1,1}};
        Matrix newmat9 = new Matrix(newnewarr7);
        Matrix newmat10 = new Matrix(newnewarr8);
        Matrix newmat11 = new Matrix(newnewarr9);
        Matrix newmat12 = new Matrix(newnewarr10);
        Matrix newmat13 = new Matrix(newnewarr11);
        Matrix[] newmatList = {newmat9, newmat10, newmat11, newmat12, newmat13};
        Matrix sumMatrix = new Matrix(newmat9.getDim()[0], newmat9.getDim()[1]);
        
        System.out.println("Moshiur");
        System.out.println(Matrix.sum(newmatList).toString());
        sumMatrix.toString();
        // sumMatrix.printMatrix();

        // System.out.println(mat2.getElement(-1, 1));
        // System.out.println(mat2.getElement(10, 10));
         

        // UpperTriangularMatrix upp1 = new UpperTriangularMatrix(3);
        // System.out.println(upp1.toString());
        int[][] arr4 = {{1,4,1}, {0,9,0}, {0,0,3}};
        int[][] arr5 = {{1,5,1,4}, {0,9,6,6}, {0,0,3,8}};
        int[][] arr6 = {{1,4,2}, {0,9,6}, {0,0,3}, {0,0,0}};
        Matrix mat6 = new Matrix(arr4);
        Matrix mat7 = new Matrix(arr5);
        Matrix mat8 = new Matrix(arr6);
        System.out.println("Result of mat6.isUpperTr(): "+mat6.isUpperTr());
        System.out.println("Result of mat7.isUpperTr(): "+mat7.isUpperTr());
        System.out.println("Result of mat8.isUpperTr(): "+mat8.isUpperTr());
        UpperTriangularMatrix upp2 = new UpperTriangularMatrix(mat6);
        upp2.print1DArray();
        System.out.println(upp2.getElement(0, 0));
        System.out.println(upp2.getElement(0, 1));
        System.out.println(upp2.getElement(0, 2));
        System.out.println(upp2.getElement(1, 1));
        System.out.println(upp2.getElement(1, 2));
        System.out.println(upp2.getElement(2, 2));
        upp2.setElement(69, 2, 2);
        System.out.println(upp2.getElement(2, 2));
        System.out.println(upp2.toString());
        Matrix newMat2 = upp2.fullMatrix();
        System.out.println(newMat2.toString());

        //upp2*x = B
        /* Matlab syntax:
         * A = [1 4 1; 0 9 0; 0 0 69]
         * B=[3; 3; 6]
         * x = A\B
         * A=[1 2 3 4; 0 5 6 7; 0 0 8 9; 0 0 0 10]
         * B=[3; 3; 6; 6]
         * x= a\B
         */
        double[] b_RHS1 = {3.0, 3.0, 6.0};
        double[] x_solve1 = upp2.effSolve(b_RHS1);
        System.out.println("Actual answer: ");
        for (int i = 0; i < x_solve1.length; i++) {
            System.out.print(x_solve1[i]+"  ");
        }
        System.out.println("Expected answer: ");
        System.out.println("1.579710 0.333333 0.086957");

        System.out.println();
        System.out.println("***********************");
        int[][] arr10 = {{1, 2, 3, 4}, {0,5,6,7}, {0,0,8,9},{0,0,0,10}};
        Matrix mat10 = new Matrix(arr10);
        System.out.println(mat10.toString());
        UpperTriangularMatrix upp10 = new UpperTriangularMatrix(mat10);
        double[] b_RHS2 = {3.0, 3.0, 6.0, 6.0};
        double[] x_solve2 = upp10.effSolve(b_RHS2);
        System.out.println("Actual answer: ");
        for (int i = 0; i < x_solve2.length; i++) {
            System.out.print(x_solve2[i]+"  ");
        }
        System.out.println("\nExpected answer: ");
        System.out.println("1.035000 -0.330000 0.075000 0.600000");
        System.out.println();
        System.out.println("***********************");
        int[][] arr11 = {{0, 2, 3, 4}, {0,5,6,7}, {0,0,8,9},{0,0,0,10}};
        Matrix mat11 = new Matrix(arr11);
        System.out.println(mat11.toString());
        System.out.println("test case 40");
        UpperTriangularMatrix upp11 = new UpperTriangularMatrix(mat11);
        double[] b_RHS3 = {3.0, 3.0, 6.0, 6.0};
        try {
            double[] x_solve3 = upp11.effSolve(b_RHS3);
        } catch (Exception e) {
            System.out.println(e);
        }

        UpperTriangularMatrix upp5 = new UpperTriangularMatrix(-1);
        upp5.print1DArray();
        System.out.println(upp5.getDim());
        System.out.println(upp5.getElement(0, 0));
        try {
            System.out.println(upp5.getElement(-4, -6));
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println(upp5.fullMatrix().toString());
        System.out.println(upp11.fullMatrix().toString());

        try {
            upp11.setElement(6934, -4, -4);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
