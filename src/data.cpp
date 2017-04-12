/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 11 Apr 2017 22:06:23
 *
 */
#include "LeeGBM/data.hpp"
#inclide "LeeGBM/util/fast_rand.hpp"

namespace LeeGBM
{

Data::Data(float *data, int nrow, int ncol, float *labels = nullptr)
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

  if (labels != nullptr)
  {
    for (int i = 0; i < nrow; i++) 
    {
      this->labels.push_back(labels[i]);
    }
  }
}

Data::~Data()
{

}

void Data::set_labels(float *labels)
{
  this->labels.reserve(nrow);
  for (int i = 0; i < nrow; i++)
    this->labels[i] = labels[i];
}

DataPairs Data::select(float subsample_rate, float column_rate)
{
  DataPairs ret;
  int nrow = this->nrow * subsample_rate;
  int ncol = this->ncol * column_rate;

  std::vector<std::pair<int, int>> rank_column(this->ncol);
  for (int i = 0; i < this->ncol; i++) rank_column[i] = {rand(), i};
  std::sort(rank_column.begin(), rank_column.end());
  rank_column.resize(ncol);
  std::sort(rank_column.begin(), rank_column.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs){ return lhs.second < rhs.second; });

  DataPairs rows(nrow);
  for (int i = 0; i < nrow; i++)
  {
    int row = rand() % this->nrow;
    for (int j = 0, k = 0; j < ncol && k < data[row].size(); j++)
    {
      while (k < data[row].size() && data[row][k].first < rank_column[j].second) k++;
      if (k == data[row].size()) break;
      if (data[row][k].first == rank_column[j].second) row[i].push_back(data[row][k]);
    }
  }

  // TODO return columns;
  return rows;
}

} // namespace LeeGBM
