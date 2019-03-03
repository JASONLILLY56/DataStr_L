template <typename E> class LStack:public Stack<E> 
{
private:
    E * top;
    int size;
public:
    LStack(int sz = 10)
    {
        top = NULL; 
        size = 0;
    }

    ~LStack() { clear(); }
    void clear()
    {
        while (top != NULL)
        {
            E* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    void push(const E& it)
    {
        top = new E(it, top);
        size++;
    }

    E pop()
    {
        Assert(top !=NULL, "Stack is empty");
        E it = top ->element;
        E* ltemp = top ->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }

    const E& topValue() const 
    {
        //Assert(top !=0,"Stack is empty");
        return top -> element;
    }

    int length() const {return size;}
};
