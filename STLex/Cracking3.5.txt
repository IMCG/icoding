#include<iostream>
#include<stack>
using namespace std;

template <typename T>                 //yiban
class MyQueue{
public:
	MyQueue() {}
	~MyQueue () {}
	void push(T val)
	{
		move(sout,sin);
		sin.push(val);
	}
	void pop()
	{
		move(sin,sout);
		sout.pop();
	}
    T front()
	{
		move(sin,sout);
		return sout.top();
	}
	T back()
	{
		move(sout,sin);
		return sin.top();
	}
	void move(stack<T> &src,stack<T> &des)
	{
		while(!src.empty())
		{
			des.push(src.top());
			src.pop();
		}
	}
	int size()
	{
		return sin.size()+sout.size();
	}
	bool empty()
	{
		return sin.empty() && sout.empty();
	}
private:
	stack<int> sin,sout;
};

template <typename T>			      //da an
class MyQueue
{
public:
	stack<T> s1,s2;
	MyQueue() {}
	~MyQueue() {}

	int size()
	{
		return s1.size()+s2.size();
	}
	void push(T value)
	{
		s1.push(value);
	}
	T top()
	{
		if(!s2.empty()) return s2.top();
		while(!s1.empty()) s2.push(s1.pop());//java's take care
		return s2.top();
	}
	T pop()
	{
		if(!s2.empty()) return s2.pop();
		while(!s1.empty()) s2.push(s1.pop());
		return s2.pop();
	}
};				  
+template <typename T>					//move a little
+class MyQueue1{
+public:
+public:
+    MyQueue1(){
+        
+    }
+    ~MyQueue1(){
+        
+    }
+    void push(T val){
+        sin.push(val);
+    }
+    void pop(){
+        move(sin, sout);
+        sout.pop();
+    }
+    T front(){
+        move(sin, sout);
+        return sout.top();
+    }
+    T back(){
+        move(sout, sin);
+        return sin.top();
+    }
+    int size(){
+        return sin.size()+sout.size();
+    }
+    bool empty(){
+        return sin.empty()&&sout.empty();
+    }
+    void move(stack<T> &src, stack<T> &dst){
+        if(dst.empty()){
+            while(!src.empty()){
+                dst.push(src.top());
+                src.pop();
+            }
+        }
+    }
+
+private:
+    stack<T> sin, sout;    
+};


int main()
{
	MyQueue<int> q;
	for(int i=0;i<10;i++)
		q.push(i);

	cout<<q.front()<<" "<<q.back()<<endl;

	q.pop();
	q.push(10);
	cout<<q.front()<<" "<<q.back()<<endl;
	
	cout<<q.empty()<<" "<<q.size()<<endl;
	
	return 0;
}
