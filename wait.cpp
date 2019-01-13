#include <Arduino.h>
#include "wait.h"

void wait::time(uint32_t duration_ms)
{
  this->_duration = duration_ms;
  this->_millis = millis();
}

void wait::restart(uint32_t duration_ms)
{
  this->_millis += this->_duration;
  this->_duration = duration_ms;
}

void wait::repel(uint32_t duration_ms)
{
  this->_duration += duration_ms;
}

wait::operator bool()
{
  bool end = this->isEnd();
  if (end) this->_millis += this->_duration;;
  return end;
}
