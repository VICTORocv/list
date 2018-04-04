//
//  main.cpp
//  list
//
//  Created by 郭悟清 on 2017/3/8.
//  Copyright © 2017年 郭悟清. All rights reserved.
//

#include <iostream>
#include <list>//双向链表
#include <iostream>
#include <algorithm>//提供了大量基于迭代器的非成员模版函数
#include <vector>
using std::vector;

class A
{
private:
    int n;
public:
    A(int n_){n=n_;}
    friend bool operator<(const A &a1,const A &a2);
    friend bool operator==(const A &a1,const A &a2);
    friend std::ostream &operator<<(std::ostream &o,const A &a);//重载左移符号
};
bool operator<(const A &a1,const A &a2)
{
    return a1.n<a2.n;
}
bool operator==(const A &a1,const A &a2)
{
    return a1.n==a2.n;
}
std::ostream &operator<<(std::ostream &o,const A &a)
{
    o<<a.n;
    return o;
}
template <class T>  //定义函数模版
void PrintList(const std::list<T> &lst)
{
    int tmp=lst.size();
    if(tmp>0)
    {
        typename std::list<T>::const_iterator i;
        for(i=lst.begin();i!=lst.end();i++)
        {
            std::cout<<*i<<",";
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::list<A> lst1,lst2;
    lst1.push_back(3);
    lst1.push_back(2);
    lst1.push_back(4);
    lst1.push_back(2);
    lst1.push_front(1);
    int list2[7]={10,20,30,30,30,40,40};
    vector<int> List2(list2,list2+7);
    std::copy(List2.begin(),List2.end(),std::back_inserter(lst2));//将vector复制到list，注意不能直接将数组复制到list!
    std::cout<<"1)";PrintList(lst1);std::cout<<std::endl;
    std::cout<<"2)";PrintList(lst2);std::cout<<std::endl;
    lst2.sort();//list容器的排序函数
    std::cout<<"3)";PrintList(lst2);std::cout<<std::endl;
    lst2.pop_front();//删除头节点
    std::cout<<"4)";PrintList(lst2);std::cout<<std::endl;
    lst1.remove(2);//删除所有和2相等的元素
    std::cout<<"5)";PrintList(lst1);std::cout<<std::endl;
    lst2.unique();//删除所有和前一个元素相等的元素,用来去除临近重复的数据
    std::cout<<"6)";PrintList(lst2);std::cout<<std::endl;
    lst1.merge(lst2);//合并lst2到lst1的尾，并清空lst2
    std::cout<<"7)";PrintList(lst1);std::cout<<std::endl;
    lst1.reverse();//颠倒顺序
    std::cout<<"8)";PrintList(lst1);std::cout<<std::endl;
    lst2.push_back(100);
    lst2.push_back(200);
    lst2.push_back(300);
    lst2.push_back(400);
    std::list<A>::iterator p1,p2,p3;
    p1=find(lst1.begin(),lst1.end(),3);//lst1中3之前的位置
    p2=find(lst2.begin(),lst2.end(),200);
    p3=find(lst2.begin(),lst2.end(),400);
    lst1.splice(p1,lst2,p2,p3);
    //将[p2,p3)插入p1之前，并从lst2中删除[p2,p3)
    std::cout<<"9)";PrintList(lst1);std::cout<<std::endl;
    std::cout<<"10)";
    for(auto& i:lst2)
    {
        std::cout<<i<<",";
    }
    std::cout<<std::endl;
    return 0;
}
