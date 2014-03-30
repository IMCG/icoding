/*How many squares are present in an NxN grid? 
In an MxN grid, how many squares are present and how many rectangles?
*/
1. squares in NxN grid


1X1	 ->  (N)^2
2X2	 ->  (N-1)^2
3X3  ->  (N-2)^2
...
NxN  ->  (1)^2
So, total no. of squares=sigma(N^2) over N
					=(N)*(N+1)*(2*N+1)/6
2.squares in MxN grid


let M>N //swap if M<N
let k=M-N
1x1  ->  (N+k)x(N)
2x2  ->  (N-1+k)x(N-1)
3X3  -> (N-2+k)x(N-2) 
...
NxN  ->(1+k)x(1)
So, total no. of squares=sigma((N+k)*(N)) over N
					=sigma(N^2 + k*N)
					=sigma(N^2) +k*sigma(N)
					=(N)(N+1)(2*N+1)/6 + k*N*(N+1)/2
3.rectangles in MxN grid


In an MxN grid you have M+1 horizontal lines
and N+1 vertical lines to enclose a rectangle.
If we choose 2 out of M+1 lines and 2 out of N+1 lines then the intersection of these 
4 lines makes a rectangle.

so,answer is 	  (N+1)C(2) * ((M+1)C(2))   		//nCr
			=(N*(N+1)/(2)) * (M*(M+1)/2)


