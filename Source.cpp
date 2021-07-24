#include<iostream>
using namespace std;


class Matrix {
private:
	int row, colum;
	int** arr;

public:
	 Matrix(int, int);
     Matrix operator+(const Matrix&);
	 Matrix operator-(const Matrix& );
	 Matrix operator*(const Matrix& );
	 friend istream& operator>>(istream&input, Matrix&);
	 friend ostream& operator<<(ostream&, Matrix&);
	
	

	
};
//addition overloading
Matrix::Matrix(int row, int colum) {

	this->row = row;
	this->colum = colum;
	arr = new int* [row];
	for (int i = 0; i < row; i++) {

		arr[i] = new int[colum];
	}

}
Matrix Matrix :: operator +(const Matrix &c1) {
	cout << "adding 2 matrix" << endl;
	Matrix c3( row, colum);
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < colum; j++)
		{
			c3.arr[i][j] = c1.arr[i][j] + this->arr[i][j];
		}
	}

	return c3;
}
//substract overloading
Matrix Matrix:: operator -(const Matrix&c1 ) {
	cout << "substract 2 matrix" << endl;
	Matrix c3(row, colum);
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < colum; j++)
		{
			c3.arr[i][j] = c1.arr[i][j] - this->arr[i][j];
		}
	}
	return c3;

}
// cin overloading
istream& operator>>(istream& input, Matrix & c)
{
	int i, j;
	cout << "Please enter the matrix:" << endl;
	for (i = 0; i < c.row; i++)
	{
		for (j = 0; j < c.colum; j++)
			input >> c.arr[i][j];
	}
	return input;
}
//cout overloading
ostream& operator<<(ostream& output, Matrix & c)
{
	int i, j;
	for (i = 0; i < c.row; i++)
	{
		for (j = 0; j < c.colum; j++)
		{

			output << c.arr[i][j];
			output << endl;

		}
	}
	return output;
}
Matrix Matrix:: operator *(const Matrix& c1)
{
	cout << " ​​multiplied:" << endl; 
	int i, j, k, sum;
	Matrix c3(row, colum);
	for (i = 0; i < row; i++) {
		for (j = 0; j < colum; j++)
		{
			sum = 0;
			for (k = 0; k < row; k++)
			{
				sum += c1.arr[i][k] * this->arr[k][j];
			}
			c3.arr[i][j] = sum;
		}
	}
	
	return c3;
}

//print


int main() {
	
	Matrix a(3, 3);
	cin >> a;
	Matrix b(3, 3);
	cin >> b;
	Matrix c = a + b;
	cout << c;
	Matrix c1 = a - b;
	cout << c1;
	Matrix c2 = a*b;
	cout << c2;
	
	return 0;
}
