#ifndef wait_h
#define wait_h

#include <Arduino.h>

class wait
{
public:

  void time(uint32_t duration_ms);
  void restart(uint32_t duration_ms);
  operator bool();

  uint32_t duration() const                 {return this->_duration;}
  uint32_t timeElapsed() const           {return millis() - this->_millis;}

  bool     isActive() const              {return timeElapsed() <  duration();}
  bool     isEnd() const            {return timeElapsed() >= duration();}
  uint32_t remainingTime() const          {return isEnd() ? 0 : duration() - timeElapsed();}

  void repel(uint32_t duration_ms);

private:

  uint32_t _millis;
  uint32_t _duration;

};

#endif
