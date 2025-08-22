#ifndef CPPM_HOMEWORKS_COUNTER_H
#define CPPM_HOMEWORKS_COUNTER_H

class Counter {
private:
    int value;

public:
    Counter() : value(1) {}

    Counter(int initialValue) : value(initialValue) {}

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int getValue() const {
        return value;
    }
};


#endif //CPPM_HOMEWORKS_COUNTER_H
