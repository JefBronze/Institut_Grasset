#include <iostream>

using namespace std;

void func2(int x, int y, int z) { // Passo º3.2 - func2(0,10,20)
    x += y + z; // x = x + y + z // Passo 3.2.1 - x = 0 + 10 + 20 - x = 30
}

int func1(int a, int b) { // Passo *3.1 - func1(10, 20)
    int result{};
    result = a + b; // Passo 3.1.1 - result = 10 + 20 - result = 30
    func2(result, a, b); // Passo 3.1.2 - º3.2
    return result;
}

int main()
{
    int x{10}; // Passo 1 - x = 10.
    int y{20}; // Passo 2 - y = 20.
    int z{};
    z = func1(x,y); // Passo 3 - z = *3.1
    cout << z << endl; // Passo 4 z = 30
    return 0;
}