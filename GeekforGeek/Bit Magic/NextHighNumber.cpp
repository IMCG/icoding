//Next higher number with same number of set bits
//http://www.slideshare.net/gkumar007/bits-next-higher-presentation
//寻找最右侧连续1串
unsigned nextHigh(unsigned x){
	unsigned smallest,ripple,ones;
	//x=xxx0 1111 0000
	smallest=x&-x;//0000 0001 0000
	ripple = x+ smallest;//xxx1 0000 0000
	ones = x^ripple	;//0001 1111 0000
	ones = (ones>>2)/smallest;//0000 0000 0111 除去多余2个1，以及右对齐
	return ripple | ones;
}


//Next smallest
unsigned nextSmall(unsigned x){
	//x=11100  --->11010 最右侧1向后移动一位
	unsigned smallest,nextSm;
	smallest=x&-x;//00100
	nextSm=smallest>>1;//00010
	return (x-smallest)|nextSm;
}
