/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 * Time : Wed 12 Apr 2017 13:23:57
 *
 */
#ifndef LEEGBM_FAST_RAND_HPP
#define LEEGBM_FAST_RAND_HPP

// Reference: https://en.wikipedia.org/wiki/Xorshift

static uint32_t __seed = 0x43215678;

inline void set_seed(uint32_t seed)
{
  __seed = seed;
}

inline uint32_t rand_u32()
{
  uint32_t x = __seed;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return __seed = x;
}

inline int rand()
{
  return 0x7fffffff & rand_u32();
}


#endif
