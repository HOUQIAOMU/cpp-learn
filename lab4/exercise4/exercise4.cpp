#include <iostream>
using namespace std;
enum Day{Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
enum Weather{Sunny,Rainy,Cloudy,Snowy};

int main()
{
    int d = 0;
    int w = 0;
    cout<<"Input the Day value:Monday(1),Tuesday(2),Wednesday(3),Thursday(4),Friday(5),Saturday(6),Sunday(7)"<<endl;
    cin>>d;
    Day today = static_cast<Day>(d-1);//use static_cast
    
    const char* dayNames[] = {"Monday","Tuesday","Wednesday","Thursday","Friday", "Saturday", "Sunday"};
    cout<<"This is "<<dayNames[today]<<endl;

    cout << "input the Weather value: SUNNY(0), RAINY(1), CLOUDY(2), SNOWNY(3)\n";
    cin >> w;
    
    // 将数字转换为Weather枚举值
    Weather weather = static_cast<Weather>(w);
    
    // Weather对应的字符串数组，用于输出
    const char* weatherNames[] = {"SUNNY", "RAINY", "CLOUDY", "SNOWNY"};
    
    cout << "The weather is: " << weatherNames[weather] << endl;

    if((today == Saturday || today == Sunday) && weather ==Sunny)
    {
        cout<<"can Travel\n";
    }
    else
        cout<<"not suitable for travel\n";

    return 0;






    
}