#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"The given grammar is:"<<endl;
    cout<<"E->TE'"<<endl;
    cout<<"E'->+TE'|epsison"<<endl;
    cout<<"T->FT'"<<endl;
    cout<<"T'->*FT'|epsilon"<<endl;
    cout<<"F->(E)|i"<<endl;
    cout<<"Enter the string that is to be parsed :"<<endl;
    string s;
    cin>>s;
    s = s+'$';
    stack<char> st;
    st.push('$');
    st.push('E');
    int i=0;
    while(s[i]!=NULL)
    {
        char a = st.top();
        if(a=='$'&&s[i]=='$')
        {
            cout<<"Successful parsing"<<endl;
            i++;
        }
        else if(a==s[i])
        {
            cout<<"match of "<<a<<endl;
            i++;
            st.pop();
        }
        else
        {

            if(a=='E'&&(s[i]=='('||s[i]=='i'))
            {
                 cout<<"E->TE'"<<endl;
                 st.pop();
                 st.push('A');
                 st.push('T');
            }
            else if(a== 'A' && s[i] == '+')
            {
                cout<<"E'->+TE'"<<endl;

                st.pop();
                st.push('A');
                st.push('T');
                st.push('+');

            }
            else if(a=='A'&& (s[i]=='$'||s[i]==')'))
            {
                cout<<"E'->epsilon"<<endl;
                st.pop();
            }
            else if(a=='T'&&(s[i]=='('||s[i]=='i'))
            {
                cout<<"T->FT'"<<endl;
                st.pop();
                st.push('B');
                st.push('F');
            }
             else if(a=='B'&&s[i]=='*')
            {
                cout<<"T'->*FT'"<<endl;
                st.pop();
                st.push('B');
                st.push('F');
                st.push('*');
            }
            else if(a=='B'&&(s[i]=='+'||s[i]==')'||s[i]=='$'))
            {
                cout<<"T'->epsilon"<<endl;
                st.pop();
            }
            else if(a=='F'&&s[i]=='(')
            {
                cout<<"F->(E)"<<endl;
                st.pop();
                st.push(')');
                st.push('E');
                st.push('(');
            }
            else if(a=='F'&&s[i]=='i')
            {
                cout<<"F->i"<<endl;
                st.pop();
                st.push('i');
            }
            else{
                cout<<"error"<<endl;
                break;
            }
        }
    }
}
