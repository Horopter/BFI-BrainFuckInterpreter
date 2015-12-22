#include<iostream>
#include<cstring>
using namespace std;
class ookook
{
    public:
    char cell[30000];
    char unconverted[30000];
    char *c;
    const char *pt;
    void ookbfc(char *p,char *q)
    {
        char* a = p;
        char* b=(p+strlen(p)-9);
        for(; a <= b; a+=9)
        {
            if(!strncmp("Ook. Ook?", a, 9)) strcat(q,">");
            else if(!strncmp("Ook? Ook.", a, 9)) strcat(q,"<");
            else if(!strncmp("Ook. Ook.", a, 9)) strcat(q,"+");
            else if(!strncmp("Ook! Ook!", a, 9)) strcat(q,"-");
            else if(!strncmp("Ook! Ook?", a, 9)) strcat(q,"[");
            else if(!strncmp("Ook? Ook!", a, 9)) strcat(q,"]");
            else if(!strncmp("Ook! Ook.", a, 9)) strcat(q,".");
            else if(!strncmp("Ook. Ook!", a, 9)) strcat(q,",");
            else a-=8;
        }
    }
    ookook(const char ook_input[])
    {
        char bf_output[30000]="";
        ookbfc((char *)ook_input,bf_output);
        c = cell;
        pt = bf_output;
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
    const char ookp[30000] = "Ook. Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook? Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook? Ook! Ook! Ook? Ook! Ook? Ook. Ook! Ook. Ook. Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook? Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook? Ook! Ook! Ook? Ook! Ook? Ook. Ook. Ook. Ook! Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook. Ook! Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook. Ook. Ook? Ook. Ook? Ook. Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook? Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook? Ook! Ook! Ook? Ook! Ook? Ook. Ook! Ook. Ook. Ook? Ook. Ook? Ook. Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook? Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook? Ook! Ook! Ook? Ook! Ook? Ook. Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook. Ook? Ook. Ook? Ook. Ook? Ook. Ook? Ook. Ook! Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook. Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook. Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook. Ook. Ook? Ook. Ook? Ook. Ook. Ook! Ook.";
    ookook itp  =  ookook(ookp);
    itp.compute();
    return 0;
}
