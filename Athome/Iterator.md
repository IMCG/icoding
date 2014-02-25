Iterator
==============
迭代器分类
--------------------
#Input Iterator
###此迭代器不允许修改所指的对象，即是只读的。支持==、!=、++、*、->等操作。
#Output Iterator
###允许算法在这种迭代器所形成的区间上进行只写操作。支持++、*等操作。
#Forward Iterator
###允许算法在这种迭代器所形成的区间上进行读写操作，但只能单向移动，每次只能移动一步。
###支持Input Iterator和Output Iterator的所有操作。
#Bidirectional Iterator
###允许算法在这种迭代器所形成的区间上进行读写操作，可双向移动，每次只能移动一步。支持Forward ###Iterator的所有操作，并另外支持--操作。
#Random Access Iterator
###包含指针的所有操作，可进行随机访问，随意移动指定的步数。支持前面四种Iterator的所有操作，
###并另外支持it + n、it - n、it += n、 it -= n、it1 - it2和it[n]等操作。

		Input Iterator    			Output Iterator
				   \				/
					Forward Iterator
							|
				  Bidirectional Iterator
				  			|
				  Random Access Iterator
###把迭代器分为5类，使用合适的Iter大大提高了效率。
		template<typename InputIterator, typename Distance>  
		void advance_II(InputIterator &i, Distance n)  
		{  
    		//单向逐一前进  
    		while (n--) ++i;  
		}  
  
		template<typename BidirectionalIterator, typename Distance>  
		void advance_BI(BidirectionalIterator &i, Distance n)  
		{  
		    //双向逐一前进  
		    if (n >= 0)  
		      while (n--) ++i;  
		    else  
		      while (n++) --i;  
		}  
		  
		template<typename RandomAccessIterator, typename Distance>  
		void advance_RAI(RandomAccessIterator &i, Distance n)  
		{  
		    //双向跳跃前进  
		    i += n;  
		}  

