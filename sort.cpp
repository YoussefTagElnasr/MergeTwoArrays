#include <iostream>

using namespace std;

int main ()
{
    int a , b , c;

    cin >> a >> b >> c;

    int x = a;
    int y = b;
    int z = c;


    if ( a > c )
    {
        int temp  = a;
        a = c;
        c = temp;
    }


    if ( a > b )
    {
        int temb1 = a;
        a = b;
        b = temb1;
    }

    if ( b > c)
    {
        int temp2 = b;
        b = c; 
        c = temp2;
    }

    

    cout << a << ' ' <<  b  << ' ' << c << endl ;

    int temp3 = b;
    int temp4 = a;

    a = c;
    b = temp4;
    c = temp3;

    cout << x << ' ' << y << ' ' << z;

}