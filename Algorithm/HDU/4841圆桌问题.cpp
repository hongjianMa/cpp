#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    vector<int>table;
    while(cin>>n>>m)
    {
        table.clear();
        for(int i = 0;i<2*n;i++)
        {
            table.push_back(i);
        }
        int pos = 0;//记录当前位置
        for(int i = 0;i<n;i++)//赶走n个坏人
        {
            pos = (pos+m-1)%table.size();//圆桌是个坏，取余处理
            table.erase(table.begin()+pos);//去除坏人
        }
        int j = 0;
        for(int i = 0;i<2*n;i++)
        {
            if(!(i%50)&&i){//50个字母一行
                cout<<endl;
            }
            if(j<table.size()&&i==table[j]){//table留下的是好人
                j++;
                cout<<"G";
            }
            else{
                cout<<"B";
            }
        }
        cout<<endl;//留一个空行
    }
    return 0;
}