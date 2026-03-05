#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int cards[4]{};//define none
    int hands[4];//no definition,generate random num
    int price[] = {2,3,5,9,'c','D'};//transfer c and D to num
    char direction[5] = {'L',82,'U',68};//transfer 82,68 to char
    char title[] = "Deepseek is awesome";
    cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[0] = " << sizeof(cards[0]) << endl;
    cout << "sizeof(price) = " << sizeof(price) << ",sizeof of price[0] = " << sizeof(price[0]) << endl;
    cout << "sizeof(direction) = " << sizeof(direction) << ",length of direction = " << strlen(direction) << endl;
    cout << "sizeof(title) = " << sizeof(title) << ",length of title = " << strlen(title) << endl;
}