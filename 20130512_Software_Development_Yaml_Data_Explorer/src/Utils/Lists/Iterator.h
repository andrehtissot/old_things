#ifndef _UTILS_LISTS_ITERATOR_H_
#define _UTILS_LISTS_ITERATOR_H_

namespace Utils {
  namespace Lists {
    template<class Type>
    class Iterator {
      protected:
        Iterator() {}
      public:
        virtual ~Iterator() {}
        virtual void first() = 0;
        virtual void next() = 0;
        virtual const bool hasNext() = 0;
        virtual Type* getCurrentItem() = 0;
    };
  }
}

#endif