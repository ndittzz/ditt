#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;
    cout << left << setw (9) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM POINTER << "<<" " << endl;
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl<<endl;

    int a;
    int *pointera = &a;
    int *pointerb = pointera;

    cout << "   Input a : ";
    cin >> a;

    int c = a + 30;

    cout << "   Nilai a : " << *pointera << " (Memory Address : " << pointera << ")" << endl;
    cout << "   Nilai b : " << *pointerb << " (Memory Address : " << pointerb << ")" << endl;
    cout << "   Nilai c : " <<     c     << " (Memory Address : " <<    &c    << ")" << endl;
    cout << endl;

    cout << "   b + 10 " << endl;
    cout << "   Nilai a : " << *pointera + 10 << " (Memory Address : " << pointera << ")" << endl;
    cout << "   Nilai b : " << *pointerb + 10 << " (Memory Address : " << pointerb << ")" << endl;

  return 0;
}
