

#define BOOST_DYN_LINK
#define BOOST_TEST_MODULE  SEGMENT_TREE
#include <iostream>
#include "SegmentTree.h"

#include <boost/test/included/unit_test.hpp>

int add_(int a, int b) // addition at merging of nodes
{
    return (a+b);
}


int max_(int a, int b) // taking maximum at merging of nodes
{
	if(a >= b)return a;
    else return b;
}


int min_(int a, int b) // taking minimum at merging of nodes
{
    if(a <= b)return a;
    else return b;
}

// summation segment_tree
BOOST_AUTO_TEST_CASE (segment_tree_queries) {
	
	int arr[6] = {1, 2, -1, 0, 4, 1};
	int num = 6;
	SegmentTree<int> segTree(arr, add_, 0, num-1);
	BOOST_CHECK(segTree.query(0,1) == 3); 

	BOOST_CHECK(segTree.query(0,0) == 1); 

	BOOST_CHECK(segTree.query(5,5) == 1); 

	BOOST_CHECK(segTree.query(0,5) == 7); 

	BOOST_CHECK(segTree.query(2,3) == -1); 
	
}

BOOST_AUTO_TEST_CASE (segment_tree_updates) {
	
	int arr[6] = {1, 2, -1, 0, 4, 1};
	int num = 6;
	SegmentTree<int> segTree2(arr, add_, 0, num-1);

	segTree2.update(0,9);
	arr[0] = 9;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(3,-4);
	arr[3] = -4;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(2,10);
	arr[2] = 10;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}


	segTree2.update(0,-2);
	arr[0] = -2;
	
	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	//BOOST_CHECK(segTree.query(2,3) == -1); 
	
}


// maximum segment_tree
BOOST_AUTO_TEST_CASE (max_segment_tree_queries) {
	
	int arr[6] = {1, 2, -1, 0, 4, 1};
	int num = 6;
	SegmentTree<int> segTree(arr, max_, 0, num-1);
	BOOST_CHECK(segTree.query(0,1) == 2); 

	BOOST_CHECK(segTree.query(0,0) == 1); 

	BOOST_CHECK(segTree.query(5,5) == 1); 

	BOOST_CHECK(segTree.query(0,5) == 4); 

	BOOST_CHECK(segTree.query(2,3) == 0); 
	
}

BOOST_AUTO_TEST_CASE (max_segment_tree_updates) {
	
	int arr[6] = {1, 2, -1, 0, 4, 1};
	int num = 6;
	SegmentTree<int> segTree2(arr, max_, 0, num-1);

	segTree2.update(0,9);
	arr[0] = 9;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(3,-4);
	arr[3] = -4;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(2,10);
	arr[2] = 10;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}


	segTree2.update(0,-2);
	arr[0] = -2;
	
	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	//BOOST_CHECK(segTree.query(2,3) == -1); 
	
}


// minimum segment_tree
BOOST_AUTO_TEST_CASE (min_segment_tree_queries) {
	
	int arr[6] = {1, 2, -1, 0, 4, 1};
	int num = 6;
	SegmentTree<int> segTree(arr, min_, 0, num-1);
	BOOST_CHECK(segTree.query(0,1) == 1); 

	BOOST_CHECK(segTree.query(0,0) == 1); 

	BOOST_CHECK(segTree.query(5,5) == 1); 

	BOOST_CHECK(segTree.query(0,5) == -1); 

	BOOST_CHECK(segTree.query(2,3) == -1); 
	
}

BOOST_AUTO_TEST_CASE (min_segment_tree_updates) {
	
	int arr[6] = {1, 2, -1, 0, 4, 1};
	int num = 6;
	SegmentTree<int> segTree2(arr, min_, 0, num-1);

	segTree2.update(0,9);
	arr[0] = 9;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(3,-4);
	arr[3] = -4;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(2,10);
	arr[2] = 10;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}


	segTree2.update(0,-2);
	arr[0] = -2;
	
	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	//BOOST_CHECK(segTree.query(2,3) == -1); 
	
}

//--------------------------------------------------
// Double


double add_d(double a, double b) // addition at merging of nodes
{
    return (a+b);
}


double max_d(double a, double b) // taking maximum at merging of nodes
{
	if(a >= b)return a;
    else return b;
}


