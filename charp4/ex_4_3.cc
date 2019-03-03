///
///@file     ex_4_3.cc
///@author     Jason(13933536151@163.com)
///@data     2019-03-03 17:53:1551606835
///
  
#include<iostream>
#include"Stack.h"
#include"LStack.h"
using std::cout;
using std::cin;
using std::endl;
enum TOHop {    DOMOVE, DOTOH};
class TOHobj
{
public:
    TOHop op;
    int num;
    char start, goal, tmp;

    TOHobj(int n,char s, char g,char t)
    {
        op = DOTOH; num = n;
        start = s; goal = g; tmp = t;
    }

    TOHobj(char s,char g)
    {
        op = DOMOVE;
        start = s;
        goal = g;
    }
};


void TOH(int n,char start,char goal,char tmp,LStack<TOHobj*>& S)
{
    S.push(new TOHobj(n, start, goal, tmp));
    TOHobj* t;
    while(S.length()>0) 
    {
        t = S.pop();
        if (t->op ==DOMOVE)     ;//move(t->start,t->goal);
        else if (t->num >0)
        {
            int num = t->num;
            char tmp = t->tmp;
            char goal = t -> goal;
            char start = t -> start;
            S.push(new TOHobj(num-1, tmp, goal, start));
            S.push(new TOHobj(start,goal));
            S.push(new TOHobj(num-1, start,tmp, goal));
        }
        delete t;
    }

}

 
int main()
{
    LStack<TOHobj*> S;
    TOH(3,'s','g','t',S);
 
}
