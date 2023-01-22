package lab4_2sh4;

public class UpperTriangularMatrix {
    // this class will only represent NxN matrix only
    private int matrixSizeN;
    private int matrixData[]; // must be N*(N+1)/2

    public UpperTriangularMatrix(int n) {
        if (n <= 0) {
            n = 1;
            this.matrixSizeN = n;
            this.matrixData = new int[n * (n + 1) / 2];
        } else {
            this.matrixSizeN = n;
            this.matrixData = new int[n * (n + 1) / 2]; // defaults all value to 0
        }
    }

    public UpperTriangularMatrix(Matrix upperTriMatrix) throws IllegalArgumentException {
        int counter = 0;

        if (upperTriMatrix.isUpperTr() == false) {
            throw new IllegalArgumentException("Supplied matrix is not an upper triangular matrix!");
        }
        if (upperTriMatrix.getDim()[0] != upperTriMatrix.getDim()[1]) {
            throw new IllegalArgumentException("Supplied matrix is not an NxN matrix!");
        }

        this.matrixSizeN = upperTriMatrix.getDim()[0];
        this.matrixData = new int[this.matrixSizeN * (this.matrixSizeN + 1) / 2];

        for (int i = 0; i < upperTriMatrix.getDim()[0]; i++) {
            for (int j = 0; j < upperTriMatrix.getDim()[1]; j++) {
                // get all elements from main diagonal and up, in order
                if (i <= j) {
                    this.matrixData[counter] = upperTriMatrix.getElement(i, j);
                    counter++;
                }
            }
        }
    }

    public int getDim() {
        return this.matrixSizeN;
    }

    public int getElement(int i, int j) throws IndexOutOfBoundsException {

        if (i < 0 || i >= this.matrixSizeN) {
            throw new IndexOutOfBoundsException("Invalid indexs");
        }

        if (j < 0 || j >= this.matrixSizeN) {
            throw new IndexOutOfBoundsException("Invalid indexs");
        }

        if (i > j) {
            return 0;
        } else {
            // N, N-1, N-2 ... 2, 1 entries as we go from row 0th to row Nths
            // what is the math formula to convert between 2d to 1d array?
            // found it:
            // https://jamesmccaffrey.wordpress.com/2010/05/14/converting-a-triangular-matrix-to-an-array/
            // i = (n * x) + y – ((x * (x+1)) / 2)
            int arrayIndex = (this.matrixSizeN * i) + j - ((i * (i + 1)) / 2);
            return this.matrixData[arrayIndex];
        }
    }

    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException {
        if (i < 0 || i >= this.matrixSizeN) {
            throw new IndexOutOfBoundsException("Invalid indexs");
        }

        if (j < 0 || j >= this.matrixSizeN) {
            throw new IndexOutOfBoundsException("Invalid indexs");
        }

        if (i > j && x != 0) {
            throw new IllegalArgumentException("Invalid indexs");
        }

        int arrayIndex = (this.matrixSizeN * i) + j - ((i * (i + 1)) / 2);
        if (i > j) {
            this.matrixData[arrayIndex] = x;    //setting it to 0 btw
        } else {
            // https://jamesmccaffrey.wordpress.com/2010/05/14/converting-a-triangular-matrix-to-an-array/
            // i = (n * x) + y – ((x * (x+1)) / 2)
            this.matrixData[arrayIndex] = x;
        }

    }

    public Matrix fullMatrix() {
        int counter = 0;
        int[][] recreateArr = new int[this.matrixSizeN][this.matrixSizeN];

        for (int i = 0; i < this.matrixSizeN; i++) {
            for (int j = 0; j < this.matrixSizeN; j++) {
                if (i <= j) {
                    recreateArr[i][j] = this.matrixData[counter];
                    counter++;
                } else {
                    // i>j
                    recreateArr[i][j] = 0;
                }
            }
        }

        return new Matrix(recreateArr);
    }

    public void print1DArray() {
        String result = "";
        for (int i = 0; i < this.matrixData.length; i++) {
            result += this.matrixData[i] + "  ";
        }
        System.out.println(result);
    }

    @Override
    public String toString() {
        int counter = 0;
        String result = "";

        for (int i = 0; i < this.matrixSizeN; i++) {
            for (int j = 0; j < this.matrixSizeN; j++) {
                if (i <= j) {
                    result += this.matrixData[counter] + "  ";
                    counter++;
                } else {
                    // i>j
                    result += "0" + "  ";
                }
            }
            result += "\n";
        }
        return result;
    }

    public int getDet() {
        int result = 1;

        for (int i = 0; i < this.matrixSizeN; i++) {
            result *= this.getElement(i, i);
        }
        return result;
    }

    public double[] effSolve(double[] b) throws IllegalArgumentException {
        // only programming friendly approach (bottom up)
        // need to implement https://algowiki-project.org/en/Backward_substitution
        //  validate matrix solver with: https://octave-online.net/

        if(b.length!=this.matrixSizeN){
            throw new IllegalArgumentException("The dimension of B must match dimension N!");
        }

        //I think invoking this method vs rewriting the entire thing again makes no difference
        //even with the "specification"/requirement
        if(this.getDet()==0){
            throw new IllegalArgumentException("The determinant is 0 (at least one of the elements in the main diagnonal has a 0!)");
        }

        double intermediateAccum = 0.0;
        double[] x = new double[b.length];
        x[x.length-1] = b[b.length-1]/this.matrixData[this.matrixData.length-1];

        //solve Ax=B
        //see http://www.mathwords.com/b/back_substitution.htm, for a practical walkthrough with an upper tri matrix (gauss reduced mat btw, row echoleon form or something)
        // System.out.println("x.length is: "+x.length);

        for (int i = this.matrixSizeN-2; i >= 0; i--) {
            intermediateAccum = 0;
            for (int j = this.matrixSizeN-1; j >= 0; j--) {
                intermediateAccum += this.getElement(i, j)*x[j];
            }
            
            //absolutely wild how this works, mind boggling
            //see 1.2 Mathematical description of the algorithm from
            //https://algowiki-project.org/en/Backward_substitution
            x[i] = (b[i]-intermediateAccum)/this.getElement(i, i);
        }

        return x;
    }
}
