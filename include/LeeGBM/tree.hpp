/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 11 Apr 2017 20:25:19
 *
 */
#ifndef LEEGBM_TREE_HPP
#define LEEGBM_TREE_HPP

namespace LeeGBM 
{

class Tree
{
public:
  Tree();
  ~Tree();
  float* predict(const Data &data) const;

private:
  TreeNode *root;
}; // class Tree

class TreeNode
{
public:
  TreeNode();
  ~TreeNode();
private:
  int feature_id;
  float threshold;
  float score;
  TreeNode *leftchild;
  TreeNode *rightchild;
}; // class TreeNode

} // namespace LeeGBM

#endif
