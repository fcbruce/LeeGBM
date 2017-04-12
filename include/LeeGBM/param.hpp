/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 11 Apr 2017 20:34:50
 *
 */
#ifndef LEEGBM_PARAM_HPP
#define LEEGBM_PARAM_HPP

#include <string>

namespace LeeGBM 
{

class Param
{
public:
  std::string objective;
  float learning_rate;
  float subsample_rate;
  float column_rate;
  int min_child_weight;
  int max_tree_deepth;
}; // class Param

} // namespace LeeGBM

#endif
