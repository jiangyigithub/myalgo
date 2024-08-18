	Jiang Yi
======

#### Data enthusiast with a strong background in math, science and programming. 
###### [ [sdsawtelle.github.io](http://sdsawtelle.github.io) ] . [ sonya.sawtelle@yale.edu ] . [ 802 461 3429 ]


Education
---------
**Ph.D. program in Applied Physics, Yale University** (2012-present)

- Research on transport in metal nanostructures. 
- Coursework in physics, engineering, and statistics.

**B.S. in Physics, Indiana University** (2008-2011)

- Baccalaureate with Departmental Honors and Highest Distinction, 3.98/4.0 GPA

**MOOCs** (ongoing)

- Machine Learning (Stanford, Andrew Ng)

Experience
---------
**Independent Researcher, Yale University** (2012-present, New Haven CT)

- Data analysis and simulation in Python and MATLAB, and instrument control in C++. Designed and executed experiments across four projects and managed several undegraduate students.

**MCAT Instructor, Kaplan Test Prep** (2011-2012, New Haven CT)

- Planned and delivered lectures on core content in undergraduate Physics, Chemistry and Biology to medium-sized groups of undergraduates.

Skills
------
**Programming:** Python, MATLAB, SQL, R, git, HTML/CSS

**Python SciPy Tools:** Pandas, Numpy, Matplotlib, Scikit-learn

Awards
------
- **Sterling Prize Fellowship**, Yale University (2013). Awarded to 30 out of 10,500 applicants.
- **IU Founders Scholar**, Indiana University (2012)
- **Baccalaureate with Highest Distinction**, Indiana University (2012). Granted to 5 students out of 498 in the class.

Projects
--------
**[*Evening Sessions: Explorations in Data Science and Python* Blog](http://sdsawtelle.github.io/blog/output/index.html)** (2015-present)

- Authored a series of articles covering a wide variety of topics and tools related to pure Python programming, data science and statistics.  
    
    
   ## `concept and arch design`
	1. 系统和软件架构，OBU通信filter，路侧传感器拓扑，monitor concept,车内软件架构(ADAS域控的责任人)
   
   ## `software development`
   1. 软件算法原型开发(整体架构主要包括感知,behavior plan,规划控制,HMI显示)部分:
    - 路侧感知（视觉+激光雷达 待补充）--> 下半年要去做
    - 路侧信号前处理,时间同步
    - 融合策略，路侧感知融合，建立统一的环境模型，拓展系统和软件架构，OBU通信filter，路侧传感器拓扑，monitor车内软件架构FOV
    - 行为behaviror pediction(概率图模型), behavior evaluation metric
    - 功能状态机
    - 路径规划（Dale）--> 不要花精力
    - 控制（Dale）--> 不要花精力
   
   ## 商业/sales
   * english --> 需要去做
   * 沟通，销售自己 --> 需要去做
   * 错误的商业模式
   
   ## 工具需求 --> 不要花精力
   * `serialization and deserialization` --> mdf-exporter
   * `replay` --> selena
   * `visulization` --> plotstr
   * `evaluation` --> snoopy/PT2015
   
   ## `deployment for  target hardware` --> 不要花精力
    * 算法软件部署和迭代和优化，schedule, run time analysis,bus load,RAM resource，software QA,CI(CLARA)
  
  ICV基于路侧感知的高阶自动驾驶预研项目：
  `痛点`：
  红绿灯被遮挡和红绿灯识别力不足
  目标被遮挡和目标识别力不足或太远


## 车路协同的高阶辅助驾驶POC项目 + 无锡（锡山）“双智”试点核心区项目   　　
项目介绍：通过车路协同技术拓展车路感知能力，实现智能网联汽车DAY1/DAY2相关功能，如协作式匝道汇入，协作式自适应巡航，超视距信息辅助等。项目中我主要负责车内软件功能架构的设计和感知融合部分的软件开发工作。
1. 参与车内软件架构的设计和定义。如协作式匝道汇入，协作式自适应巡航，超视距信息辅助等功能对感知，决策，控制模块的需求软件架构和新功能模块设计和软件需求
2. 负责相应模块的软件开发和测试 ，如 路侧信号前处理,时间同步，设计感知融合策略融合路侧目标，建立统一的环境模型
3. 软件优化和模块解耦，使其适用于ROS2原型和嵌入式硬件平台
4. 算法嵌入式硬件软件部署，软件部署于博世量产平台，解决如schedule, run time,bus load,RAM resource等问题
5. 与相关子系统相关负责人沟通的需求，如OBU通信 filter，路侧传感器拓扑等
6. 培训新人，帮助新成员的项目所需技术栈

项目中应用的技术或工具，C++，python，linux，GTest, ROS2, CMake, Vector Tool等

---

## CN ICV Collabrative Vehicle-Road Side System POC + Wuxi ICV Pilot Zone Ecosystem 

This project is about collaborative vehicle-roadside system , this system extend the perception skills of in-vehicle system, enable intelligent connected vehicle to perceive their environment with smart infrastructure data, to enhance user experience & availability. we develop DAY1/DAY2 ADAS feature such as collaborative adaptive cruise control, collaborative ramp merge-in features.In this project, I am responsible for the software architecture design and the software development of perception fusion part.

1. the design of software architecture for in-vehicle function module 
2. software development and test for fusion part, include the preprocessing of road side data, time sync,object fusion 
3. software optimization and software decouple, make efforts to our system adapt to prototype system and embedded system.
4. deployment the system into the target hardware,solve these issue such as scheduling, run time,bus loading, RAM resource
5. the requirement for related system ,such as On-Board Unit, road side perception unit
6. training and build technical stack for new employees

Tools: C++，python，linux，GTest, ROS2, CMake, Vector Tool


