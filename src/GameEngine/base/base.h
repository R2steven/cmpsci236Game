//TODO: factor out general use functions into base

#ifndef GAME236_BASE_H
#define GAME236_BASE_H

template<class T>
inline T clamp(T min, T max, T val)  {
  return max > val ? 
          (min < val ? val : min) 
          : max;
}

#endif