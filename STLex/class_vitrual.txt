//virtual

#include<iostream>
class Parent
{
public:
    Parent(){}
    Parent(int value){this->value=value;}
    ~Parent(){}
    Parent(Parent&){}
    virtual void move(int n){std::cout<<"Parent moves "<<n<<" step!"<<std::endl;}
protected:
    int value;
};
class Child: public Parent
{
public:
    Child(){}
    Child(int value,int special):
    Parent(value),
    special(special)
    {

    }
    void move(int n){std::cout<<"Child moves "<<n<<" step!"<<std::endl;}
private:
    int special;
};
void main()
{
    Parent *p = new Child(1,1);
    p->move(1);//child moves 1 step£¡
    Parent& p1 = *p;
    p1.move(1);//child moves 1 step£¡
    Parent p2 = *p;
    p2.move(1);//Parent moves 1 step£¡
    delete p;
}