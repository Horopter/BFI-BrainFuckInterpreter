#include<iostream>
using namespace std;
class brainfuck
{
    public:
    char cell[30000];
    char *c;
    const char *pt;
    brainfuck(const char bf_input[])
    {
        c = cell;
        pt = bf_input;
    }
    void INC_VAL()
    {
        (*c)++;
    }
    void DEC_VAL()
    {
        (*c)--;
    }
    void INC_PT()
    {
        c++;
    }
    void DEC_PT()
    {
        c--;
    }
    void input()
    {
        cin >> *c;
    }
    void show()
    {
        cout << *c;
    }
    void SQBR_LEFT()
    {
        int _NEXT_  =  1;
        if (*c  ==  '\0')
            {
                do
                {
                    pt++;
                    if (*pt  ==  '[')
                        _NEXT_++;
                    else if(*pt  ==  ']')
                        _NEXT_--;
                }while(_NEXT_ != 0);
            }
    }
    void SQBR_RIGHT()
    {
        int _NEXT_ = 0;
        do
        {
            if (*pt  ==  '[')
                _NEXT_++;
            else if(*pt  ==  ']')
                _NEXT_--;
            pt--;
        }while(_NEXT_ != 0);
    }
    void compute()
    {
            while(*pt)
                {
                    switch(*pt)
                    {
                        case'>':
                                INC_PT();
                                break;
                        case'<':
                                DEC_PT();
                                break;
                        case'+':
                                INC_VAL();
                                break;
                        case'-':
                                DEC_VAL();
                                break;
                        case'.':
                                show();
                                break;
                        case',':
                                input();
                                break;
                        case'[':
                                SQBR_LEFT();
                                break;
                        case']':
                                SQBR_RIGHT();
                                break;
                        default:
                                cout << "Unknown Symbol Found!";
                    }
                    pt++;
                }
    }
};
int main()
{
    const char program[30000] = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    brainfuck itp  =  brainfuck(program);
    itp.compute();
    return 0;
}
