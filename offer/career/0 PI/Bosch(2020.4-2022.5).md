# BOSCH车端软件工作总结
## summary
1. 路侧信号前处理,时间同步
2. 融合策略，路侧感知融合，建立统一的环境模型，拓展FOV
3. 行为behaviror pediction(概率图模型) 
4. behavior evaluation metric
5. 车内软件架构, 系统架构，OBU通信 filter，路侧传感器拓扑
6. 算法软件部署，schedule, run time analysis,bus load,RAM resource
   
## tasks
- RSP
    - time sync
        - autosar master/salve
        - time base and system solution
        - 测试试验
    - space sync/coordinate transform
        - 法规WGS84/02 
        - GPS -->ENU --> local frame(reference point)
    - ROI and delete ego
        - 对向车道
        - 后方车辆
        - delete ego
    - ego state buffer
        - store ego pose for multitude sources sensor(ego localization+ road side perception)
        - ego velocity/acceleration
- FUSION 
    - RSS object latency may be large
        - out of sequence handle
        - predict measurement algorithm
    - localization accuracy
        - yaw accuracy effect the object state for fusion
    - 3D object fusion algorithm
        - generate dep object only
        - gating parameter , velocity gate do not passed
    - DEP ROI range only cover front objects, but Road Side Sensor have different 
        - original ROI is too small, tuning the parameter of ROI for far range road side object
    - EIMTPR only send radar only object and radar vision fused object 
        - cancel restrict condition for output fusion object
- RSI
    - object lane-map relation association
        - 判断目标行为（在那个车道，是否变道）
        - 概率图模型
    - object behavior estimation
        - constant velocity model
    - ego behavior estimation
        - ego state estimation
    - object selection
        - choose most critical object from multitude object scenario.
    - situation evaluation
        - comfortable metric --> delta TTX
- 软件ARCH和方案设计
    - cooperate perception 
    - safety traffic light
- Tool-chain(selena/plotstr/mdf-exporter)
    - selena
    - plotstr
    - mdf-exporter
    - lauterbash
- De-couple in-vehicle software for business
    - experience benefit for future arch
    - software module decouple


## hard skills
- C++
  - OO
  - STL
  - C++ 11
- python
- C++ tool chain
  - CMAKE
  - GTEST
- ADAS algorithm
- AI


## soft skills
- communication
- English
  - longman 3000
- presentation
  - PPT