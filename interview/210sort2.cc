#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>

using namespace std;

struct TestCase {
    int numCourses;
    vector<pair<int, int>> prerequisites;
    vector<int> expectedOrder;
};

vector<int> findCourseOrder(int numCourses, vector<pair<int, int>>& prerequisites, unordered_map<int, vector<int>>& graph) {
    vector<int> inDegree(numCourses, 0);
    
    for (auto& prereq : prerequisites) {
        int course = prereq.first;
        int preCourse = prereq.second;
        graph[preCourse].push_back(course);
        inDegree[course]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> courseOrder;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        courseOrder.push_back(current);
        
        for (int neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if (courseOrder.size() == numCourses) {
        return courseOrder;
    } else {
        return {}; // Return an empty vector if there is a cycle
    }
}

void printGraph(const unordered_map<int, vector<int>>& graph) {
    cout << "DAG Representation:\n";
    for (const auto& node : graph) {
        cout << node.first << " -> ";
        for (int neighbor : node.second) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void generateDotFile(const unordered_map<int, vector<int>>& graph, const string& filename) {
    ofstream dotFile(filename);
    dotFile << "digraph G {\n";
    for (const auto& node : graph) {
        for (int neighbor : node.second) {
            dotFile << "    " << node.first << " -> " << neighbor << ";\n";
        }
    }
    dotFile << "}\n";
    dotFile.close();
}

void runTests(vector<TestCase>& testCases) {
    for (size_t i = 0; i < testCases.size(); ++i) {
        unordered_map<int, vector<int>> graph;
        vector<int> result = findCourseOrder(testCases[i].numCourses, testCases[i].prerequisites, graph);
        
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Number of Courses: " << testCases[i].numCourses << "\n";
        cout << "Prerequisites: ";
        for (auto& prereq : testCases[i].prerequisites) {
            cout << "(" << prereq.first << ", " << prereq.second << ") ";
        }
        cout << "\n";
        printGraph(graph);
        string dotFilename = "graph" + to_string(i + 1) + ".dot";
        generateDotFile(graph, dotFilename);
        cout << "DOT file generated: " << dotFilename << "\n";
        
        cout << "Expected Order: ";
        for (int course : testCases[i].expectedOrder) {
            cout << course << " ";
        }
        cout << "\n";
        cout << "Actual Order: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << "\n";
        
        bool passed = (result == testCases[i].expectedOrder);
        cout << "Test " << (passed ? "PASSED" : "FAILED") << "\n\n";
    }
}

int main() {
    vector<TestCase> testCases = {
        {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 1, 2, 3}},
        {2, {{1, 0}}, {0, 1}},
        {2, {{1, 0}, {0, 1}}, {}}, // This case has a cycle
        {3, {{1, 0}, {2, 0}, {1, 2}}, {0, 2, 1}}
    };
    
    runTests(testCases);

    return 0;
}
