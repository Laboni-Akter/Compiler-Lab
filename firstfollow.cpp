#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter number of productions: "<<endl;
    int n;
    cin>>n;
    cout<<"Productions: "<<endl;
    string s[n];

    map<char,set<int>> v;
    set<char> st;
    map<char, set<char>> first;
    int maxi;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        v[s[i][0]].insert(i);
        st.insert(s[i][0]);
        if(i==0)
            maxi = s[i].size();
        else
        {
            if(s[i].size()>maxi)
                maxi = s[i].size();
        }
    }
    //first calculation
    for(int i=0;i<n;i++)
    {
        int j=i;
        queue<pair<int,int>> q;
        int d=2;
        int done[n][maxi];
        for(int y=0;y<n;y++)
        {
            for(int z=0;z<maxi;z++)
                done[y][z]=0;
        }
        int p=-1;
       while(true)
       {
           int c=2;
          if(s[j][c]==s[j][0])
            {
                if(q.empty())
                {
               break;
                }
               else{
               auto o = q.front();
               j=o.first;
               p=o.second;
               q.pop();
               }
            }
           else{
           if((s[j][c]>='A'&&s[j][c]<='Z')){
            set<int>:: iterator itrr;
           itrr = v[s[j][c]].begin();
           while(itrr!=v[s[j][c]].end()){
                int x = *itrr;
           q.push({x,j});
           done[j][c]=1;
           itrr++;
           }
           if(q.empty())
           {
               break;
           }
           else{
                auto o = q.front();
               j=o.first;
               p=o.second;
               q.pop();
           }
           }
           else
           {
              if(s[j][c]=='0')
               {
                   first[s[i][0]].insert('0');
                   int m;
                   if(p!=-1){
                  for(m=2;m<s[p].size();m++)
                  {
                      if(done[p][m]==0)
                      {
                          break;
                      }
                  }
                  d=m;
               if(d<s[p].size()){
               if(s[p][d]<'A'||s[p][d]>'Z')
                first[s[i][0]].insert(s[p][d]);
               else
                 {
                     set<int>:: iterator itrrr;
                    itrrr = v[s[p][d]].begin();
                    while(itrrr!=v[s[p][d]].end()){
                    q.push(make_pair(*itrrr,p));
                   done[p][d]=1;
                    itrrr++;
                    }
                 }
               }
               }
               }
               else
                first[s[i][0]].insert(s[j][c]);
               if(q.empty())
                {
               break;
                }
               else{
                auto o = q.front();
               j=o.first;
               p=o.second;
               q.pop();
               }
           }
       }
       }
    }
    // printing first
    set<char>:: iterator it;
    it = st.begin();
    while(it!=st.end())
    {
        set<char>:: iterator itr;
        itr = first[*it].begin();
        cout<<"First["<<*it<<"]:";
        while(itr!=first[*it].end())
        {
            cout<<*itr<<" ";
            itr++;
        }
        cout<<endl;
        it++;
    }

    cout<<endl;

    //follow calculation
    map<char,set<char>> follow;
    follow[s[0][0]].insert('$');
    for(int i=0;i<n;i++)
    {
        char a = s[i][0];
        for(int j=0;j<n;j++)
        {
            for(int k=2;k<s[j].size();k++)
            {
                if(s[j][k]==a)
                {
                    if(k==s[j].size()-1)
                    {
                        set<char>:: iterator itf;
                        itf = follow[s[j][0]].begin();
                        while(itf!=follow[s[j][0]].end())
                        {
                            follow[a].insert(*itf);
                            itf++;
                        }
                    }
                    else if(s[j][k+1]<'A'||s[j][k+1]>'Z')
                    {
                        follow[a].insert(s[j][k+1]);
                    }
                    else
                    {
                        queue<char> q2;
                        q2.push(s[j][k+1]);
                        int c = k+1;
                        while(!q2.empty())
                        {
                            char b = q2.front();
                            q2.pop();
                            set<char>:: iterator itf;
                            itf = first[b].begin();
                            while(itf!=first[b].end()){
                            if(*itf=='0')
                            {
                                if(c!=s[j].size()-1)
                                {
                                    if(s[j][c+1]<'A'||s[j][c+1]>'Z')
                                        follow[a].insert(s[j][c+1]);
                                    else{
                                    q2.push(s[j][c+1]);
                                    c++;
                                    }
                                }
                                else
                                {
                                    set<char>:: iterator itf;
                                    itf = follow[s[j][0]].begin();
                                    while(itf!=follow[s[j][0]].end())
                                        {
                                            follow[a].insert(*itf);
                                            itf++;
                                        }
                                }
                            }
                            else{
                            follow[a].insert(*itf);
                            }
                            itf++;
                            }
                        }
                    }
                }
            }
        }
    }

     set<char>:: iterator itff;
    itff = st.begin();
    while(itff!=st.end())
    {
        set<char>:: iterator itrf;
        itrf = follow[*itff].begin();
        cout<<"Follow["<<*itff<<"]:";
        while(itrf!=follow[*itff].end())
        {
            cout<<*itrf<<" ";
            itrf++;
        }
        cout<<endl;
        itff++;
    }

}
