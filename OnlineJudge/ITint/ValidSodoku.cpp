//error
bool used[9];
bool check(int t, bool used[9]){
	if (used[t])
		return false;
	used[t] = true;
	return true;
}
int isValidSudoku(int arr[]) {
	for (int i = 0; i < 9; i++){
		fill_n(&used[0], 9, false);//行
		for (int j = 0; j < 9; j++){
			if (!check(arr[i*9 + j],used))
				return false;
		}
		fill_n(&used[0], 9, false);//列
		for (int j = 0; j < 9; j++){
			if (!check(arr[j*9 + i], used))
				return false;
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			fill_n(&used[0], 9, false);
			for (int a = i*3; a < i * 3+3; a++){
				for (int b = j*3; b < j * 3+3; b++){
					if (!check(arr[a*9 + b], used))
						return false;
				}
			}
		}
	}
	return true;
}