double min_d(double a, double b) // taking minimum at merging of nodes
{
    if(a <= b)return a;
    else return b;
}

// summation segment_tree
BOOST_AUTO_TEST_CASE (sumd_segment_tree_queries) {
	
	double arr[6] = {1.5, 2.9, -1.1, 0.6, 4.1, 1};
	int num = 6;
	SegmentTree<double> segTree(arr, add_d, 0, num-1);
	BOOST_CHECK(segTree.query(0,1) -4.4<=0.0000001); 

	BOOST_CHECK(segTree.query(0,0)-1.5<=0.0000001); 

	BOOST_CHECK(segTree.query(5,5)-1<=0.0000001); 

	BOOST_CHECK(segTree.query(0,5) -9<=0.0000001); 

	BOOST_CHECK(segTree.query(2,3)+0.5 <= 0.0000001); 
	
}

BOOST_AUTO_TEST_CASE (sumd_segment_tree_updates) {
	
	double arr[6] = {1.5, 2.9, -1.1, 0.6, 4.1, 1};
	int num = 6;
	SegmentTree<double> segTree2(arr, add_d, 0, num-1);

	segTree2.update(0,9.1);
	arr[0] = 9.1;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(3,-4);
	arr[3] = -4;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(2,10.6);
	arr[2] = 10.6;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}


	segTree2.update(0,-25.33);
	arr[0] = -25.33;
	
	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	//BOOST_CHECK(segTree.query(2,3) == -1); 
	
}


// maximum segment_tree
BOOST_AUTO_TEST_CASE (maxd_segment_tree_queries) {
	
	double arr[6] = {1.5, 2.9, -1.1, 0.6, 4.1, 1};
	int num = 6;
	SegmentTree<double> segTree(arr, max_d, 0, num-1);
	BOOST_CHECK(segTree.query(0,1)-2.9<=0.0000001); 

	BOOST_CHECK(segTree.query(0,0)-1.5<=0.0000001); 

	BOOST_CHECK(segTree.query(5,5)-1<=0.0000001); 

	BOOST_CHECK(segTree.query(0,5) -4.1<=0.0000001); 

	BOOST_CHECK(segTree.query(2,3)-0.6<=0.0000001); 
	
}

BOOST_AUTO_TEST_CASE (maxd_segment_tree_updates) {
	
	double arr[6] = {1.5, 2.9, -1.1, 0.6, 4.1, 1};
	int num = 6;
	SegmentTree<double> segTree2(arr, max_d, 0, num-1);

	segTree2.update(0,9.1);
	arr[0] = 9.1;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(3,-4);
	arr[3] = -4;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(2,10.6);
	arr[2] = 10.6;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}


	segTree2.update(0,-25.33);
	arr[0] = -25.33;
	
	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	//BOOST_CHECK(segTree.query(2,3) == -1); 
	
}


// minimum segment_tree
BOOST_AUTO_TEST_CASE (mind_segment_tree_queries) {
	
	double arr[6] = {1.5, 2.9, -1.1, 0.6, 4.1, 1};
	int num = 6;
	SegmentTree<double> segTree(arr, min_d, 0, num-1);
	BOOST_CHECK(segTree.query(0,1)-1.5<=0.0000001); 

	BOOST_CHECK(segTree.query(0,0)-1.5<=0.0000001); 

	BOOST_CHECK(segTree.query(5,5)-1<=0.0000001); 

	BOOST_CHECK(segTree.query(0,5)+1.1<=0.0000001); 

	BOOST_CHECK(segTree.query(2,3)+1.1<=0.0000001); 
	
}

BOOST_AUTO_TEST_CASE (mind_segment_tree_updates) {
	
	double arr[6] = {1.5, 2.9, -1.1, 0.6, 4.1, 1};
	int num = 6;
	SegmentTree<double> segTree2(arr, min_d, 0, num-1);

	segTree2.update(0,9.1);
	arr[0] = 9.1;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(3,-4);
	arr[3] = -4;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	segTree2.update(2,10.6);
	arr[2] = 10.6;

	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}


	segTree2.update(0,-25.33);
	arr[0] = -25.33;
	
	for(size_t i = 0 ; i < 6; i++){
		BOOST_CHECK(segTree2.query(i,i) == arr[i]);
	}

	//BOOST_CHECK(segTree.query(2,3) == -1); 
	
}

