// Method 1 (Use Sorting)
1) Sort both strings
2) Compare the sorted strings

// Method 2 (Count characters) 两个count[]
# define NO_OF_CHARS 256
 
/* function to check whether two strings are anagram of each other */
bool areAnagram(char *str1, char *str2)
{
    // Create two count arrays and initialize all values as 0
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};
    int i;
 
    // For each character in input strings, increment count in
    // the corresponding count array
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }
 
    // If both strings are of different length. Removing this condition
    // will make the program fail for strings like "aaca" and "aca"
    if (str1[i] || str2[i])
      return false;
 
    // Compare count arrays
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count1[i] != count2[i])
            return false;
 
    return true;
}
//一个count[]
bool areAnagram(char *str1, char *str2)
{
    // Create two count arrays and initialize all values as 0
    int count[NO_OF_CHARS] = {0};
    int i;
 
    // For each character in input strings, increment count in
    // the corresponding count array
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }
 
    // If both strings are of different length. Removing this condition
    // will make the program fail for strings like "aaca" and "aca"
    //检查长度是否相等
    if (str1[i] || str2[i])
      return false;
 
    // See if there is any non-zero value in count array
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count[i])
            return false;
     return true;
}