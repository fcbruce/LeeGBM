/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 11 Apr 2017 20:14:54
 *
 */
#ifndef LEEGBM_GBM_HPP
#define LEEGBM_GBM_HPP

#include <vector>

#include "./tree.hpp"

namespace LeeGBM 
{

class GBM
{
public:
  GBM();
  ~GBM();

private:
  Objective *obj_func;
  std::vector<Tree> trees;

}; // class GBM

} // namespace LeeGBM

#endif
