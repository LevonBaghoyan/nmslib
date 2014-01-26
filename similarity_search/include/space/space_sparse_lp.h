/**
 * Non-metric Space Library
 *
 * Authors: Bilegsaikhan Naidan (https://github.com/bileg), Leonid Boytsov (http://boytsov.info).
 * With contributions from Lawrence Cayton (http://lcayton.com/).
 *
 * For the complete list of contributors and further details see:
 * https://github.com/searchivarius/NonMetricSpaceLib 
 * 
 * Copyright (c) 2014
 *
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */

#ifndef _SPACE_SPARSE_LP_H_
#define _SPACE_SPARSE_LP_H_

#include <string>
#include <map>
#include <stdexcept>

#include <string.h>
#include "global.h"
#include "object.h"
#include "utils.h"
#include "space.h"
#include "space_lp.h"
#include "space_sparse_vector.h"

#define SPACE_SPARSE_L     "lp_sparse"
#define SPACE_SPARSE_LINF  "linf_sparse"
#define SPACE_SPARSE_L1    "l1_sparse"
#define SPACE_SPARSE_L2    "l2_sparse"

namespace similarity {

template <typename dist_t>
class SpaceSparseLp : public SpaceSparseVector<dist_t> {
 public:
  explicit SpaceSparseLp(dist_t p) : distObj_(p) {}
  virtual ~SpaceSparseLp() {}

  virtual std::string ToString() const;

 protected:
  virtual dist_t HiddenDistance(const Object* obj1, const Object* obj2) const;
 private:
  SpaceLpDist<dist_t> distObj_;
};


}  // namespace similarity

#endif 
