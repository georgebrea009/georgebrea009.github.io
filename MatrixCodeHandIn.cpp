/*CIS277-B040
Group 1
1.	Mahmoud Almeslamani
2.	Roberto Bruni
3.	Mario Awad Girgis
4.	George Brea
*/
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


struct Matrix { string name;
float element1, element2, element3, element4;
};


/*
Gets matrix by prompting user for input.
Initializes a matrix structure, prints out matrix shape, then prompts user for 
Matrix name and matrix values.
Returns a matrix structure with the inputted name and values.
*/
 
Matrix get_matrix() {
Matrix m;
    cout << "Enter the name of the matrix: " << endl;
    cin >> m.name;
    cout << "Enter the values for the 2x2 matrix:" << endl; 
    cout << "Enter matrix element 1: ";cin >> m.element1; 
    cout << "Enter matrix element 2: ";cin >> m.element2; 
    cout << "Enter matrix element 3: ";cin >> m.element3; 
    cout << "Enter matrix element 4: ";cin >> m.element4;
    cout<<endl;

return m;
}


/*
Gets a scalar by prompting user for input.
Initializes a float, then prompts user for scalar value.
Returns scalar float.
*/
 
float get_scalar() {
 
float k;
    cout << "Enter scalar value k: "; cin >> k;
return k;
}

/*
Computes the sum of two matrices.
Takes in two matrix structures m1 and m2 as input and adds their elements.
Returns a matrix structure with name "Sum". 
*/

Matrix calc_sum(const Matrix& m1, const Matrix& m2) {
Matrix sum;
sum.name = "Sum";
    cout<<endl;
    sum.element1 = m1.element1 + m2.element1;
    sum.element2 = m1.element2 + m2.element2;
    sum.element3 = m1.element3 + m2.element3;
    sum.element4 = m1.element4 + m2.element4;
return sum;
}

/*
Computes the difference of two matrices.
Takes in two matrix structures m1 and m2 as input and subtracts m2 from m1.
Returns a matrix structure with name "Difference". 
*/
 
Matrix calc_diff(const Matrix& m1, const Matrix& m2) {
Matrix diff;
diff.name = "Difference";
    cout<<endl;
    diff.element1 = m1.element1 - m2.element1;
    diff.element2 = m1.element2 - m2.element2;
    diff.element3 = m1.element3 - m2.element3;
    diff.element4 = m1.element4 - m2.element4;
return diff;
}


/*
Computes the product of a scalar and a matrix.
Takes in one matrix and one float to compute the product of the float and 
matrix values.
Returns a matrix structure with name "Difference". 
*/
 
Matrix scalar_mult(float k, const Matrix& m) {
Matrix k_m;
k_m.name = "Scalar_Multiplied";
    cout <<endl;
    k_m.element1 = k * m.element1;
    k_m.element2 = k * m.element2;
    k_m.element3 = k * m.element3;
    k_m.element4 = k * m.element4;
return k_m;
}

/*
Computes the product of two matrices.
Takes in two matrices m1 and m2, then performs a matrix multiplication.
Returns a matrix structure with name "Difference". 
*/
 
Matrix calc_prod(const Matrix& m1, const Matrix& m2) {
Matrix prod; prod.name = "Product";
    cout <<endl;
    prod.element1 = m1.element1 * m2.element1 + m1.element2 * m2.element3;
    prod.element2 = m1.element1 * m2.element2 + m1.element2 * m2.element4;
    prod.element3 = m1.element3 * m2.element1 + m1.element4 * m2.element3;
    prod.element4 = m1.element3 * m2.element2 + m1.element4 * m2.element4;
return prod;
 
}

/*
Computes the inverse of a matrix.
Takes in one matrix m1 and m2, then calculates the determinant and uses it to
compute the inverse matrix.
Returns a matrix structure with name "Difference". 
*/
 
Matrix calc_inv(const Matrix& m) {
Matrix m_inv;
float det;
m_inv.name = "Inverse";
cout<<endl;
det = m.element1 * m.element4 - m.element2 * m.element3;
    if (det == 0) {
        cout << "Matrix is not invertible (determinant is zero)." << endl;
        return m_inv; // Return matrix with uninitialized values
    }
        m_inv.element1 = m.element4 / det;
        m_inv.element2 = -m.element2 / det;
        m_inv.element3 = -m.element3 / det;
        m_inv.element4 = m.element1 / det;
return m_inv;
}

/*
Display a matrix.
Takes one matrix m as input and displays its values using cout as seen below:
m.name
m.a11   m.a12
m.a21   m.a22
\n
No value returned.
*/

void print_matrix(const Matrix& m) {
    cout << m.name << ":" << endl;
    cout << m.element1 << "\t" << m.element2 << endl;
    cout << m.element3 << "\t" << m.element4 << endl;
}
 
int main() {
Matrix m1 = get_matrix();
Matrix m2 = get_matrix();
float k = get_scalar();
int selection;
    do {
        cout<<endl;
        cout << "Select one of the options:" << endl;
        cout << "1. Matrix addition" << endl;
        cout << "2. Matrix subtraction" << endl;
        cout << "3. Scalar matrix multiplication" << endl;
        cout << "4. Matrix multiplication" << endl;
        cout << "5. Matrix inversion" << endl;
        cout << "6. Exit" << endl<<endl;
        cout<<"Enter your selection: ";
        cin >> selection;
switch (selection) {
        case 1:
            print_matrix(calc_sum(m1, m2));
            break;
        case 2:
            print_matrix(calc_diff(m1, m2));
            break;
        case 3:
            print_matrix(scalar_mult(k, m1));
            break;
        case 4:
            print_matrix(calc_prod(m1, m2));
            break;
        case 5:
            print_matrix(calc_inv(m1));
            break;
        case 6:
            cout << "Exiting" << endl;
            break;
        default:
        cout << "Invalid input. Try again." << endl;
        }
    } while (selection != 6);
     return 0;
}



