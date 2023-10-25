#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> findDuplicates(vector<int>& a) {
    int n = a.size();
  for (int i = 0; i < n; ++i) {
        int index = abs(a[i]);
        if (a[index] > 0) {
            a[index] = -a[index];
        } else {
           a[index] = abs(a[index]);
        }
    }

    vector<int> duplicates;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            duplicates.push_back(i);
        }
    }

   
    sort(duplicates.begin(), duplicates.end());
   return duplicates.empty() ? vector<int>{-1} : duplicates;
}

int main() {
   vector<int> arr = {0, 3, 1, 2};
   vector<int> result = findDuplicates(arr);
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
