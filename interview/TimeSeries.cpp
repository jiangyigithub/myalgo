#include <vector>
#include <stdexcept>
#include <iostream>

struct Time {
    double value;
    
    Time operator+(double dt) const {
        return Time{value + dt};
    }
    
    Time operator-(const Time& other) const {
        return Time{value - other.value};
    }
    
    bool operator<=(const Time& other) const {
        return value <= other.value;
    }
    
    bool operator<(const Time& other) const {
        return value < other.value;
    }
    
    bool operator>=(const Time& other) const {
        return value >= other.value;
    }
};

struct TimeSeriesPoint
{
    Time time;
    double value;
};

// A TimeSeries is a list of TimeSeriesPoint data, with data elements associated to a particular time. TimeSeries data can be interpolated.
typedef std::vector<TimeSeriesPoint> TimeSeries;

/// @brief Return interpolated value. Weight in [0.0, 1.0]
/// @param before 
/// @param after 
/// @param weight 
/// @return 
TimeSeriesPoint interpolate(TimeSeriesPoint const &before, TimeSeriesPoint const &after, double weight)
{
    TimeSeriesPoint result;
    result.time = Time{before.time.value + (after.time.value - before.time.value) * weight}; // Interpolate time
    result.value = before.value + (after.value - before.value) * weight; // Interpolate value
    return result;
}

/// @brief Implement a function to sample a TimeSeries at a particular time. Assume that the input time is within the TimeSeries:
/// @param time_series 
/// @param desired_time 
/// @return 
TimeSeriesPoint sample(TimeSeries const &time_series, Time const &desired_time)
{
    if (time_series.size() < 2)
    {
        throw std::invalid_argument("TimeSeries must contain at least two points.");
    }

    for (size_t i = 0; i < time_series.size() - 1; ++i)
    {
        const TimeSeriesPoint &before = time_series[i];
        const TimeSeriesPoint &after = time_series[i + 1];

        if (before.time <= desired_time && desired_time <= after.time)
        {
            double total_duration = after.time.value - before.time.value;
            double elapsed = desired_time.value - before.time.value;
            double weight = elapsed / total_duration;

            return interpolate(before, after, weight);
        }
    }
    /// 如果时间点超出时间序列的范围，抛出 std::out_of_range 异常
    throw std::out_of_range("Desired time is out of range.");
}

/// @brief resample a TimeSeries, returning a uniformly sampled series.
/// @param time_series 
/// @param dt 
/// @param resampled_series 
void resample(TimeSeries const &time_series, double dt, TimeSeries *resampled_series)
{
    if (time_series.size() < 2)
    {
        throw std::invalid_argument("TimeSeries must contain at least two points.");
    }

    Time start_time = time_series.front().time;
    Time end_time = time_series.back().time;

    resampled_series->clear();
    for (Time t = start_time; t <= end_time; t = t + dt)
    {
        TimeSeriesPoint sampled_point = sample(time_series, t);
        resampled_series->push_back(sampled_point);
    }
}

/// @brief Implement a function to merge two TimeSeries. The function should return a sorted TimeSeries with the union of all data. 
/// @param ts1 
/// @param ts2 
/// @param merged 
void mergeTimeSeries(TimeSeries const &ts1, TimeSeries const &ts2, TimeSeries *merged)
{
    merged->clear();
    size_t i = 0, j = 0;
    
    while (i < ts1.size() && j < ts2.size()) {
        if (ts1[i].time < ts2[j].time) {
            merged->push_back(ts1[i]);
            i++;
        } else if (ts2[j].time < ts1[i].time) {
            merged->push_back(ts2[j]);
            j++;
        } else {
            // If times are equal, we can choose to ignore one of them. 
            // Here we are adding from ts1 and advancing both pointers.
            merged->push_back(ts1[i]);
            i++;
            j++;
        }
    }
    
    // Append the remaining elements from ts1
    while (i < ts1.size()) {
        merged->push_back(ts1[i]);
        i++;
    }
    
    // Append the remaining elements from ts2
    while (j < ts2.size()) {
        merged->push_back(ts2[j]);
        j++;
    }
}

// Example usage
int main()
{   
    /// 1. test interpolate function 
    TimeSeriesPoint point1 = {Time{0.0}, 10.0};
    TimeSeriesPoint point2 = {Time{1.0}, 20.0};
    TimeSeriesPoint result = interpolate(point1, point2, 0.5);
    std::cout << "Interpolate value at time " << result.time.value << " is " << result.value << std::endl;
    
    /// 2. test sample function 
    TimeSeries time_series = {
        {Time{0}, 0.0},
        {Time{10}, 10.0},
        {Time{20}, 20.0}
    };
    Time desired_time = Time{1.5};
    TimeSeriesPoint sample_out = sample(time_series, desired_time);
    std::cout << "Interpolated value at time " << desired_time.value << " is " << sample_out.value << std::endl;
    
    /// 3. test resample function 
    TimeSeries resampled_series;
    double dt = 2.0;
    resample(time_series, dt, &resampled_series);
    for (const auto& point : resampled_series)
    {
        std::cout << "Time: " << point.time.value << ", Value: " << point.value << std::endl;
    }

    /// 4. test mergeTimeSeries function 
    TimeSeries ts1 = {
        {Time{0}, 0.0},
        {Time{10}, 10.0},
        {Time{20}, 20.0}
    };
    TimeSeries ts2 = {
        {Time{5}, 5.0},
        {Time{15}, 15.0},
        {Time{25}, 25.0}
    };
    TimeSeries merged;
    mergeTimeSeries(ts1, ts2, &merged);
    for (const auto& point : merged)
    {
        std::cout << "Time: " << point.time.value << ", Value: " << point.value << std::endl;
    }

    return 0;
}
