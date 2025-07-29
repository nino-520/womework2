#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial; 

class Term {
    friend Polynomial;
private:
    float coef; 
    int exp;    
public:
    Term(float c = 0, int e = 0) : coef(c), exp(e) {}
};

class Polynomial {
private:
    Term* termArray; 
    int capacity;    
    int terms;       
public:
    Polynomial() { 
        capacity = 10;
        terms = 0;
        termArray = new Term[capacity];
    }

    Polynomial Add(Polynomial poly) { 
        Polynomial result;
        int i = 0, j = 0;
        while (i < terms || j < poly.terms) {
            if (i >= terms) {
                result.termArray[result.terms++] = poly.termArray[j++];
            } else if (j >= poly.terms) {
                result.termArray[result.terms++] = termArray[i++];
            } else if (termArray[i].exp > poly.termArray[j].exp) {
                result.termArray[result.terms++] = termArray[i++];
            } else if (termArray[i].exp < poly.termArray[j].exp) {
                result.termArray[result.terms++] = poly.termArray[j++];
            } else {
                float sumCoef = termArray[i].coef + poly.termArray[j].coef;
                if (sumCoef != 0) {
                    result.termArray[result.terms] = Term(sumCoef, termArray[i].exp);
                    result.terms++;
                }
                i++; j++;
            }
        }
        return result;
    }

    Polynomial Mult(Polynomial poly) { 
        Polynomial result;
        for (int i = 0; i < terms; i++) {
            for (int j = 0; j < poly.terms; j++) {
                float newCoef = termArray[i].coef * poly.termArray[j].coef;
                int newExp = termArray[i].exp + poly.termArray[j].exp;
                result.termArray[result.terms++] = Term(newCoef, newExp);
            }
        }
        return result;
    }

    float Eval(float f) { 
        float result = 0;
        for (int i = 0; i < terms; i++) {
            result += termArray[i].coef * pow(f, termArray[i].exp);
        }
        return result;
    }

    ~Polynomial() { delete[] termArray; } 
};

int main() {
    Polynomial p1, p2;
    p1.termArray[0] = Term(2, 2); p1.terms = 1; 
    p2.termArray[0] = Term(3, 1); p2.terms = 1; 
    Polynomial sum = p1.Add(p2);
    cout << "在 x=2 時的和: " << sum.Eval(2) << endl;
    return 0;
}
