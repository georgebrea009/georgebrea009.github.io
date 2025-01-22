#include<iostream>
#include<string>
using namespace std;

struct matrix {
    string name;
    float a11, a12, a21, a22;
};

matrix get_matrix() {
    matrix m;

    cout << "a11\ta12\na21\ta22\n" << endl;
    cout << "Enter matrix name: ";
    cin >> m.name;
    cout << "Enter matrix value a11: ";
    cin >> m.a11;
    cout << "Enter matrix value a12: ";
    cin >> m.a12;
    cout << "Enter matrix value a21: ";
    cin >> m.a21;
    cout << "Enter matrix value a22: ";
    cin >> m.a22;

    return m;
}

float get_scalar() {
    float k;
    cout << "Enter scalar value k: ";
    cin >> k;
    return k;
}

matrix calc_sum(matrix m1, matrix m2) {
    matrix sum;
    sum.name = "Sum";
    sum.a11 = m1.a11 + m2.a11;
    sum.a12 = m1.a12 + m2.a12;
    sum.a21 = m1.a21 + m2.a21;
    sum.a22 = m1.a22 + m2.a22;

    return sum;
}

matrix calc_diff(matrix m1, matrix m2) {
    matrix diff;
    diff.name = "Difference";
    diff.a11 = m1.a11 - m2.a11;
    diff.a12 = m1.a12 - m2.a12;
    diff.a21 = m1.a21 - m2.a21;
    diff.a22 = m1.a22 - m2.a22;

    return diff;
}

matrix scalar_mult(float k, matrix m) {
    matrix k_m;
    k_m.name = "Scalar_Multiplied";

    k_m.a11 = k*m.a11;
    k_m.a12 = k*m.a12;
    k_m.a21 = k*m.a21;
    k_m.a22 = k*m.a22;

    return k_m;
}

matrix calc_prod(matrix m1, matrix m2) {
    matrix prod;
    prod.name = "Prod";

    prod.a11 = m1.a11*m2.a11 + m1.a12*m2.a21;
    prod.a12 = m1.a11*m2.a12 + m1.a12*m2.a22;
    prod.a21 = m1.a21*m2.a11 + m1.a22*m2.a21;
    prod.a11 = m1.a21*m2.a12 + m1.a22*m2.a22;

    return prod;
}

matrix calc_inv(matrix m) {
    matrix m_inv;
    float det;

    m_inv.name = "Inverse";

    det = m.a11*m.a22 - m.a21*m.a12;

    m_inv.a11  = m.a22/det;
    m_inv.a12  = -m.a12/det;
    m_inv.a21  = -m.a21/det;
    m_inv.a22  = m.a11/det;

    return m_inv;
}

void print_matrix(matrix m) {
    cout << m.name << endl;
    cout << m.a11 << "\t" << m.a12 << "\n" << m.a21 << "\t" << m.a22 << endl;
}

int main() {

    matrix m1 = get_matrix();
    matrix m2 = get_matrix();
    float k = get_scalar();

    print_matrix(m1);
    print_matrix(m2);

    int selection;

    do {
        cout << "Select an option below:" << endl;
        cout << "Enter 1 for matrix addition" << endl;
        cout << "Enter 2 for matrix subtraction" << endl;
        cout << "Enter 3 for scalar matrix multiplcaiton" << endl;
        cout << "Enter 4 for matrix multiplication" << endl;
        cout << "Enter 5 for matrix inversion" << endl;
        cout << "Enter 6 to exit" << endl;
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

