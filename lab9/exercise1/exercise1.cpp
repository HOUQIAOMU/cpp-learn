#include <iostream>
using namespace std;
class Demo
{
    private:
        int id;
        
    public:
        Demo(int cid)
        {
            this->id = cid;
            cout<<"constructor has been called"<<endl;
        }
        static int num;
        void displayID()
        {
            cout<<"this is:"<<this<<",id is:"<<this->id<<endl;
        }

        void display()
        {
            cout<<"The value of static number is:"<<num<<endl;
        }
};

int Demo::num = 0;
int main()
{
    Demo obj(2);
    Demo obj1(1);

    obj.displayID();
    obj1.displayID();
    
    obj.display();
    obj1.display();
    return 0;
}