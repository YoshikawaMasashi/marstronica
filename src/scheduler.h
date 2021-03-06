// Copyright[2019] <marshi(masashi yoshikawa)>
#pragma once

#include <chrono>
#include <map>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class Scheduler {
 private:
    bool is_running = false;
    std::chrono::system_clock::time_point start_time =
      std::chrono::system_clock::now();
    double step_second = 0.0001;
    std::map<double, std::vector<std::function<void(void)>>> task_queue;
    double bpm = 120;
    std::mutex is_running_mutex;
    std::mutex task_queue_mutex;
    std::thread scheduling_thread;
    void set_is_running(bool);
 public:
    Scheduler();
    ~Scheduler();
    void schedule();
    void start();
    void stop();
    void add_task(double, std::function<void(void)>);
    double get_bpm();
    double now_seconds();
    double now_beats();
    double seconds_to_beats(double);
    double beats_to_seconds(double);
};
