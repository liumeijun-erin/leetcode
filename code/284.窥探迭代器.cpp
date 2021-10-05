/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 顶端迭代器
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
	int cur;
	bool forward ;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		cur = -1;
		forward = false;
		// Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if(!forward){
			cur = Iterator::next();
			forward = true;
		}
		return cur;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(!forward){
			cur = Iterator::next();
		}
		else{
			forward = false;
		}
		return cur;
	}
	
	bool hasNext() const {
		if(forward||Iterator::hasNext()) return true;
		return false;
	}
	//["PeekingIterator","next","peek","next","next","hasNext"]\n[[[1,2,3]],[],[],[],[],[]]
	//["PeekingIterator","next","peek","peek","next","hasNext"]\n[[[1,2,3]],[],[],[],[],[]]
};
// @lc code=end

