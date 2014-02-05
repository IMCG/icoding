/*MinStack.hh
 A LIFO stack class that suports O(1) push,pop,and find-min,
 Only returns (but does not remove) the minimum value;
*/
 #ifndef MinStack_Included
 #define MinStack_Included

 #include<deque>
 #include<functional>	//for std::less
 #include<utility>		//for std::pair

/*class: MinStack<T,Comparator=std::less<T>>
 *Usage: MinStack<T> myStack;
*/
 template<typename T,
 		  typename Comparator=std::less<T>>
 class MinStack{
 public:
 	//Constructs a new stack that uses the specified comparator to
 	//make comparisons.
 	explicit MinStack(Comparator=Comparator());
 	//Pushs a new element atop the stack.
 	void push(const T& val);
 	//Pops the top element of the stack,If the stack is empty. error.
 	void pop();
 	//Returns an immutable view of the top element of the stack.
 	const T&top() const;
 	//Returns an immutable view of the minimum element of the stack.
 	const T&min() const;
 	//Returns whether the stack is empty and its size.
 	bool empty() const;
 	size_t size() const;
 private:
 	/*The actual stack,Each entry is a pair of an element and the index
 	of the minimum element at or below this point.*/
 	std::deque<std::pair<T,size_t>>mStack;
 	/*The comparator used to determine what the smallest element is.*/
 	Comparator mComp;
 };

/*************Implementation Below This Point****************/
 template<typename T,typename Comparator>
 MinStack<T,Comparator>::MinStack(Comparator c)
 		:mStack(),mComp(c){
 			//Handled in initialization list
 	}
 /* Size and empty queries forward directly to the underlying deque. */
template <typename T, typename Comparator>
size_t MinStack<T, Comparator>::size() const {
  return mStack.size();
}
template <typename T, typename Comparator>
bool MinStack<T, Comparator>::empty() const {
  return mStack.empty();
}

/* Returning the top element looks at the back of the deque. */
template <typename T, typename Comparator>
const T& MinStack<T, Comparator>::top() const {
  return mStack.back().first;
}

/* Returning the min element looks at the element in the deque that is the
 * smallest so far.  It's held at the index at the top of the stack. */
template <typename T, typename Comparator>
const T& MinStack<T, Comparator>::min() const {
  return mStack[mStack.back().second].first;
}

/* Inserting a new element adds it to the stack and updates the minimum element
 * if the new element is smaller.
 */
template <typename T, typename Comparator>
void MinStack<T, Comparator>::push(const T& elem) {
  /* If the stack is empty, add the new element and mark that it's the smallest
   * so far.
   */
  if (empty()) {
    mStack.push_back(std::make_pair(elem, 0));
  }
  else {
    /* Otherwise, find the index of the smallest element and insert the new
     * element annotated with that index.
     */
    size_t smallestIndex = mStack.back().second;

    /* If this new element is smaller, the smallest element will now be at the
     * back of the list.
     */
    if (mComp(elem, min()))
      smallestIndex = mStack.size();

    /* Add the element in. */
    mStack.push_back(std::make_pair(elem, smallestIndex));
  }
}