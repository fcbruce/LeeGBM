/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 11 Apr 2017 22:06:23
 *
 */
#include "LeeGBM/data.hpp"

namespace LeeGBM
{

Data::Data(float *data, int nrow, int ncol)
{
  this->key_value_pairs.reserve(nrow);
  this->nrow = nrow;
  this->ncol = ncol;

  for (int i = 0; i < nrow; i++)
  {
    for (int j = 0; j < ncol; j++)
    {
      float &x = data[i * ncol + j];
      if (x == x) this->key_value_pairs[i].push_back(std::make_pair(j, x));
    }
  }
}

Data::~Data()
{

}

DataPairs Data::select(float subsample_rate, float column_rate)
{
  DataPairs ret;
  int nrow = this->nrow * subsample_rate;
  int ncol = this->ncol * column_rate;


  // TODO Select the instances & features

}

} // namespace LeeGBM
