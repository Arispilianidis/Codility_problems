#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <map>
#include <array>
#include <algorithm>


using namespace std;

//auto c3 = std::string(1, s[i]) + s[i + 1];

std::string toBinary(int n)
{
	std::string r;
	while (n != 0)
	{
		r = (n % 2 == 0 ? "0" : "1") + r;
		n /= 2;
	}
	return r;
}

class Solution {
public:

	int solution2(vector<int>& A) {
		// write your code in C++14 (g++ 6.2.0)

		vector<int> sortedA;
		copy_if(A.begin(), A.end(), std::back_inserter(sortedA), [](int i) {return i > 0; });
		sort(sortedA.begin(), sortedA.end());

		if (sortedA.size() == 0 || sortedA[0] != 1) {
			return 1;
		}

		for (size_t i = 0; i < sortedA.size() - 1; i++) {
			if (sortedA[i + 1] - sortedA[i] == 0) {
				continue;
			}
			else if (sortedA[i + 1] - sortedA[i] != 1)
				return sortedA[i] + 1;
		}

		return sortedA[sortedA.size() - 1] + 1;
	}

	int solution(int N) {
		string binary = toBinary(N);
		cout << binary << endl;
		size_t found_before;
		size_t found_after;
		size_t difference;
		size_t max_defference = 0;
		/*vector<size_t> indexes_of_ones; */

		found_before = binary.find("1");
		found_after = binary.find("1", found_before + 1);

		while (found_after != std::string::npos) {

			cout << found_after << endl;

			difference = found_after - found_before - 1; //-1 because we are finding the difference of 0-based integers
			if (difference > max_defference) {

				max_defference = difference;

				if (max_defference >= binary.size() / 2) {
					cout << "result size>2: \n";
					return max_defference;
				}
			}

			found_before = found_after;
			found_after = binary.find("1", found_before + 1);
			
		}

		cout << "result: \n";

		return max_defference;

	}

			
};



int main()
{
	Solution v;
	
	/*cout << v.solution(21474647);*/
	vector<int> A{ 1, 3, 6, 4, 1, 2 };
	cout << v.solution2(A);

	cin.get();
	return 0;
}
