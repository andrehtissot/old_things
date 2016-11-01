#ifndef _UTILS_LISTS_LINKED_LIST_H_
#define _UTILS_LISTS_LINKED_LIST_H_
#include "IterableList.h"

namespace Utils {
  namespace Lists {
    template<class Type>
    class LinkedList : public IterableList<Type> {
      private:
        class LinkedListElement {
          private:
            Type* element;
            LinkedListElement* nextLinkedListElement;
          public:
            LinkedListElement(Type* element) {
              this->nextLinkedListElement = NULL;
              this->element = element;
            }
            ~LinkedListElement(){}
            Type* getElement() const {
              return this->element;
            }
            void setElement(Type* const element) {
              this->element = element;
            }
            LinkedListElement* getNextLinkedListElement() const {
              return nextLinkedListElement;
            }
            void setNextLinkedListElement(LinkedListElement* const linkedListElement) {
              this->nextLinkedListElement = linkedListElement;
            }
        };
        class LinkedListIterator : public Iterator<Type> {
          private:
            LinkedListElement* firstLinkedListElement;
            LinkedListElement* currentLinkedListElement;
          public:
            LinkedListIterator(LinkedListElement* firstLinkedListElement) : Iterator <Type>(){
              this->currentLinkedListElement = this->firstLinkedListElement = firstLinkedListElement;
            }
            ~LinkedListIterator(){}
            void first(){
              this->currentLinkedListElement = this->firstLinkedListElement;
            }
            void next(){
              if(this->currentLinkedListElement == NULL)
                return;
              this->currentLinkedListElement = this->currentLinkedListElement->getNextLinkedListElement();
            }
            const bool hasNext(){
              if(this->currentLinkedListElement == NULL)
                return false;
              return this->currentLinkedListElement->getNextLinkedListElement() != NULL;
            }
            Type* getCurrentItem(){
              if(this->currentLinkedListElement == NULL)
                return NULL;
              return this->currentLinkedListElement->getElement();
            }
        };
        LinkedListElement* firstLinkedListElement;
        LinkedListElement* lastLinkedListElement;

      public:
        LinkedList() : IterableList <Type>(),
          firstLinkedListElement(NULL),
          lastLinkedListElement(NULL) {
        }
        virtual ~LinkedList() {
          this->removeAll();
        }
        void append(Type* const element) {
          LinkedListElement* newLinkedListElement = new LinkedListElement(element);
          if(this->lastLinkedListElement == NULL) {
            this->firstLinkedListElement = this->lastLinkedListElement = newLinkedListElement;
          } else {
            this->lastLinkedListElement->setNextLinkedListElement(newLinkedListElement);
            this->lastLinkedListElement = newLinkedListElement;
          }
        }
        Type* get(int const position) const {
          if(position < 0)
            return NULL;
          LinkedListElement* linkedListElement = this->firstLinkedListElement;
          if(linkedListElement == NULL)
            return NULL;
        	for(int i = 0; i < position; i++){
            linkedListElement = linkedListElement->getNextLinkedListElement();
            if(linkedListElement == NULL)
              return NULL;
          }
          return linkedListElement->getElement();
        }
        void insert(Type* const element, int const position) {
          if(position < 0)
            return;
          LinkedListElement* linkedListElement = this->firstLinkedListElement;
          int currentPosition = 0;
          for(;currentPosition < (position-1) && linkedListElement != NULL; currentPosition++)
            linkedListElement = linkedListElement->getNextLinkedListElement();
          if(linkedListElement == NULL){
            for(int i = 0; (position - currentPosition) > i; i++)
              this->append(NULL);
            this->append(element);
            return;
          }
          LinkedListElement* nextLinkedListElement = linkedListElement->getNextLinkedListElement();
          if(nextLinkedListElement == NULL) {
            this->append(element);
            return;
          }
          LinkedListElement* newLinkedListElement = new LinkedListElement(element);
          newLinkedListElement->setNextLinkedListElement(nextLinkedListElement);
          linkedListElement->setNextLinkedListElement(newLinkedListElement);
        }
        const int indexOf(Type* const element) const {
          LinkedListElement* linkedListElement = firstLinkedListElement;
          int currentIndex = 0;
          while(linkedListElement != NULL){
            if(linkedListElement->getElement() == element)
              return currentIndex;
            currentIndex++;
            linkedListElement = linkedListElement->getNextLinkedListElement();
          }
          return -1;
        }
        void remove(int const position, bool deleteElement = false){
          if(position < 0 || this->firstLinkedListElement == NULL)
            return;
          if(position == 0){
            if(deleteElement && this->firstLinkedListElement->getElement() != NULL)
              delete(this->firstLinkedListElement->getElement());
            this->firstLinkedListElement->setElement(NULL);
            return;
          }
          LinkedListElement* linkedListElementBefore = this->firstLinkedListElement;
          int currentPosition = 0;
          for(;currentPosition < (position-1) && linkedListElementBefore != NULL; currentPosition++)
            linkedListElementBefore = linkedListElementBefore->getNextLinkedListElement();
          if(linkedListElementBefore == NULL)
            return;
          LinkedListElement* foundLinkedListElement = linkedListElementBefore->getNextLinkedListElement();
          if(foundLinkedListElement == NULL)
            return;
          LinkedListElement* nextLinkedListElement = foundLinkedListElement->getNextLinkedListElement();
          if(nextLinkedListElement == NULL){
            this->lastLinkedListElement = linkedListElementBefore;
            linkedListElementBefore->setNextLinkedListElement(NULL);
            if(deleteElement && foundLinkedListElement->getElement() != NULL)
              delete(foundLinkedListElement->getElement());
            delete(foundLinkedListElement);
            return;
          }
          if(deleteElement && foundLinkedListElement->getElement() != NULL)
            delete(foundLinkedListElement->getElement());
          foundLinkedListElement->setElement(NULL);
        }
        void removeAll(bool deleteElements = false) {
          LinkedListElement* nextLinkedListElement = firstLinkedListElement;
          LinkedListElement* linkedListElementToDelete;
          while(nextLinkedListElement != NULL){
            linkedListElementToDelete = nextLinkedListElement;
            nextLinkedListElement = linkedListElementToDelete->getNextLinkedListElement();
            if(deleteElements && (linkedListElementToDelete->getElement() != NULL))
              delete(linkedListElementToDelete->getElement());
            delete(linkedListElementToDelete);
          }
          this->firstLinkedListElement = this->lastLinkedListElement = NULL;
        }
        Iterator<Type>* createIterator() const {
          return new LinkedListIterator(this->firstLinkedListElement);
        }
        const int count() const {
          int total = 0;
          LinkedListElement* linkedListElement = firstLinkedListElement;
          while(linkedListElement != NULL){
            total++;
            linkedListElement = linkedListElement->getNextLinkedListElement();
          }
          return total;
        }
    };
  }
}
#endif