//SRMRoomAssignmentPhase
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int countCompetions(vector<int>ratings, int K){
	int score = ratings[0];
	vector<vector<int>>(K,vector<int>());
	sort(ratings.begin(), ratings.end(), greater<int>());
	//找到index然后比较K
	auto index = find(ratings.begin(), ratings.end(), score);
	int dis = distance(ratings.begin(), index) + 1;
	int ab = K;
	int count = 0;
	while (dis > ab){
		ab += K;
		count++;
	}
	return count;
}
int main()
{
	vector<int>a
	{ 422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500 };
	cout << countCompetions(a, 4);
}