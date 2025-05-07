#include <pthread.h>
#include <time.h>
#include "ParallexFeedback360.hpp"

ParallexFeedback360 *test;

void *test_method(void *arg) {
    test = new ParallexFeedback360(12);
    test->MoveClockwise(100);
    
    while (1) {
        // For ~10ms sleep
        struct timespec ts = {0, 10 * 1000 * 1000};  // 10 million nanoseconds = 10 ms
        nanosleep(&ts, NULL);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t test_thread_id;
    pthread_create(&test_thread_id, NULL, test_method, NULL);
    pthread_join(test_thread_id, NULL);
    return 0;
}