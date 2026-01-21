#include <thread>
#include <iostream>

int main() {
  std::thread task([](){
    std::cout << "Working...." << std::endl;
  });
  task.join();
}