package lab4_2sh4;

import java.util.Arrays;

public class Matrix {
    private int rows;
    private int cols;
    private int matrixData[][];

    public Matrix(int row, int col){
        this.rows = row;
        this.cols = col;
        // System.out.println("row is: "+this.rows+" and col is: "+this.cols);
        if(row<=0){
            this.rows = 3;
        }
        if(col<=0){
            this.cols = 3;
        }
        //allocate memory for matrixData (2-d array)

        matrixData = new int[this.rows][this.cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrixData[i][j]=0;
                // System.out.println("MatrixData is: "+matrixData[i][j]+"\n");
            }
        }
        // System.out.println("MatrixData is: "+Arrays.deepToString(this.matrixData)+"\n");
    }

    public Matrix(int[][] table){
        if(table==null){
            throw new NullPointerException("Null value passed!");
        }
        if(table.length<=0){
            throw new ArrayIndexOutOfBoundsException("Matrix row length is 0!");
        }
        if(table[0].length<=0){
            throw new ArrayIndexOutOfBoundsException("Matrix column length is 0!");
        }
        // System.out.println("MatrixData Row Size is: "+table.length+"\n");
        // System.out.println("MatrixData Row Size is: "+table[0].length+"\n");
        this.rows = table.length;
        this.cols = table[0].length;
        this.matrixData = new int[this.rows][this.cols];
        for (int i = 0; i < table.length; i++) {
            for (int j = 0; j < table[0].length; j++) {
                this.matrixData[i][j] = table[i][j];
            }
        }
        // System.out.println("MatrixData is: "+Arrays.deepToString(this.matrixData)+"\n");
    }

    public int getElement(int i, int j) throws IndexOutOfBoundsException{
        if(i < 0 || i >= this.rows){
            throw new IndexOutOfBoundsException("Invalid indexs");
        }

        if(j < 0 || j >= this.cols){
            throw new IndexOutOfBoundsException("Invalid indexs");
        }
       
        return this.matrixData[i][j];
    }

    public boolean setElement(int x, int i, int j) {
        if(this.rows < i || i > this.rows){
            return false;
        }

        if(this.cols < j || j > this.cols){
            return false;
        }

        this.matrixData[i][j] = x;
       
        return true;
    }

    public Matrix copy(){
        Matrix copy = new Matrix(this.matrixData);
        return copy;
        // return new Matrix(this.matrixData);

    }

    public void addTo(Matrix m) throws ArithmeticException{
        if(m.cols != this.cols && m.rows != this.rows){
            throw new ArithmeticException("Invalid Operation");
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this.matrixData[i][j] = this.matrixData[i][j] + m.matrixData[i][j];
            }
        }
    }

    public Matrix subMatrix(int i, int j) throws ArithmeticException{
        if(i > this.rows || j > this.cols || i<0 || j<0){
            throw new ArithmeticException("Submatrix not defined.");
        }

        Matrix subMatrix = new Matrix(i, j);

        for (int x = 0; x < i; x++) {
            for (int y = 0; y < j; y++) {
                subMatrix.matrixData[x][y] = this.matrixData[x][y];
            }
        }

        return subMatrix;
    }

    public boolean isUpperTr(){
        boolean result = false;
        int counter = 0;

        for (int i = 0; i < this.matrixData.length; i++) {
            for (int j = 0; j < this.matrixData.length; j++) {
                if(i>j){
                    counter += this.matrixData[i][j];
                }
            }
        }

        if(counter==0){
            result = true;
        }

        // System.out.println("Result of isUpperTr() is: "+result);

        return result;
    }

    public static Matrix sum(Matrix[] matArray) throws ArithmeticException{
        if(matArray.length<1){
            throw new ArithmeticException("The list must have at least 2 matrix!");
        }

        if(matArray.length==1){
            Matrix result = new Matrix(matArray[0].matrixData);
            return result;
        }

        int rows = matArray[0].rows;
        int cols = matArray[0].cols;

        for (int i = 0; i < matArray.length; i++) {
            //not all matrix has equal dimensions
            if(matArray[i].rows!= rows || matArray[i].cols!= cols){
                throw new ArithmeticException("Not all the matrix have the same dimensions!");
            }
        }

        Matrix sumMatrix = new Matrix(rows, cols);

        for (int i = 0; i < matArray.length; i++) {
            sumMatrix.addTo(matArray[i]);
        }

        return sumMatrix;
    }

    @Override
    public String toString(){

        String result="";
        for (int i = 0; i < this.matrixData.length; i++) {
            for (int j = 0; j < this.matrixData[0].length; j++) {
                if(j<this.matrixData[0].length-1){
                    result = result+this.matrixData[i][j]+"  ";
                }else{
                    result = result+this.matrixData[i][j]+"\n";
                }
            }
        }
        return result;
    }

    public int[] getDim(){
        int[] dim = new int[2];

        dim[0] = this.rows;
        dim[1] = this.cols;

        return dim;
    }

    public void printMatrix(Matrix mat){
        System.out.println(Arrays.deepToString(mat.matrixData));
    }

    public void printMatrix(){
        System.out.println(Arrays.deepToString(this.matrixData));
    }

}
