#include <pthread.h>
#include "ParallexFeedback360.hpp"

ParallexFeedback360 *test;

void *test_method(void *arg) {
    test = new ParallexFeedback360(12);

    while (1) {}
}

int main() {
    pthread_t test_thread_id;
    pthread_create(&test_thread_id, NULL, test_method, NULL);

    return 0;
    pthread_exit(NULL);
}