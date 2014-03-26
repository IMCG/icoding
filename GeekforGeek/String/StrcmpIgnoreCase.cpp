//大写小写只有第六位不同
/* implementation of strcmp that ingnores cases */
int ic_strcmp(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] && s2[i]; ++i)
    {
        /* If characters are same or inverting the 6th bit makes them same */
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
           continue;
        else
           break;
    }
 
    /* Compare the last (or first mismatching in case of not same) characters */
    if (s1[i] == s2[i])
        return 0;
    if ((s1[i]|32) < (s2[i]|32)) //Set the 6th bit in both, then compare
        return -1;
    return 1;
}