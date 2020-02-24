#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "bs_tree.h"
#include "rb_tree.h"
#include "timer.h"
#include "random_generator.h"
#include <fstream>

int main(int argc, char* argv[]) {
	random_generator rg;
	// rb_tree_i_info rb_info;
	// bs_tree_i_info bs_info;
	timer t;
	int n, direction, tree;
	int count;
	std::ofstream myfile;
	myfile.open("time.csv", std::ios::out | std::ios::app);
	int size[4] = { 10000, 50000, 100000, 250000 };
	tree = 0;

	// bs_info.reset();
	// rb_info.reset();

	/*
	 * check arguments
	 */
	if (argc > 1) {
		n = atoi(argv[1]);
		n = (n < 1) ? 1 : n;
	} else {
		cout << argv[0] << " [n] [direction] [tree]" << endl;
		cout << "[n]              size of the random string array" << endl;
		cout << "[direction]            -1: input is sorted descending" << endl;
		cout << "                 1: input is sorted ascending" << endl;
		cout << "                 0: input is random" << endl;
		cout << "[tree]           0: using bs tree" << endl;
		cout << "                 1: using rb tree" << endl;
		cout << endl;
		return 0;
	}

	if (argc > 2)
		direction = atoi(argv[2]);
	else
		direction = 0;

	if (argc > 3)
		tree = atoi(argv[3]);
	else
		tree = 0;

	/*
	 * allocated and generate integer array
	 */
	rb_tree rb;
	bs_tree bs;
	int* input_array;
	int* output_array;
	int bh;

	t.start();
	if (direction == 0)
		input_array = create_random(n);
	else {
		if (direction < 0)
			input_array = create_reverse_sorted(n);
		else
			input_array = create_sorted(n);
	}
	t.stop();

	cout << "Timer (generate): " << t << endl;

	for (int i = 0; (i < n) && (i < 20); i++)
		cout << input_array[i] << endl;
	cout << endl;

	/*
	 * run algorithms
	 */
	if (tree == 0) {
		cout << "Running sort using BS trees: " << endl;
		t.start();
		// for (int i = 0; i < n; i++)
		bs.insert(input_array, n);
		count = bs.getCount();
		output_array = new int[count + 1];
		// n = bs.convert(input_array, n);
		t.stop();
	} else {
		cout << "Running sort using RB trees: " << endl;
		t.start();
		// for (int i = 0; i < n; i++)
		rb.insert(input_array, n);
		count = rb.getCount();
		output_array = new int[count + 1];
		// n = rb.convert(input_array);
		t.stop();
	}

	cout << "Timer (sort): " << t << endl;
	cout << "New size: " << count << endl;
	myfile << t.real() << ";" << t.user() << ";" << t.sys() << ";";
	// if (tree == 1)
	// {
	// 	t.start();
	// 	bh = rb.check_black_height();
	// 	if (bh > 0)
	// 		cout << "Black height: " << bh << endl;
	// 	else
	// 		cout << "Black height check failed!" << endl;
	// 	t.stop();

	// 	cout << "Time (black height test): " << t << endl;
	// }

	/*
	 * check output
	 */
	int height;
	if (tree == 0) {
		// delete[] input_array;

		// output_array = bs.output(count);
		// count = bs.output(output_array);

		// count = bs.output(output_array);
		count = bs.output(output_array);
		// count = bs.getCount();
		// cout<<"\nNOW DUPLICATES"<<n-count;
		// cout<<"\nCount\t"<<count;
		// input_array = new int[count];

		cout << "\nCount of Duplicates: " << bs.duplicates_count() << endl;

	} else {
		// rb.output();
		// delete[] input_array;
		// count = rb.getCount();
		// input_array = new int[count];
		count = rb.output(output_array);

		// count = rb.getCount();
		height = rb.heightTree();
		cout << "\nBlack Height of RB TREE " << height << endl;
		cout << "Duplicates: " << rb.count_Duplicates() << endl;
		cout << "Left Rotate: " << rb.count_Left() << endl;
		cout << "Right Rotate: " << rb.count_Right() << endl;
		cout << "Case 1: " << rb.count_Case1() << endl;
		cout << "Case 2: " << rb.count_Case2() << endl;
		cout << "Case 3: " << rb.count_Case3() << endl;
	}
	myfile << height << ";" << rb.count_Duplicates() << ";" << rb.count_Left()
			<< ";" << rb.count_Right() << ";" << rb.count_Case1();
	myfile << ";" << rb.count_Case2() << ";" << rb.count_Case3() << endl;
	if (check_sorted(output_array, 0, count - 1))
		cout << "The output is sorted!" << endl;
	else
		cout << "ERROR: The output is not sorted!" << endl;

	for (int i = 0; (i < n) && (i < 20); i++)
		cout << output_array[i] << endl;
	cout << endl;

	/*
	 * free allocated storage
	 */
	delete[] input_array;
	delete[] output_array;

	return 0;
}

