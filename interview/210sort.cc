#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

struct TestCase {
    int numCourses;
    vector<pair<int, int>> prerequisites;
    vector<int> expectedOrder;
};

// Function to perform topological sort
vector<int> findCourseOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    // Create an adjacency list to represent the graph
    unordered_map<int, vector<int>> graph;
    // Create a vector to store the in-degree of each node
    vector<int> inDegree(numCourses, 0);
    
    // Build the graph and in-degree vector
    for (auto& prereq : prerequisites) {
        int course = prereq.first;
        int preCourse = prereq.second;
        graph[preCourse].push_back(course);
        inDegree[course]++;
    }
    
    // Create a queue to process nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    // List to store the topological order
    vector<int> courseOrder;
    
    // Process the graph
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        courseOrder.push_back(current);
        
        // Decrease the in-degree of adjacent nodes
        for (int neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // Check if topological sort is possible
    if (courseOrder.size() == numCourses) {
        return courseOrder;
    } else {
        return {}; // Return an empty vector if there is a cycle
    }
}

void runTestCases(vector<TestCase>& testCases) {
    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Running test case " << i + 1 << ":\n";
        cout << "Number of courses: " << testCases[i].numCourses << "\n";
        cout << "Prerequisites: ";
        for (const auto& prereq : testCases[i].prerequisites) {
            cout << "(" << prereq.first << ", " << prereq.second << ") ";
        }
        cout << "\n";
        cout << "Expected order: ";
        for (const int course : testCases[i].expectedOrder) {
            cout << course << " ";
        }
        cout << "\n";
        
        vector<int> actualOrder = findCourseOrder(testCases[i].numCourses, testCases[i].prerequisites);
        
        cout << "Actual order: ";
        for (const int course : actualOrder) {
            cout << course << " ";
        }
        cout << "\n";
        
        bool passed = (actualOrder == testCases[i].expectedOrder);
        cout << "Test " << (passed ? "PASSED" : "FAILED") << "\n\n";
    }
}

int main() {
    vector<TestCase> testCases = {
        {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 1, 2, 3}},
        {2, {{1, 0}}, {0, 1}},
        {2, {{1, 0}, {0, 1}}, {}}, // Cycle case
        {6, {{1, 0}, {2, 1}, {3, 2}, {4, 3}, {5, 4}}, {0, 1, 2, 3, 4, 5}},
        {3, {{1, 0}, {2, 1}}, {0, 1, 2}}
    };
    
    runTestCases(testCases);

    return 0;
}
