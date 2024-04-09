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
        m_quefront = nullptr;
        m_querear = nullptr;
        queSize = 0;
    }
    void push(int x)
    {
        Listnode* node = new Listnode(x);
        if (m_quefront == nullptr)
        {
            m_quefront = node;
            m_querear = node;
            queSize++;
        }
        else
        {
            m_querear->next=node;
            m_querear = node;
            queSize++;
        }

    }


    void pop()
    {
        if (m_quefront == nullptr)
        {
            std::cout << "kong" << std::endl;

        }
        else
        {
            Listnode* temp = m_quefront;
            m_quefront = m_quefront->next;
            delete temp;
            queSize--;
        }
    }


    void printfont()
    {

        std::cout <<"¶ÓÊ×Îª£º"<< m_quefront->val << std::endl;

    }




};




int main()
{

    Listqueue Que;
    Que.LinkedListQueue();
    Que.push(1);
    Que.push(2);
    Que.push(3);
    Que.push(4);
    Que.pop();
    Que.printfont();


    return 0;
}