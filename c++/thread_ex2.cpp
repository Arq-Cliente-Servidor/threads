#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string>
#define NUM_THREADS 5

using namespace std;

struct thread_data {
  int thread_id;
  string message;
  thread_data() {}
  thread_data(int id, string msg) : thread_id(id), message(msg) {}
};

void* printHello(void* threadarg) {
  thread_data* my_data;
  my_data = (thread_data*) threadarg;

  cout << "Thread ID: " << my_data->thread_id << endl;
  cout << "Message: " << my_data->message << endl;

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  thread_data td[NUM_THREADS];
  int rc, i;

  for (i = 0; i < NUM_THREADS; i++) {
    td[i] = thread_data(i, "This is a message");
    cout << "main() : creating thread, " << i << endl;
    rc = pthread_create(&threads[i], NULL, printHello, (void*)&td[i]);

    if (rc) {
      cout << "Error: unable to create thread," << rc << endl;
      exit(-1);
    }
  }
  pthread_exit(NULL);
  return 0;
}
