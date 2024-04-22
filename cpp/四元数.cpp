#include <iostream>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

/**
 * 已经坐标系A的q1,t1和坐标系B的q2,t2;p点在坐标系A的坐标为p1，求p点到坐标系B的坐标p2
 * 假设p点在世界坐标系中的坐标表示为P
 * 方程组为:
 * q1*P+t1=p1
 * q2*P+t2=p2
 * 求解p2:
 * p2=q2*q1的逆*(p1-t1)+t2
*/

int main(){
    Eigen::Quaterniond q1 = Eigen::Quaterniond(0.35,0.2,0.3,0.1).normalized();
    Eigen::Quaterniond q2 = Eigen::Quaterniond(-0.5,0.4,-0.1,0.2).normalized();

    Eigen::Vector3d t1 = Eigen::Vector3d(0.3,0.1,0.1);
    Eigen::Vector3d t2 = Eigen::Vector3d(-0.1,0.5,0.3);

    Eigen::Vector3d p1 = Eigen::Vector3d(0.5,0.1,0.2);
    Eigen::Vector3d p2;

    p2=q2*q1.inverse()*(p1-t1)+t2;
    std::cout<<p2.transpose()<<std::endl;
}