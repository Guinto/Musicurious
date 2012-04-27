#include "ObjectCollection.h"

void ObjectCollection::add(Object *o) {
   collection.push_back(o);
}

void ObjectCollection::erase(int index) {
   collection.erase(collection.begin() + index);
}

int ObjectCollection::size() {
   return collection.size();
}

Object* ObjectCollection::get(int index) {
   return collection[index];
}
