#ifndef _UTILS_LISTS_ITERABLE_LIST_H_
#define _UTILS_LISTS_ITERABLE_LIST_H_
#include "Iterator.h"

namespace Utils {
  namespace Lists {
    template<class Type>
    class IterableList {
      protected:
        IterableList() {}
      public:
        virtual ~IterableList() {}
        virtual Iterator<Type>* createIterator() const = 0;
    };
  }
}

#endif