#include <iostream>
#include <memory>>

class CameraSimulator
{
    public :
    int camera_id;
    CameraSimulator(int id)
    {
        camera_id=id;
        std::cout<<"相机已连接"<<std::endl;
    }
    ~CameraSimulator()
    {
        std::cout<<"相机已断开"<<std::endl;
    }
};
int  main()
{
    std::shared_ptr<CameraSimulator> 
    qaq=std::make_shared<CameraSimulator>(10086);
    
}