//You can have a comparison object that has a flag indicating which member to sort on.
//不同的比较方式

//@ONE
class Comparo{
    int m_field;
public:
    Comparo(int field)  : m_field(field) { }
    bool operator()(const MyClass & Left, const MyClass & right)
    {
        switch (m_field)
        {
            case 0:
                return left.A < right.A;
            case 1:
                return left.B < right.B;
        }
    }
};
std::vector<MyClass> vec = FillMyVector();
std::sort(vec.begin(), vec.end(), Comparo(0));  // sorts on field A
std::sort(vec.begin(), vec.end(), Comparo(1));  // sorts on field B

//trick  不用sizeof 获取数组长度
int main ()
{
    int arr[100];

    // &arr is a pointer to an array of 100 ints.
	// The [1] means "add the size of the thing that is pointed to", which is an array of 100 ints.
	// So the difference between (&arr)[1] and arr is 100 ints.
	// (Note that this trick will only work in places where sizeof would have worked anyway.)
    printf ("%d", (&arr)[1] - arr);
    return 0;
}