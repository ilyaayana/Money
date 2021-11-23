#include <iostream>
#include<iomanip>
#include <exception>
#include "Money.h"
using namespace std;

int main()
{
    cout << boolalpha;
    Money m1,m2;
    cout << "Enter your values(pounds, shillings and pens)" << endl;
    cout << "for the first one:";
    try { 
        cin >> m1;
        cout << "for the second one:";
        cin >> m2;
    }
    catch (const exception& err) {
        cerr << "Error:" << err.what() << " Aborting the program" << endl;
        return 0;
    }
    cout <<"So, you've chosen values " <<  m1  << "and "<< m2 << endl;
    cout << "negative(-): " << -m1 << " and " << -m2 << endl;
    cout << "summ: ";
    try {
        cout << m1 + m2 << endl;
    }
    catch (exception& err) {
        cerr << "Error: " << err.what() << endl;
    }
    cout << "difference:";
    try {
       cout  << m1 - m2 << endl;
    }
    catch (exception& err) {
        cerr << "Error: " << err.what() << endl;
    }
    cout << "Comparisons: \n1. == : " << (m1 == m2) << "\n2. !=: " << (m1 != m2) << "\n3. < : " << (m1 < m2) << "\n4. <= : " << (m1 <= m2) << "\n5. > : " << (m1 > m2) << "\n6. >= : " << (m1 >= m2) << endl;
    cout << "Adding the value of the second one to the first one, now the value of the first one is ";
    try {
        cout << (m1 += m2) << endl;
    }
    catch (exception& err) {
        cerr << "Error: " << err.what() << endl;
    }
    cout << "Subtracting the value of the second one to the first one, now the value of the first one is ";
    try {
        cout << (m1 -= m2) << endl;
    }
    catch (exception& err) {
        cerr << "Error: " << err.what() << endl;
    }
}
