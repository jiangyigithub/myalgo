#include <iostream>
#include <memory>
 
int main() {
  auto p = std::make_shared<int>(4);
  auto p3 = std::shared_ptr<int>(new int(4));
  int a = p3.use_count();
  auto p1 = p;
  std::cout << "p use_count: " << p.use_count() << "\n";
  auto p2 = std::move(p);
  std::cout << "p use_count: " << p1.use_count() << "\n";
  return 0;
}
 