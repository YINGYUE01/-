#include<iostream>

struct Listnode
{
    int val;
    Listnode* next;
    Listnode* prev;
    Listnode(int x) :
        val(x), next(nullptr), prev(nullptr) {}
};


class Deque
{

private:
    Listnode* m_front;
    Listnode* m_rear;
    int DequeSize = 0;

public:


    Deque() : m_front(nullptr), m_rear(nullptr) {}


    bool isEmpty()
    {
        return DequeSize == 0;

    }

    void printSize()
    {
        std::cout << DequeSize << std::endl;
    }

    void push(int num, bool isFront)
    {
        Listnode* node = new Listnode(num);
        if (isEmpty())
        {
            m_front =node;
            m_rear = node;
        }
        else if (isFront)
        {
            m_front->prev = node;
            node->next = m_front;
            m_front = node;
        }
        else
        {
            m_rear->next = node;
            node->prev = m_rear;
            m_rear = node;

        }
        DequeSize++;
    }

    void push_Front(int num)
    {
        push(num, true);
    }

    void push_Rear(int num)
    {
        push(num, false);
    }

    void pop(bool isFront)
    {
        if (isEmpty())
        {
            std::cout << "队列为空" << std::endl;
            return;
        }

        if (isFront)
        {
            std::cout << m_front->val << std::endl;
            Listnode* temp = m_front->next;
            if (!temp)
            {
                temp->prev = nullptr;
                m_front->next = nullptr;
                m_front = m_front->next;
            }
            delete m_front;
            m_front = temp;

        }
        else
        {
            std::cout << m_rear->val << std::endl;
            Listnode* temp = m_rear->prev;
            if (!temp)
            {
                temp->next = nullptr;
                m_rear->prev = nullptr;
            }
            delete m_rear;
            m_rear = temp;

        }
        DequeSize--;
    }
    void pop_front()
    {
        pop(true);
    }
    void pop_rear()
    {
        pop(false);
    }

    int peekFront()
    {
        if (isEmpty())
        {
            throw std::out_of_range::out_of_range("队列为空");
        }
        else
        {
            return m_front->val;
        }
    }
    int peekRear()
    {
        if (isEmpty())
        {
            throw std::out_of_range::out_of_range("队列为空");

        }
        else
        {
            return m_rear->val;
        }
    }
};
int main()
{
    Deque deque;
    deque.push_Front(1);
    deque.push_Front(2);
    deque.push_Front(3);
    deque.push_Front(4);
    deque.push_Rear(5);
    deque.push_Rear(6);
    deque.push_Rear(7);
    deque.push_Rear(8);
    deque.pop_front();
    int a = deque.peekFront();
    int b = deque.peekRear();



}
