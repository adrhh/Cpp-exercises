#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cerr;
using std::string;

template <typename T>
class Stack
{
    private:
        T* arr;
        int size;
        int top;
        bool isEmpty() const
            {return top < 0;}
        bool isFull() const
            {return top == size - 1;}
    public:
        Stack(int n=1) : size(n), top(-1)
            {arr = new T[n];}
        void push(T t)
        {
            if(!isFull())
                arr[++top] = t;   
            else
                cerr << "Stack is full" << endl;
        }
        T pop()
        {
            if(!isEmpty())
                return arr[top--];
            else
                cerr << "Stack is empty" << endl;
        }
};

string zadanie(const string& str)
{
    Stack<char> stack(str.size());
    string answer("Yes");
    
    for(auto c : str)
    {
        char tempChar;
        bool loopFlag = true;
    
        switch(c)
        {
            case '{' :  case '[' : case  '(' :
                stack.push(c);
                break;
            case '}' :
                tempChar = stack.pop();
                if(!(tempChar == '{'))
                    loopFlag = false;
                break;
            case ']' :
                tempChar = stack.pop();
                if(!(tempChar == '['))
                    loopFlag = false;
                break;
            case ')' :
                tempChar = stack.pop();
                if(!(tempChar == '('))
                    loopFlag = false;
                break;
        }
        if(!loopFlag)
        {
            answer = "No";
            break;
        }
    }
    return answer;   
}

int main()
{
    string test1 = "([])";
    string test2 = "{[]([][])}";
    string test3 = "{(})";
    cout << zadanie(test1) << endl;
    cout << zadanie(test2) << endl;
    cout << zadanie(test3) << endl;
    
    return 0;
}
