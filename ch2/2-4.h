#ifndef prob2_4_h
#define prob2_4_h

#include "../print.h"

using std::vector;

namespace CLRS{
	namespace CH2{
		template <typename T>
		int merge_inverse(vector<T>& A, int p, int q, int r){
			int n1 = q - p + 1;
			int n2 = r - q;
			vector<int> L(n1 + 1), R(n2 + 1);
			for(int i = 0; i < n1; i++) L[i] = A[p + i];
			for(int j = 0; j < n2; j++) R[j] = A[q + j + 1];
			L[n1] = INT_MAX;
			R[n2] = INT_MAX;
			int i = 0; 
			int j = 0;
			int inversions = 0;
			for(int k = p; k <= r; k++){
				if(L[i] <= R[j]){
					A[k] = L[i];
					i++;
				}else{
					inversions = inversions + n1 - i;
					A[k] = R[j];
					j++;
				}
			}
			return inversions;
		}

		template <typename T>
		int count_inversions(vector<T>& A, int p, int r){
			if(p < r){
				int q = (p + r) / 2;
				int left = count_inversions(A, p, q);
				int right = count_inversions(A, q + 1, r);
				return merge_inversions(A, p, q, r) + left + right;
			}

			return 0;
		}
	}
}

#endif
