#include <iostream>
#include <thread>
#include <chrono>

class DebounceTimer
{
public:
    DebounceTimer(int duration_ms) : duration(duration_ms), start_time(std::chrono::steady_clock::now()), elapsed(false) {}

    void tick()
    {
        if (elapsed)
            return;
        auto now = std::chrono::steady_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();
        if (elapsed_time >= duration)
        {
            elapsed = true;
        }
    }

    bool isElapsed() const
    {
        return elapsed;
    }

    void reset()
    {
        start_time = std::chrono::steady_clock::now();
        elapsed = false;
    }

private:
    int duration;
    std::chrono::steady_clock::time_point start_time;
    bool elapsed;
};

// Mock classes and enums
namespace valin
{
    enum class E_DrivingDecActSts
    {
        ACTIVE_L3,
        INACTIVE
    };
    enum class E_RBU_PilotBrkDecActSts
    {
        ACTIVE_L3,
        INACTIVE
    };
}

class FSMInputInterface
{
public:
    struct Chassis
    {
        valin::E_DrivingDecActSts m_DrivingDecActSts = valin::E_DrivingDecActSts::INACTIVE;
        valin::E_DrivingDecActSts m_DrivingDecActSts_RE = valin::E_DrivingDecActSts::INACTIVE;
        valin::E_RBU_PilotBrkDecActSts m_RBU_PilotBrkDecActSts = valin::E_RBU_PilotBrkDecActSts::INACTIVE;
        valin::E_RBU_PilotBrkDecActSts m_RBU_PilotBrkDecActSts_RE = valin::E_RBU_PilotBrkDecActSts::INACTIVE;
    } chassis;

    const Chassis &getvalinchassis() const
    {
        return chassis;
    }
};

namespace Longs_States
{
    enum State
    {
        Longs_ActiveControl,
        Longs_ActiveSuspend,
        Longs_DriverRequest,
        Longs_StandActive,
        Longs_Inactive
    };
}

class StateMachines
{
public:
    Longs_States::State m_longState = Longs_States::Longs_ActiveControl;
};

// Global instances
FSMInputInterface fsmInputInterface;
StateMachines stateMachines;

bool m_isBrakeHandShakeFailed = true;
bool debouncedBrakeFail = false;
DebounceTimer m_debounceTimerofNotActive(400);

void debounceBrakeHandShakeFailed()
{

    m_isBrakeHandShakeFailed = (fsmInputInterface.getvalinchassis().m_DrivingDecActSts != valin::E_DrivingDecActSts::ACTIVE_L3) && (fsmInputInterface.getvalinchassis().m_DrivingDecActSts_RE != valin::E_DrivingDecActSts::ACTIVE_L3) && (fsmInputInterface.getvalinchassis().m_RBU_PilotBrkDecActSts != valin::E_RBU_PilotBrkDecActSts::ACTIVE_L3) && (fsmInputInterface.getvalinchassis().m_RBU_PilotBrkDecActSts_RE != valin::E_RBU_PilotBrkDecActSts::ACTIVE_L3);

    bool isHwaActive = (stateMachines.m_longState == Longs_States::Longs_ActiveControl ||
                        stateMachines.m_longState == Longs_States::Longs_ActiveSuspend ||
                        stateMachines.m_longState == Longs_States::Longs_DriverRequest ||
                        stateMachines.m_longState == Longs_States::Longs_StandActive);

    if (isHwaActive && m_isBrakeHandShakeFailed)
    {
        m_debounceTimerofNotActive.tick();
        if (m_debounceTimerofNotActive.isElapsed())
        {
            debouncedBrakeFail = true;
        }
    }
    else
    {

        m_debounceTimerofNotActive.reset();
        debouncedBrakeFail = false;
    }
}

void testDebounceLogic()
{
    // Test setup
    stateMachines.m_longState = Longs_States::Longs_ActiveControl;
    fsmInputInterface.chassis.m_DrivingDecActSts = valin::E_DrivingDecActSts::INACTIVE;
    fsmInputInterface.chassis.m_DrivingDecActSts_RE = valin::E_DrivingDecActSts::INACTIVE;
    fsmInputInterface.chassis.m_RBU_PilotBrkDecActSts = valin::E_RBU_PilotBrkDecActSts::INACTIVE;
    fsmInputInterface.chassis.m_RBU_PilotBrkDecActSts_RE = valin::E_RBU_PilotBrkDecActSts::INACTIVE;

    // Run initial update

    debounceBrakeHandShakeFailed();
    std::cout << "Initial debouncedBrakeFail: " << debouncedBrakeFail << std::endl;

    // Simulate time passing and state changes
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    debounceBrakeHandShakeFailed();
    std::cout << "After 200ms debouncedBrakeFail: " << debouncedBrakeFail << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    debounceBrakeHandShakeFailed();
    std::cout << "After additional 250ms (450ms total) debouncedBrakeFail: " << debouncedBrakeFail << std::endl;

    // Change state to inactive
    stateMachines.m_longState = Longs_States::Longs_Inactive;

    debounceBrakeHandShakeFailed();
    std::cout << "After setting longActive to false debouncedBrakeFail: " << debouncedBrakeFail << std::endl;
}

int main()
{
    testDebounceLogic();
    return 0;
}
