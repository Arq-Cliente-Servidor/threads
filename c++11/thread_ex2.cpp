#include <iostream>
#include <thread>

// This function will be called from a thread
void call_from_thread(int tid) {
  std::cout << "Launched by thread " << tid << std::endl;
}

static const int num_thread = 10;

int main() {
  std::thread t[num_thread];

  // Launch a group of threads
  for (int i = 0; i < num_thread; i++) {
    t[i] = std::thread(call_from_thread, i);
  }

  std::cout << "Launched from the main\n";

  // Join the threads with the main thread
  for (int i = 0; i < num_thread; i++) {
    t[i].join();
  }

  return 0;
}
