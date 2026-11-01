#include <iostream>
#include <vector>
#include <algorithm>
class Target
{
public :
   Target(int Id,double Distance):id(Id),distance(Distance) {};
   int id;
   double distance;
   void show()
   {
       std::cout<<"Id: "<<id<<" "<<"距离相机的距离为: "
       <<distance<<"厘米\n";
   }
};
class TargetManager
{
public :
   std::vector<Target>num;
   void add(Target t)
   {
    num.push_back(t);
   }
   Target get_nearest()
   {
      sort(num.begin(),num.end(),
      [](Target a,Target b)
      {
        return a.distance<b.distance;
      }   
      );
      if(num.size()==0)
      {
         return Target{-1,0.0};
      }
      return num[0];
   }
   void print_all() 
   {
      if(num.size()==0)
      {
          std::cout<<"当前未储存任何数据"<<std::endl;
      }
      else
      {
           for(int i=0;i<num.size();i++)
           {
           std::cout<<"Id: "<<num[i].id<<" "<<"距离相机的距离为: "
           <<num[i].distance<<"厘米\n";
           }
           std::cout<<std::endl;
      }
   }
};
int main()
{
    Target a{1,1.114514};
    Target b{2,3.456};
    Target c{3,1.065};
    Target d{4,2.56};
    TargetManager qaq;
    qaq.print_all();
    qaq.get_nearest().show();
    qaq.add(a);
    qaq.add(b);
    qaq.add(c);
    qaq.add(d);
    std::cout<<"离相机最近的信息: "<<std::endl;
    qaq.get_nearest().show();
    qaq.print_all();
}