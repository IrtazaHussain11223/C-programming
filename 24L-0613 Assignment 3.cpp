#include <iostream>
#include <cmath>
using namespace std;

class VectorType 
{
private:
    float* x;
    float* y;
    float* z;

public:
    VectorType() 
    {
        x = new float;
        y = new float;
        z = new float;
        *x = *y = *z = 0;
    }

    VectorType(float a, float b, float c) 
    {
        x = new float;
        y = new float;
        z = new float;
        *x = a;
        *y = b;
        *z = c;
    }

    VectorType(const VectorType& v)
    {
        x = new float;
        y = new float;
        z = new float;
        *x = *v.x;
        *y = *v.y;
        *z = *v.z;
    }

    ~VectorType() 
    {
        delete x;
        delete y;
        delete z;
    }

    VectorType& operator=(const VectorType& v) 
    {
        if (this != &v)
        {
            *x = *v.x;
            *y = *v.y;
            *z = *v.z;
        }
        return *this;
    }

    float operator*(const VectorType& v) const
    {
        return (*x * *v.x) + (*y * *v.y) + (*z * *v.z);
    }

    float length() const 
    {
        return sqrt(*x * *x + *y * *y + *z * *z);
    }

    float angle(const VectorType& v) const 
    {
        return acos((*this * v) / (length() * v.length()));
    }

    VectorType operator+(const VectorType& v) const
    {
        return VectorType(*x + *v.x, *y + *v.y, *z + *v.z);
    }

    VectorType operator-(const VectorType& v) const 
    {
        return VectorType(*x - *v.x, *y - *v.y, *z - *v.z);
    }

    VectorType& operator++()
    {
        (*x)++;
        (*y)++;
        (*z)++;
        return *this;
    }

    VectorType operator++(int)
    {
        VectorType temp = *this;
        ++(*this);
        return temp;
    }

    VectorType& operator--() 
    {
        (*x)--;
        (*y)--;
        (*z)--;
        return *this;
    }

    VectorType operator--(int)
    {
        VectorType temp = *this;
        --(*this);
        return temp;
    }

    friend bool operator==(const VectorType& a, const VectorType& b)
    {
        return *a.x == *b.x && *a.y == *b.y && *a.z == *b.z;
    }

    friend bool operator!=(const VectorType& a, const VectorType& b)
    {
        return !(a == b);
    }

    friend istream& operator>>(istream& in, VectorType& v)
    {
        in >> *v.x >> *v.y >> *v.z;
        return in;
    }

    friend ostream& operator<<(ostream& out, const VectorType& v) 
    {
        out << *v.x << " " << *v.y << " " << *v.z;
        return out;
    }
};

int main() 
{
    VectorType a(1, 2, 3);
    VectorType b(4, 5, 6);
    VectorType c = a + b;
    cout << "Addition is : " << c << endl;
    VectorType d = a - b;
    cout << "Subtraction is : " << d << endl;
    cout << "Dot product: " << a * b << endl;
    cout << "Angle in radinas: " << a.angle(b) << endl;
    cout << "Length of a: " << a.length() << endl;
}
