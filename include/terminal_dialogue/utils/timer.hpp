#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <memory>

class Timer {
public:
  using SharedPtr = std::shared_ptr<Timer>;

  Timer()
    : m_start_time { std::chrono::system_clock::now() },
      m_delta_time { 0.0 } {}
  ~Timer() {}

  void Tick() { m_delta_time = std::chrono::system_clock::now() - m_start_time;}
  double GetTime() { return m_delta_time.count(); }
  void Reset() { m_start_time = std::chrono::system_clock::now(); }

private:
  std::chrono::system_clock::time_point m_start_time;
  std::chrono::duration<double> m_delta_time;
};

#endif