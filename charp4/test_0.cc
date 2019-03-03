///
///@file     test_0.cc
///@author     Jason(13933536151@163.com)
///@data     2019-03-03 21:38:1551620298
///
  
#include <iostream>
#include <cassert>
using namespace std;
//�ڵ㶨��
template<class T>
struct StackNode {
    T data;                     //ջÿ���ڵ��������
    StackNode<T> *next;         //ջ�ڵ��ָ����
    StackNode(T x, StackNode<T> *Node = NULL) : data(x){}
    //��ÿ�����Գ�ʼ��
};
//ģ���ඨ��
template<class T>
class LinkedStack {
public:
    LinkedStack() : top(NULL){}                 //���캯��
    ~LinkedStack();                                //��������
    void Push(const T & x);                     //��ջ
    bool Pop(T & x);                            //��ջ
    bool getTop(T & x) const;                   //��ȡջ��Ԫ��
    bool isEmpty()const;                        //�ж�ջ�Ƿ�ΪNULL
    int getSize() const;                        //��ջ��Ԫ�صĸ���
    void makeEmpty();                           //���ջ
    void output(ostream & out);                     //����������˴������غ������ã�
private:
    StackNode<T> *top;                          //ջ��ָ��
};
//��������
template<class T>
void LinkedStack<T>::makeEmpty() {
    //���ɾȥ��ʽջ�е�Ԫ�أ�ֱ��ջ��ָ��Ϊ��
    StackNode<T> *p;//ָ��ջ���(�ṹ��)��ָ��
    //����p����Ϊһ������ָ���ڹ���
    //����ڵ��ͷ�
    while (top != NULL) {
        p = top;
        top = top->next;
        delete p;
    }

}

template<class T>//��������ж����ʱ��Ҳ��Ҫģ��˵��
LinkedStack<T>::~LinkedStack() {
    //��������
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
    //��Ԫ��x����ջ��
    StackNode<T> *newNode = new StackNode<T>(x);
    assert(newNode != NULL);                            //�ڴ���������жϴ���
    newNode->next = top;
    top = newNode;
}

template<class T>
bool LinkedStack<T>::Pop(T & x) {
    //ɾ��ջ���ڵ㣬ɾ����data���ص�x����
    if (isEmpty()) {
        cout << "IsEmpty()"<<endl;
        return false;                                   //ջΪNULL��ջʧ��
        
    }
    StackNode<T> *p = top;                              //���Top
    top = top->next;                                    //����ջ��ָ��
    x = p->data;                                        //��ȡͷ����ֵ
    delete p;                                           //�ͷ�ջ��Ԫ��
    return true;
}

template<class T>
bool LinkedStack<T>::getTop(T & x) const {
    //����ջ��Ԫ�ص�ֵ
    if (isEmpty()) {
        cout << "getTop fail"<< endl;
        return false;                                   //ջΪNULL����ȡջ��ʧ��
    }
    x = top->data;
    return true;
}

template<class T>
int LinkedStack<T>::getSize()const {
    StackNode<T> *p = top;
    int len = 0;
    while (p != NULL) {
        p = p->next;                                    //������������
        len++;
    }
    cout << "the size of LinkList is:\t"<<len<<endl;
    return len;
}

template<class T>
void LinkedStack<T>::output(ostream & out) {            //������������غ�������
    //��<< �������غ󣬽��и�ʽ�������cout������
    //�����ʽջ
    StackNode<T> *p = top;
    while (p != NULL) {
        out << p->data << ' ';
        p = p->next;
    }
}

template<class T>
ostream & operator << (ostream & out, LinkedStack<T> & LS) {
    //����������������������Ϊ�����
    //һ����ostream�������ã���һ�����û��Զ����LinkedStack<T>�������
    //�ȼ����������е���cout<<LS����������Ϊoperator(cout,LS)
    //���ò�����Ϊcout�ı�������������һ����ostream�����ã��Ա���ȡ���������������
    LS.output(out);                             //������Ԫ������ģ��class�г��ֵ�����
    cout << endl;
    return out;
}


int main()
{
    //Push and Pop����
    LinkedStack<int> LS;                        //����һ����ʽջ
    LS.Push(1);
    LS.Push(2);
    LS.Push(3);
    LS.Push(4);
    LS.Push(5);
    cout << LS;                                 //�����غ������
    int del1, del2;
    LS.Pop(del1);
    cout << "del1=\t"<<del1<<endl;
    LS.Pop(del2);
    cout << "del2=\t"<<del2<<endl;
    cout << LS;

    //getSize �� getTop����
    int topVal = 0;
    LS.getTop(topVal);
    cout << topVal << endl;
    cout << LS.getSize() << endl;

    //�ж��Ƿ�ΪNULL����
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
