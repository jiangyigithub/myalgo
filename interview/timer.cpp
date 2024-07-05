#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class Timer {
public:
    // Constructor: Initializes the timer with the current time and sets elapsed to false
    Timer(int duration) //需要动态初始化
        : start_time(std::chrono::steady_clock::now()), elapsed(false), duration(duration) {}
    
    // Resets the timer to the current time and sets elapsed to false
    void reset() {
        start_time = std::chrono::steady_clock::now();
        elapsed = false;
    }
    
    // Updates the elapsed status based on the elapsed time since the timer was last reset
    void tick() {
        auto now = std::chrono::steady_clock::now();  // Get the current time
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();  // Calculate the elapsed time in milliseconds
        if (elapsed_ms >= duration) {  // Check if the elapsed time exceeds the predefined duration
            elapsed = true;  // Set elapsed to true if the duration has been met or exceeded
        }
    }
    
    // Returns whether the predefined duration has elapsed
    bool isElapsed() const {
        return elapsed;
    }
    
private:
    std::chrono::steady_clock::time_point start_time;  // Stores the start time of the timer
    bool elapsed;  // Indicates whether the predefined duration has elapsed
    int duration;  // Duration in milliseconds
};

struct DrivingHMIIn {
    unsigned int m_ADAS_enum_HNOPScenariosReminder;
};

struct SomeIPTx {
    struct ADAS_strt_HNOPfunctionInfo {
        unsigned int m_HNOPScenariosReminder;
    } m_ADAS_strt_HNOPfunctionInfo;
};

namespace valout {
    namespace ADAS_enum_HNOPScenariosReminder {
        const unsigned int None = 0u;
        const unsigned int Static_Obstacle = 1u;
        const unsigned int Ready_to_pass_through_large_curvature = 2u;
        const unsigned int Oversized_Vehicle_One_Side = 3u;
    }
}

int main() {
    DrivingHMIIn drivinghmi_in;
    SomeIPTx l_someipTx;
    Timer m_sendScenariosReminderTimer(3000);
    bool m_ScenariosReminder = false;

    // 测试1: 输入信号为1
    drivinghmi_in.m_ADAS_enum_HNOPScenariosReminder = 1u;
    std::cout << "测试1: 输入信号为1" << std::endl;

    for (int i = 0; i < 10; ++i) {
        if ((drivinghmi_in.m_ADAS_enum_HNOPScenariosReminder == 1u) ||
            (drivinghmi_in.m_ADAS_enum_HNOPScenariosReminder == 2u) ||
            (drivinghmi_in.m_ADAS_enum_HNOPScenariosReminder == 3u))
        {
            m_ScenariosReminder = true;
            m_sendScenariosReminderTimer.reset();
        } else {
            // do nothing
        }

        if (m_ScenariosReminder)
        {
            m_sendScenariosReminderTimer.tick();
            if (m_sendScenariosReminderTimer.isElapsed())
            {
                m_ScenariosReminder = false;
                m_sendScenariosReminderTimer.reset();
                l_someipTx.m_ADAS_strt_HNOPfunctionInfo.m_HNOPScenariosReminder = valout::ADAS_enum_HNOPScenariosReminder::None;
            } else {
                if (drivinghmi_in.m_ADAS_enum_HNOPScenariosReminder == 1u)
                {
                    l_someipTx.m_ADAS_strt_HNOPfunctionInfo.m_HNOPScenariosReminder = valout::ADAS_enum_HNOPScenariosReminder::Static_Obstacle;
                } 
                else if (drivinghmi_in.m_ADAS_enum_HNOPScenariosReminder == 2u)
                {
                    l_someipTx.m_ADAS_strt_HNOPfunctionInfo.m_HNOPScenariosReminder = valout::ADAS_enum_HNOPScenariosReminder::Ready_to_pass_through_large_curvature;
                } 
                else if (drivinghmi_in.m_ADAS_enum_HNOPScenariosReminder == 3u)
                {
                    l_someipTx.m_ADAS_strt_HNOPfunctionInfo.m_HNOPScenariosReminder = valout::ADAS_enum_HNOPScenariosReminder::Oversized_Vehicle_One_Side;
                } 
                else {
                }
            }
        }

        // 模拟一帧的时间间隔
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // 在第1秒后将信号设置为0
        if (i == 0) {
            drivinghmi_in.m_ADAS_enum_HNOPScenariosReminder = 0;
        }

        // 输出结果
        std::cout << "第" << i + 1 << "秒，m_HNOPScenariosReminder = " 
                  << l_someipTx.m_ADAS_strt_HNOPfunctionInfo.m_HNOPScenariosReminder << std::endl;
    }

    return 0;
}
