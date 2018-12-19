#include <iostream> 
using namespace std; 



#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;



int main() 
{ 
	ordered_set o_set; 

	// Finding the SECOND largest element
	cout << *(o_set.find_by_order(1)) << endl; 

	// Finding the number of elements 
	// strictly less than k=4 
	cout << o_set.order_of_key(4) << endl; 

	return 0; 
} 
