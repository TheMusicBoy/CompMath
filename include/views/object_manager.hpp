#ifndef _VIEWS_OBJECT_MANAGER_HPP_
#define _VIEWS_OBJECT_MANAGER_HPP_

#include <list>
#include <memory>

namespace vw {

////////////////////////////////////////////////////////////////
// \brief Object that used to manage objects.
////////////////////////////////////////////////////////////////
template <typename Ty>
class ObjectManager {
 protected:
    using ptr = Ty*;

    std::list<ptr> objects_;  // list of objects

 public:
    using pos  = typename std::list<ptr>::iterator;
    using cpos = typename std::list<ptr>::const_iterator;

    // Default constructor
    ObjectManager() = default;
    // Copy constructor
    ObjectManager(const ObjectManager& other) = default;
    // Move constructor
    ObjectManager(ObjectManager&& other) = default;
    // Destructor
    ~ObjectManager() { delall(); }

    // Assignment operator

    // Copy assignment operator
    ObjectManager& operator=(const ObjectManager& other) = default;
    // Move assignment operator
    ObjectManager& operator=(ObjectManager&& other) = default;

    // Add object to manager
    pos add(ptr object) { 
		objects_.push_back(object); 
		return std::prev(objects_.end());
	}

    // Remove object from manager by position
    void remove(pos position) { objects_.erase(position); }
    // Remove all objects from manager
    void clear() { objects_.clear(); }

    // Delete object from manager by position
    void del(pos position) {
        delete *position;
        objects_.erase(position);
    }
    // Delete all objects from manager
    void delall() {
        for (auto& el : objects_) delete el;
        objects_.clear();
    }

    // Get object number of manager
    size_t size() const { return objects_.size(); }
    // Is the manager empty
    bool empty() const { return objects_.empty(); }

    // Begin of manager
    pos begin() { return objects_.begin(); }
    // End of manager
    pos end() { return objects_.end(); }

    // Const begin of manager
    cpos begin() const { return objects_.begin(); }
    // Const end of manager
    cpos end() const { return objects_.end(); }
};

}  // namespace vw

#endif  // _VIEWS_OBJECT_MANAGER_HPP