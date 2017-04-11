/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 11 Apr 2017 20:40:44
 *
 */
#ifndef LEE_DATA_HPP
#define LEE_DATA_HPP

#include <vector>

namespace LeeGBM
{

typedef std::vector<std::vector<pair<int, float>>> DataPairs;


class Data
{
public:
  Data(float *data, int nrow, int ncol);
  ~Data();

  DataPairs select_data(float subsample_rate, float column_rate) const;
private:
  DataPairs key_value_pairs; // feature_id - value
  int nrow, ncol;
}; // class Data


} // namespace LeeGBM

#endif
