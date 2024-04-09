#include<IOSTREAM>

struct Listnode
{
    int val;
    Listnode* next;
    Listnode(int x):
        val(x),next(nullptr) {}
};

class Listqueue
{

private:
    Listnode* m_quefront;
    Listnode* m_querear;
    int queSize;

public:
    void LinkedListQueue()
    {
        m_quefront=nullptr;
        m_querear=nullptr;
        queSize=0;
    }
    void push(int x)
    {
        Listnode* node=new ListNode(x);
        if(m_quefront==nullptr)
        {
            m_quefront=node;
            m_querear=node;
            queSize++;
        }
        else
        {
            node->next=m_querear;
            m_querear=node;
            queSize++;
        }

    }


    void pop()
    {

    }


    void printfont()
    {

    }




};




 int main()
 {

    Listqueue Que;
    Que.push(1);
    Que.push(2);
    Que.push(3);
    Que.push(4);
    Que.pop();
    Que.printfont(); 


    return 0;
 }