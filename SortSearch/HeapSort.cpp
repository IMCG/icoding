//Head Sort & priority_queue
//从1开始，这样才满足完全二叉树的性质
#include <iostream>
using namespace std;
const int maxn = 101;
int R[maxn];
//位置low上的节点调整
void shift(int low, int high){
	int i = low, j = 2 * i;
	int temp = R[i];
	while (j <= high){
		//选取较大的儿子
		if (j < high&&R[j] < R[j + 1])
			j++;
		if (temp < R[j]){
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else break;
	}
	R[i] = temp;
}
void heapsort(int n){
	//预处理成堆
	for (int i = n / 2; i >= 1; --i)
		shift(i, n);
	//交换R[1]和最后节点
	for (int i = n; i >= 2; --i){
		swap(R[i], R[1]);
		shift(1, i - 1);
	}
}
int main(){
	for (int i = 1; i <= 6; ++i)
		cin >> R[i];
	heapsort(6);
	for (int i = 1; i <= 6; ++i)
		cout << R[i];
	return 0;
}

//大项堆
#include <iostream>
using namespace std;
const int maxn = 101;

//堆里面节点个数
int n;
int R[maxn];
//位置low上的节点调整
void shift(int low, int high){
	int i = low, j = 2 * i;
	int temp = R[i];
	while (j <= high){
		//选取较大的儿子
		if (j < high&&R[j] < R[j + 1])
			j++;
		if (temp < R[j]){
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else break;
	}
	R[i] = temp;
}
//insert a new node with value v into heap
void insertNode(int v){
	R[++n] = v;
	for (int k = n; k > 1; k /= 2){
		if (R[k]>R[k / 2])
			swap(R[k], R[k / 2]);
		else break;
	}
}
//delete 
void deleteNode(){
	swap(R[1], R[n--]);
	shift(1, n);
}
void Top(){
	cout << R[1] << "\n";
}
int main(){
	n = 0;
	int node;
	while ((cin >> node),node){
		insertNode(node);
	}
	Top();
	deleteNode();
	Top();
	return 0;
}