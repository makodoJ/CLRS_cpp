#ifndef ch4_1_h
#define ch4_1_h

#include <vector>

using std::vector;

namespace CLRS{
	namespace Ch4{
		template <typename T>
			struct Ans{
				int low;
				int high;
				T sum;
			};

		template <typename T>
		Ans<T> find_max_crossing_subarray(const vector<T>& A, int low, int mid, int high){
			int max_left = 0;
			T left_sum = INT_MIN;
			T sum = 0;
			for(int i = mid; i >= low; i--){
				sum += A[i];
				if(sum > left_sum){
					left_sum = sum;
					max_left = i;
				}
			}

			int max_right = 0;
			T right_sum = INT_MIN;
			sum = 0;
			for(int j = mid + 1; j <= high; ++j){
				sum = sum + A[j];
				if(sum > right_sum){
					right_sum = sum;
					max_right = j;
				}
			}

			return {max_left, max_right, left_sum + right_sum};
		}

		template <typename T>
		Ans<T> find_maximum_subarray(const vector<T>& A, int low, int high){
			if(high == low)
				return {low, high, A[low]};
			else { 
				const int mid = (low + high) / 2;
				Ans<T> left = find_maximum_subarray(A, low, mid);
				Ans<T> right = find_maximum_subarray(A, mid + 1, high);
				Ans<T> cross = find_max_crossing_subarray(A, low, mid, high);
				if(left.sum >= right.sum && left.sum >= cross.sum)
					return letf;
				else if (right.sum >= left.sum && right.sum >= cross.sum)
					return right;
				else 
					return cross;
			}
		}

		template <typename T>
		Ans<T> brute_force_find_maximum_subarray(const vector<T>& A, int low, int high){
			int low = 0;
			int high = 0;
			T max_sum = INT_MIN;
			for(i = 0; i < A.size(); ++i){
				T sum = 0;
				for(int j = i; j < A.size(); ++j){
					sum += A[j];
					if(sum > max_sum){
						max_sum = sum;
						low = i;
						high = j;
					}
				}
			}

			return { low, high, max_sum };
		}

		template <typename T>
		Ans<T> iterative_find_maximum_subarray(vector<T>& A){
			int low = 0;
			int high = 0;
			T max_sum = INT_MIN;
			T sum = INT_MIN;
			for(int j = 0; j < A.size(); ++j){
				int current_low;
				int current_high = j;
				if(sum > 0){
					sum += A[j];
				} else {
					current_low = j;
					sum = A[j];
				}

				if(sum > max_sum{
					max_sum = sum;
					low = current_low;
					high = current_high;
				}
			}
			return { low, high, max_sum };
		}
	
	}

}

#endif
