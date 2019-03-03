///
///@file     test_0.cc
///@author     Jason(13933536151@163.com)
///@data     2019-03-03 21:38:1551620298
///
  
#include <iostream>
#include <cassert>
using namespace std;
//节点定义
template<class T>
struct StackNode {
    T data;                     //栈每个节点的数据域
    StackNode<T> *next;         //栈节点的指针域
    StackNode(T x, StackNode<T> *Node = NULL) : data(x){}
    //对每个结点对初始化
};
//模板类定义
template<class T>
class LinkedStack {
public:
    LinkedStack() : top(NULL){}                 //构造函数
    ~LinkedStack();                                //析构函数
    void Push(const T & x);                     //进栈
    bool Pop(T & x);                            //出栈
    bool getTop(T & x) const;                   //读取栈顶元素
    bool isEmpty()const;                        //判断栈是否为NULL
    int getSize() const;                        //求栈的元素的个数
    void makeEmpty();                           //清空栈
    void output(ostream & out);                     //输出函数（此处由重载函数调用）
private:
    StackNode<T> *top;                          //栈顶指针
};
//函数定义
template<class T>
void LinkedStack<T>::makeEmpty() {
    //逐个删去链式栈中的元素，直至栈顶指针为空
    StackNode<T> *p;//指向栈结点(结构体)的指针
    //这里p是作为一个工作指针在工作
    //逐个节点释放
    while (top != NULL) {
        p = top;
        top = top->next;
        delete p;
    }

}

template<class T>//在类外进行定义的时候，也需要模板说明
LinkedStack<T>::~LinkedStack() {
    //析构函数
    makeEmpty();
}

template<class T>
bool LinkedStack<T>::isEmpty() const{
    if (NULL == top) {
        return true;
    }
    return false;
}

template<class T>
void LinkedStack<T>::Push(const T & x) {
    //将元素x推入栈顶
    StackNode<T> *newNode = new StackNode<T>(x);
    assert(newNode != NULL);                            //内存分配错误的中断处理
    newNode->next = top;
    top = newNode;
}

template<class T>
bool LinkedStack<T>::Pop(T & x) {
    //删除栈顶节点，删除的data返回到x当中
    if (isEmpty()) {
        cout << "IsEmpty()"<<endl;
        return false;                                   //栈为NULL出栈失败
        
    }
    StackNode<T> *p = top;                              //标记Top
    top = top->next;                                    //更新栈顶指针
    x = p->data;                                        //提取头结点的值
    delete p;                                           //释放栈顶元素
    return true;
}

template<class T>
bool LinkedStack<T>::getTop(T & x) const {
    //返回栈顶元素的值
    if (isEmpty()) {
        cout << "getTop fail"<< endl;
        return false;                                   //栈为NULL，读取栈顶失败
    }
    x = top->data;
    return true;
}

template<class T>
int LinkedStack<T>::getSize()const {
    StackNode<T> *p = top;
    int len = 0;
    while (p != NULL) {
        p = p->next;                                    //遍历整个链表
        len++;
    }
    cout << "the size of LinkList is:\t"<<len<<endl;
    return len;
}

template<class T>
void LinkedStack<T>::output(ostream & out) {            //输出函数，重载函数调用
    //对<< 进行重载后，进行格式化输出到cout对象中
    //输出链式栈
    StackNode<T> *p = top;
    while (p != NULL) {
        out << p->data << ' ';
        p = p->next;
    }
}

template<class T>
ostream & operator << (ostream & out, LinkedStack<T> & LS) {
    //重载输出运算符，返回类型为输出流
    //一个是ostream流的引用，另一个是用户自定义的LinkedStack<T>类的引用
    //等价于主函数中调用cout<<LS编译器解释为operator(cout,LS)
    //引用参数成为cout的别名，函数返回一个对ostream的引用，以便提取运算符的连续调用
    LS.output(out);                             //避免友元函数在模板class中出现的问题
    cout << endl;
    return out;
}


int main()
{
    //Push and Pop测试
    LinkedStack<int> LS;                        //定义一个链式栈
    LS.Push(1);
    LS.Push(2);
    LS.Push(3);
    LS.Push(4);
    LS.Push(5);
    cout << LS;                                 //用重载函数输出
    int del1, del2;
    LS.Pop(del1);
    cout << "del1=\t"<<del1<<endl;
    LS.Pop(del2);
    cout << "del2=\t"<<del2<<endl;
    cout << LS;

    //getSize 和 getTop测试
    int topVal = 0;
    LS.getTop(topVal);
    cout << topVal << endl;
    cout << LS.getSize() << endl;

    //判断是否为NULL测试
    if (LS.isEmpty()) {
        cout << "empty stack" << endl;
    }
    else {
        cout << "not empty stack" << endl;
    }
    LS.makeEmpty();
    if (LS.isEmpty()) {
        cout << "empty stack" << endl;
    }
    else {
        cout << "not empty stack" << endl;
    }
}
